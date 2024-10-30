#include "window.hpp"

void Window::onCreate() {
  // TODO: Ao iniciar a aplicacao, pré-selecionar a primeira forma geometrica (primeiro botão)
}

void Window::onPaintUI() {

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
            "palavra1", 
            "palavra2", 
            "palavra3", 
            "palavra4", 
            "palavra5", 
            "palavra6"};

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

  // TODO: Add janela que mostrará as formas geometricas -- 40% Feito
  {
    ImGui::SetNextWindowSize(ImVec2(appWindowWidth, appWindowHeight*(2/3)));
    ImGui::SetNextWindowPos(ImVec2(0, (appWindowHeight/3)));

    auto const flags{ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoResize |
                     ImGuiWindowFlags_NoCollapse};
    ImGui::Begin("Objetos", nullptr, flags);

    // TODO: Add exibir qual botão está selecionado - 80% feito
    //Se clicar um botão, chamar funcao que cria a figura geometrica correspondente
    if (button_click == 0){
      //variavel "sides" definindo os lados da figura geometrica
      //poligono(sides)
    }
    if (button_click == 1){
      //variavel "sides" definindo os lados da figura geometrica
      //poligono(sides)
    }
    if (button_click == 3){
      //variavel "sides" definindo os lados da figura geometrica
      //poligono(sides)
    }
    //...

    ImGui::Spacing();
    ImGui::End();
  }
    ImGui::End();
}

// Figuras geometricas
// TODO: Add formas geometricas
void Window::poligono(int sides){
  fmt::print(stdout, "Ola mundo {}\n", sides);
  // TODO: Desenvolver com base na funcao setupModel() da sessao 5.1
}