#include "window.hpp"
#include <abcgOpenGLWindow.hpp>
#include <glm/gtx/fast_trigonometry.hpp>
#include <glm/gtx/rotate_vector.hpp>

bool gerado = true;
bool linear = true;
auto sides = 3;

void Window::onCreate() {
  m_rotation = 0.0f;
  m_previousMousePosition = glm::ivec2(0, 0);

  auto const *vertexShader{R"gl(#version 300 es

    layout(location = 0) in vec2 inPosition;
    layout(location = 1) in vec4 inColor;

    uniform vec2 translation;
    uniform float scale;
    uniform float rotation;

    out vec4 fragColor;

    void main() {
      // Apply rotation
      float cosAngle = cos(rotation);
      float sinAngle = sin(rotation);
      vec2 rotatedPosition = vec2(
        inPosition.x * cosAngle - inPosition.y * sinAngle,
        inPosition.x * sinAngle + inPosition.y * cosAngle
      );
      
      vec2 newPosition = rotatedPosition * scale + translation;
      gl_Position = vec4(newPosition, 0, 1);
      fragColor = inColor;
    }
  )gl"};

  auto const *fragmentShader{R"gl(#version 300 es

    precision mediump float;  

    in vec4 fragColor;

    out vec4 outColor;

    void main() { outColor = fragColor; }
  )gl"};

  m_program = abcg::createOpenGLProgram(
      {{.source = vertexShader, .stage = abcg::ShaderStage::Vertex},
       {.source = fragmentShader, .stage = abcg::ShaderStage::Fragment}});

  abcg::glClearColor(0, 0, 0, 1);
  abcg::glClear(GL_COLOR_BUFFER_BIT);

  m_randomEngine.seed(
      std::chrono::steady_clock::now().time_since_epoch().count());
  poligonos(3);
}

void Window::onEvent(SDL_Event const &event) {
  if (event.type == SDL_MOUSEMOTION) {
    glm::ivec2 mousePosition;
    SDL_GetMouseState(&mousePosition.x, &mousePosition.y);

    // Calcula o ângulo de rotação com base na posição do mouse em relação ao centro da janela
    glm::vec2 direction{mousePosition.x - m_viewportSize.x / 2,
                        -(mousePosition.y - m_viewportSize.y / 2)};

    m_rotation = std::atan2(direction.y, direction.x);
  }
}

void Window::onPaint() {
  auto const m_sides = sides;
  if (gerado && linear) {
    // Renderiza o polígono uma vez ao clicar no botão
    auto const m_sides = sides;
    poligonos(m_sides);
    gerado = false;
  }

  // Atualizar o ângulo de rotação em tempo real
  updateRotation();

  // Definir a viewport e usar o programa do shader
  abcg::glViewport(0, 0, m_viewportSize.x, m_viewportSize.y);
  abcg::glUseProgram(m_program);

  // Configurar a posição e escala uma vez
  glm::vec2 const translation{0.0f, -0.3f};
  auto const translationLocation{
      abcg::glGetUniformLocation(m_program, "translation")};
  abcg::glUniform2fv(translationLocation, 1, &translation.x);

  auto const scale{0.4f};
  auto const scaleLocation{abcg::glGetUniformLocation(m_program, "scale")};
  abcg::glUniform1f(scaleLocation, scale);

  // Atualizar o valor de rotação em tempo real
  auto const rotationLocation{abcg::glGetUniformLocation(m_program, "rotation")};
  abcg::glUniform1f(rotationLocation, m_rotation);


  // Renderizar o polígono com a rotação atualizada
  abcg::glBindVertexArray(m_VAO);

  if(linear == true){
    abcg::glDrawArrays(GL_TRIANGLE_FAN, 0, m_sides + 2);
  }

  abcg::glBindVertexArray(0);

  abcg::glUseProgram(0);
}

void Window::updateRotation() {
  // Função chamada em cada quadro para atualizar a rotação
  glm::ivec2 mousePosition;
  SDL_GetMouseState(&mousePosition.x, &mousePosition.y);

  glm::vec2 direction{mousePosition.x - m_viewportSize.x / 2,
                      -(mousePosition.y - m_viewportSize.y / 2)};

  m_rotation = std::atan2(direction.y, direction.x);
  abcg::glClear(GL_COLOR_BUFFER_BIT);
}

