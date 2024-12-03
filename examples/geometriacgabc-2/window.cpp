#include "window.hpp"
#include <vector> 

#include <glm/gtx/fast_trigonometry.hpp>
#include <unordered_map>
#include <string>

void Window::onEvent(SDL_Event const &event) {
  glm::ivec2 mousePosition;
  SDL_GetMouseState(&mousePosition.x, &mousePosition.y);

  if (event.type == SDL_MOUSEMOTION) {
    m_trackBall.mouseMove(mousePosition);
  }
  if (event.type == SDL_MOUSEBUTTONDOWN &&
      event.button.button == SDL_BUTTON_LEFT) {
    m_trackBall.mousePress(mousePosition);
  }
  if (event.type == SDL_MOUSEBUTTONUP &&
      event.button.button == SDL_BUTTON_LEFT) {
    m_trackBall.mouseRelease(mousePosition);
  }
  if (event.type == SDL_MOUSEWHEEL) {
    m_zoom += (event.wheel.y > 0 ? -1.0f : 1.0f) / 5.0f;
    m_zoom = glm::clamp(m_zoom, -1.0f, 1.0f);
  }
}

void Window::onCreate() {
  auto const &assetsPath{abcg::Application::getAssetsPath()};

  abcg::glClearColor(0, 0, 0, 1);

  // Enable depth buffering
  abcg::glEnable(GL_DEPTH_TEST);

  // Create program
  m_program =
      abcg::createOpenGLProgram({{.source = assetsPath + "geometriacgabc-2.vert",
                                  .stage = abcg::ShaderStage::Vertex},
                                 {.source = assetsPath + "geometriacgabc-2.frag",
                                  .stage = abcg::ShaderStage::Fragment}});

  m_colorLocation = abcg::glGetUniformLocation(m_program, "color");

  // Load model
  m_model.loadObj(assetsPath + "tetraedo.obj");
  m_model.setupVAO(m_program);

  m_trianglesToDraw = m_model.getNumTriangles();

  m_randomEngine.seed(
      std::chrono::steady_clock::now().time_since_epoch().count());
}

