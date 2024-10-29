#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "abcgOpenGL.hpp"

class Window : public abcg::OpenGLWindow {
protected:
  void onCreate() override;
  void onPaintUI() override;

private:
  static int const m_l{2}; // Matriz dos botões - linhas
  static int const m_c{3}; // Matriz dos botões - colunas

  std::array<std::string, m_l * m_c> m_button{};
};

#endif