void Window::onPaintUI() {
  abcg::OpenGLWindow::onPaintUI();
  
  int button_click = 99;

  // Get size of application's window
  auto const appWindowWidth{gsl::narrow<float>(getWindowSettings().width)};
  auto const appWindowHeight{gsl::narrow<float>(getWindowSettings().height)};

  // Janela dos botões
  {
    // Comprimeto da tela / 3 de forma que os botões ocupem apenas 1/3 da tela
    ImGui::SetNextWindowSize(ImVec2(appWindowWidth, appWindowHeight/3));
    ImGui::SetNextWindowPos(ImVec2(0, 0));

    auto const flags{ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoResize |
                     ImGuiWindowFlags_NoCollapse};
    ImGui::Begin("Geometria ABC", nullptr, flags);

    // TODO: Add botões e texto nos botões -- FEITO
    {
        auto const gridHeight{(appWindowHeight/3) - 22 - 20 - (m_l * 10) - 20};
        auto const buttonHeight{gridHeight / m_l};

        // Texto formas geometricas nos botões
        std::array<std::string, m_l*m_c> const fg = {
            "Triangulo", 
            "Quadrado", 
            "Pentagono", 
            "Hexagono", 
            "Circulo", 
            " "}; // TODO: Criar uma forma geometrica não linear (estrela, meia lua, etc)

        // Use custom font
        if (ImGui::BeginTable("buttons", m_c)) {
            for (auto i : iter::range(m_l)) {
            ImGui::TableNextRow();
            for (auto j : iter::range(m_c)) {
                ImGui::TableSetColumnIndex(j);
                auto const offset = i * m_c + j;

                auto const& fg_value = fg[offset];

                // Button text is fg followed by an ID in the format ##ij
                auto buttonText{fmt::format("{}##{}{}", fg_value, i, j)}; // --
                if (ImGui::Button(buttonText.c_str(), ImVec2(-1, buttonHeight))) {
                    m_button.at(offset) = fg_value;
                    button_click = offset;
                }
            }
            ImGui::Spacing();
        }
        ImGui::EndTable();
      }
    }

    ImGui::Spacing();
  }

    // TODO: Add exibir qual botão está selecionado - FEITO
    //Se clicar um botão, chamar funcao que cria a figura geometrica correspondente
    if (button_click == 0){ // TRINAGULO
      abcg::glClear(GL_COLOR_BUFFER_BIT);
      sides = 3;
      gerado = true;
      linear = true;
    }
    if (button_click == 1){ // QUADRADO
      abcg::glClear(GL_COLOR_BUFFER_BIT);
      sides = 4;
      gerado = true;
      linear = true;
    }
    if (button_click == 2){ // PENTAGONO
      abcg::glClear(GL_COLOR_BUFFER_BIT);
      sides = 5;
      gerado = true;
      linear = true;
    }
    if (button_click == 3){ // HEXAGONO
      abcg::glClear(GL_COLOR_BUFFER_BIT);
      sides = 6;
      gerado = true;
      linear = true;
    }
    if (button_click == 4){ // CIRCULO
      abcg::glClear(GL_COLOR_BUFFER_BIT);
      sides = 30;
      gerado = true;
      linear = true;
    }
    if (button_click == 5){ // CIRCULO
      abcg::glClear(GL_COLOR_BUFFER_BIT);
      gerado = true;
      linear = false;
    }

    ImGui::End();
}

void Window::onResize(glm::ivec2 const &size) {
  m_viewportSize = size;

  abcg::glClear(GL_COLOR_BUFFER_BIT);
}

void Window::onDestroy() {
  abcg::glDeleteProgram(m_program);
  abcg::glDeleteBuffers(1, &m_VBOPositions);
  abcg::glDeleteBuffers(1, &m_VBOColors);
  abcg::glDeleteVertexArrays(1, &m_VAO);
}

// Figuras geometricas
void Window::poligonos(int sides){
  fmt::print(stdout, "Vertices {}\n", sides);
  // TODO: Desenvolver com base na funcao setupModel() da sessao 5.1 -- FEITO
  // Release previous resources, if any
  abcg::glDeleteBuffers(1, &m_VBOPositions);
  abcg::glDeleteBuffers(1, &m_VBOColors);
  abcg::glDeleteVertexArrays(1, &m_VAO);

  // Select random colors for the radial gradient
  std::uniform_real_distribution rd(0.0f, 1.0f);
  glm::vec3 const color1{rd(m_randomEngine), rd(m_randomEngine),
                         rd(m_randomEngine)};
  glm::vec3 const color2{rd(m_randomEngine), rd(m_randomEngine),
                         rd(m_randomEngine)};

  // Minimum number of sides is 3
  sides = std::max(3, sides);

  std::vector<glm::vec2> positions;
  std::vector<glm::vec3> colors;

  // Polygon center
  positions.emplace_back(0, 0);
  colors.push_back(color1);

  // Border vertices
  auto const step{M_PI * 2 / sides};
  for (auto const angle : iter::range(0.0, M_PI * 2, step)) {
    positions.emplace_back(std::cos(angle), std::sin(angle));
    colors.push_back(color2);
  }

  // Duplicate second vertex
  positions.push_back(positions.at(1));
  colors.push_back(color2);

  // Generate VBO of positions
  abcg::glGenBuffers(1, &m_VBOPositions);
  abcg::glBindBuffer(GL_ARRAY_BUFFER, m_VBOPositions);
  abcg::glBufferData(GL_ARRAY_BUFFER, positions.size() * sizeof(glm::vec2),
                     positions.data(), GL_STATIC_DRAW);
  abcg::glBindBuffer(GL_ARRAY_BUFFER, 0);

  // Generate VBO of colors
  abcg::glGenBuffers(1, &m_VBOColors);
  abcg::glBindBuffer(GL_ARRAY_BUFFER, m_VBOColors);
  abcg::glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(glm::vec3),
                     colors.data(), GL_STATIC_DRAW);
  abcg::glBindBuffer(GL_ARRAY_BUFFER, 0);

  // Get location of attributes in the program
  auto const positionAttribute{
      abcg::glGetAttribLocation(m_program, "inPosition")};
  auto const colorAttribute{abcg::glGetAttribLocation(m_program, "inColor")};

  if (positionAttribute == -1 || colorAttribute == -1) {
    fmt::print(stderr, "Erro ao encontrar atributos no shader.\n");
    return;
  }

  // Create VAO
  abcg::glGenVertexArrays(1, &m_VAO);

  // Bind vertex attributes to current VAO
  abcg::glBindVertexArray(m_VAO);

  abcg::glEnableVertexAttribArray(positionAttribute);
  abcg::glBindBuffer(GL_ARRAY_BUFFER, m_VBOPositions);
  abcg::glVertexAttribPointer(positionAttribute, 2, GL_FLOAT, GL_FALSE, 0,
                              nullptr);
  abcg::glBindBuffer(GL_ARRAY_BUFFER, 0);

  abcg::glEnableVertexAttribArray(colorAttribute);
  abcg::glBindBuffer(GL_ARRAY_BUFFER, m_VBOColors);
  abcg::glVertexAttribPointer(colorAttribute, 3, GL_FLOAT, GL_FALSE, 0,
                              nullptr);
  abcg::glBindBuffer(GL_ARRAY_BUFFER, 0);

  if (m_VAO == 0 || m_VBOPositions == 0 || m_VBOColors == 0) {
    fmt::print(stderr, "Erro ao criar buffers ou VAO.\n");
    return;
  }

  // End of binding to current VAO
  abcg::glBindVertexArray(0);
}