void Window::onUpdate() {
  m_modelMatrix = m_trackBall.getRotation();

  m_viewMatrix =
      glm::lookAt(glm::vec3(0.0f, 0.0f, 2.0f + m_zoom),
                  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
}

void Window::onPaint() {
  abcg::glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  abcg::glViewport(0, 0, m_viewportSize.x, m_viewportSize.y);

  abcg::glUseProgram(m_program);

  // Get location of uniform variables
  auto const viewMatrixLoc{abcg::glGetUniformLocation(m_program, "viewMatrix")};
  auto const projMatrixLoc{abcg::glGetUniformLocation(m_program, "projMatrix")};
  auto const modelMatrixLoc{
      abcg::glGetUniformLocation(m_program, "modelMatrix")};
  auto const colorLoc{abcg::glGetUniformLocation(m_program, "color")};

  // Set uniform variables that have the same value for every model
  abcg::glUniformMatrix4fv(viewMatrixLoc, 1, GL_FALSE, &m_viewMatrix[0][0]);
  abcg::glUniformMatrix4fv(projMatrixLoc, 1, GL_FALSE, &m_projMatrix[0][0]);

  // Set uniform variables for the current model
  abcg::glUniformMatrix4fv(modelMatrixLoc, 1, GL_FALSE, &m_modelMatrix[0][0]);
  abcg::glUniform4f(colorLoc, m_color.at(0), m_color.at(1), m_color.at(2), 1.0f); // White

  m_model.render(m_trianglesToDraw);

  abcg::glUseProgram(0);
}


void Window::onPaintUI() {
  abcg::OpenGLWindow::onPaintUI();

  // Create a window for the other widgets
  {
    auto const widgetSize{ImVec2(300, 62)};
    ImGui::SetNextWindowPos(ImVec2(m_viewportSize.x - widgetSize.x - 5, 5));
    ImGui::SetNextWindowSize(widgetSize);
    ImGui::Begin("Widget window", nullptr, ImGuiWindowFlags_NoDecoration);

    abcg::glEnable(GL_CULL_FACE);

    // CW/CCW combo box
    {
      static std::size_t currentIndex{};
      std::vector<std::string> const comboItems{"Tetraedo", "Piramide", "Cubo", "Paralelepipedo", "Prisma-hexagonal", "Cone", "Cilindro", "Esfera", "Elipsoide", "Toroide"};

      ImGui::PushItemWidth(225);
      if (ImGui::BeginCombo("Formas",
                            comboItems.at(currentIndex).c_str())) {
        for (auto const index : iter::range(comboItems.size())) {
          auto const isSelected{currentIndex == index};
          if (ImGui::Selectable(comboItems.at(index).c_str(), isSelected))
            currentIndex = index;
          if (isSelected)
            ImGui::SetItemDefaultFocus();
        }
        ImGui::EndCombo();
      }
      ImGui::PopItemWidth();

      ImGui::ColorEdit3("Colorir", m_color.data());
      
      if (currentIndex == 0) {
        carregaObj("tetraedo");
      } else if (currentIndex == 1){
        carregaObj("piramide");
      } else if (currentIndex == 2){
        carregaObj("cubo");
      } else if (currentIndex == 3){
        carregaObj("paralelepipedo");
      } else if (currentIndex == 4){
        carregaObj("prisma");
      } else if (currentIndex == 5){
        carregaObj("cone");
      } else if (currentIndex == 6){
        carregaObj("cilindro");
      } else if (currentIndex == 7){
        carregaObj("esfera");
      } else if (currentIndex == 8){
        carregaObj("elipsoide");
      } else if (currentIndex == 9){
        carregaObj("toroide");
      }
    }
    auto const aspect{gsl::narrow<float>(m_viewportSize.x) /
                          gsl::narrow<float>(m_viewportSize.y)};
        m_projMatrix =
            glm::perspective(glm::radians(45.0f), aspect, 0.1f, 5.0f);

    ImGui::End();
  }

  {
    ImGui::SetNextWindowPos(ImVec2(180, m_viewportSize.y - 70));
    ImGui::SetNextWindowSize(ImVec2(m_viewportSize.x -20, 70));
    ImGui::Begin("Text window", nullptr, ImGuiWindowFlags_NoDecoration);

    {
      ImGui::PushItemWidth(m_viewportSize.x - 20);

      ImGui::Text("Vertices: %d\nArestas: %d\nFaces: %d", m_obj[0], m_obj[1], m_obj[2]);

      ImGui::PopItemWidth();
    }

    ImGui::End();
  }
}

void Window::onResize(glm::ivec2 const &size) {
  m_viewportSize = size;
  m_trackBall.resizeViewport(size);
}

void Window::onDestroy() {
  m_model.destroy();
  abcg::glDeleteProgram(m_program);
}

void Window::carregaObj(std::string obj){
  m_model.destroy();
  abcg::glDeleteProgram(m_program);

  auto const &assetsPath{abcg::Application::getAssetsPath()};

  abcg::glEnable(GL_DEPTH_TEST);

  // Create program
  m_program =
      abcg::createOpenGLProgram({{.source = assetsPath + "geometriacgabc-2.vert",
                                  .stage = abcg::ShaderStage::Vertex},
                                 {.source = assetsPath + "geometriacgabc-2.frag",
                                  .stage = abcg::ShaderStage::Fragment}});

  if(obj == "tetraedo"){
    m_model.loadObj(assetsPath + "tetraedo.obj");
    m_obj = {4, 6, 4};
  } else if (obj == "piramide"){
    m_model.loadObj(assetsPath + "basic_pyramid.obj");
    m_obj = {5, 8, 5};
  } else if (obj == "cubo"){
    m_model.loadObj(assetsPath + "quadrado.obj");
  } else if (obj == "paralelepipedo"){
    m_model.loadObj(assetsPath + "paralelepipedo.obj");
  } else if (obj == "prisma"){
    m_model.loadObj(assetsPath + "prisma.obj");
  } else if (obj == "cone"){
    m_model.loadObj(assetsPath + "cone.obj");
  } else if (obj == "cilindro"){
    m_model.loadObj(assetsPath + "cilindro.obj");
  } else if (obj == "esfera"){
    m_model.loadObj(assetsPath + "esfera.obj");
    m_obj = {0, 0, 0};
  } else if (obj == "elipsoide"){
    m_model.loadObj(assetsPath + "elipsoide.obj");
  } else if (obj == "toroide"){
    m_model.loadObj(assetsPath + "toroide.obj");
  }

  m_model.setupVAO(m_program);

  m_trianglesToDraw = m_model.getNumTriangles(); // Desnecessário talvez
}