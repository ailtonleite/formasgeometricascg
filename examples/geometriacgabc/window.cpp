#include "window.hpp"

void Window::onCreate() {
  // TODO: Ao iniciar a aplicacao, pré-selecionar a primeira forma geometrica (primeiro botão)
}

void Window::onPaintUI() {
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
                }
            }
            ImGui::Spacing();
        }
        ImGui::EndTable();
      }
    }

    ImGui::Spacing();
    }
    
    // TODO: Add exibir qual botão está selecionado
    // TODO: Add formas geometricas
    // TODO: Add janela que mostrará as formas geometricas

    ImGui::End();
}