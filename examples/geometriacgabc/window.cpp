#include "window.hpp"

void Window::onCreate() {
    // Pré-selecionar a primeira forma geométrica (primeiro botão)
    m_selectedShapeIndex = 0; // Assume que m_selectedShapeIndex é um membro da classe
}

void Window::onPaintUI() {
    // Get size of application's window
    auto const appWindowWidth{gsl::narrow<float>(getWindowSettings().width)};
    auto const appWindowHeight{gsl::narrow<float>(getWindowSettings().height)};

    // Janela dos botões
    {
        ImGui::SetNextWindowSize(ImVec2(appWindowWidth, appWindowHeight / 3));
        ImGui::SetNextWindowPos(ImVec2(0, 0));

        auto const flags{ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoResize |
                         ImGuiWindowFlags_NoCollapse};
        ImGui::Begin("Geometria ABC", nullptr, flags);

        auto const gridHeight{(appWindowHeight / 3) - 22 - 20 - (m_l * 10) - 20};
        auto const buttonHeight{gridHeight / m_l};

        std::array<std::string, m_l * m_c> const fg = {
            "Forma 1", 
            "Forma 2", 
            "Forma 3", 
            "Forma 4", 
            "Forma 5", 
            "Forma 6"
        };

        if (ImGui::BeginTable("buttons", m_c)) {
            for (auto i : iter::range(m_l)) {
                ImGui::TableNextRow();
                for (auto j : iter::range(m_c)) {
                    ImGui::TableSetColumnIndex(j);
                    auto const offset = i * m_c + j;

                    auto const& fg_value = fg[offset];

                    auto buttonText{fmt::format("{}##{}{}", fg_value, i, j)};
                    if (ImGui::Button(buttonText.c_str(), ImVec2(-1, buttonHeight))) {
                        m_button.at(offset) = fg_value;
                        m_selectedShapeIndex = offset; // Armazena o índice do botão pressionado
                    }
                }
                ImGui::Spacing();
            }
            ImGui::EndTable();
        }

        ImGui::Spacing();
    }

    // Exibir qual botão está selecionado
    ImGui::Text("Forma selecionada: %s", fg[m_selectedShapeIndex].c_str());

    // Desenhar a forma geométrica correspondente
    drawShape(m_selectedShapeIndex); // Função para desenhar a forma

    ImGui::End();
}

void Window::drawShape(int index) {
    // Aqui você deve implementar a lógica para desenhar a forma correspondente ao índice
    // Por exemplo:
    switch (index) {
        case 0:
            // Desenhar Forma 1
            break;
        case 1:
            // Desenhar Forma 2
            break;
        case 2:
            // Desenhar Forma 3
            break;
        case 3:
            // Desenhar Forma 4
            break;
        case 4:
            // Desenhar Forma 5
            break;
        case 5:
            // Desenhar Forma 6
            break;
        default:
            break;
    }
}