// Forma geometrica não linear
void Window::forma(){
  fmt::print(stdout, "Forma especial\n");
  abcg::glDeleteBuffers(1, &m_VBOPositions);
  abcg::glDeleteBuffers(1, &m_VBOColors);
  abcg::glDeleteVertexArrays(1, &m_VAO);

  // Select random colors for the radial gradient
  std::uniform_real_distribution rd(0.0f, 1.0f);
  glm::vec3 const color1{rd(m_randomEngine), rd(m_randomEngine),
                         rd(m_randomEngine)};
  glm::vec3 const color2{rd(m_randomEngine), rd(m_randomEngine),
                         rd(m_randomEngine)};

  std::array positions{
    glm::vec2{-02.5f, +12.5f}, glm::vec2{-15.5f, +02.5f},
    glm::vec2{-15.5f, -12.5f}, glm::vec2{-09.5f, -07.5f},
    glm::vec2{-03.5f, -12.5f}, glm::vec2{+03.5f, -12.5f},
    glm::vec2{+09.5f, -07.5f}, glm::vec2{+15.5f, -12.5f},
    glm::vec2{+15.5f, +02.5f}, glm::vec2{+02.5f, +12.5f}
  };

  // Normalize
  for (auto &position : positions) {
    position /= glm::vec2{15.5f, 15.5f};
  }

  std::array const indices{0, 1, 3,
                           1, 2, 3,
                           0, 3, 4,
                           0, 4, 5,
                           9, 0, 5,
                           9, 5, 6,
                           9, 6, 8,
                           8, 6, 7};

  std::vector<glm::vec3> colors;
  colors.push_back(color1);

  // Generate VBO
  abcg::glGenBuffers(1, &m_VBO);
  abcg::glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
  abcg::glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions.data(),
                     GL_STATIC_DRAW);
  abcg::glBindBuffer(GL_ARRAY_BUFFER, 0);

  // Generate EBO
  abcg::glGenBuffers(1, &m_EBO);
  abcg::glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
  abcg::glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices.data(),
                     GL_STATIC_DRAW);
  abcg::glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

  // Generate VBO of colors
  abcg::glGenBuffers(1, &m_VBOColors);
  abcg::glBindBuffer(GL_ARRAY_BUFFER, m_VBOColors);
  abcg::glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(glm::vec3),
                     colors.data(), GL_STATIC_DRAW);
  abcg::glBindBuffer(GL_ARRAY_BUFFER, 0);

  // Get location of attributes in the program
  GLint positionAttribute{abcg::glGetAttribLocation(m_program, "inPosition")};

  // Create VAO
  abcg::glGenVertexArrays(1, &m_VAO);

  // Bind vertex attributes to current VAO
  abcg::glBindVertexArray(m_VAO);

  abcg::glEnableVertexAttribArray(positionAttribute);
  abcg::glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
  abcg::glVertexAttribPointer(positionAttribute, 2, GL_FLOAT, GL_FALSE, 0,
                              nullptr);
  abcg::glBindBuffer(GL_ARRAY_BUFFER, 0);

  abcg::glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);

  // End of binding to current VAO
  abcg::glBindVertexArray(0);
}