#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <random>
#include "abcgOpenGL.hpp"
#include <abcgOpenGLWindow.hpp>

class Window : public abcg::OpenGLWindow {
protected:
  void onCreate() override;
  void onPaint() override;
  void onPaintUI() override;
  void onDestroy() override;

private:
  static int const m_l{2}; // Matriz dos botões - linhas
  static int const m_c{3}; // Matriz dos botões - colunas

  int button_click; // Variavel que indica qual botão foi selecionado
  int sides;
  int m_sides;

  glm::ivec2 m_viewportSize{};

  GLuint m_VAO{};
  GLuint m_VBOPositions{};
  GLuint m_VBOColors{};
  GLuint m_program{};
  std::default_random_engine m_randomEngine;

  std::array<std::string, m_l * m_c> m_button{};

  void poligono(int sides); // definindo funcao de criacao de figuras geometricas comuns
  // TODO: Possivel funcoes de figuras mais complexas
};

#endif