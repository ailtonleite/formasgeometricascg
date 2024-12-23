#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <random>
#include <vector> 

#include "abcgOpenGL.hpp"
#include "model.hpp"
#include "trackball.hpp"
#include <string>

class Window : public abcg::OpenGLWindow {
protected:
  void onEvent(SDL_Event const &event) override;
  void onCreate() override;
  void onUpdate() override;
  void onPaint() override;
  void onPaintUI() override;
  void onResize(glm::ivec2 const &size) override;
  void onDestroy() override;

private:
  glm::ivec2 m_viewportSize{};

  Model m_model;
  int m_trianglesToDraw{};

  TrackBall m_trackBall;
  float m_zoom{};

  glm::mat4 m_modelMatrix{1.0f};
  glm::mat4 m_viewMatrix{1.0f};
  glm::mat4 m_projMatrix{1.0f};

  GLuint m_program{};
  GLint m_colorLocation{};
  std::default_random_engine m_randomEngine;

  std::array<float, 4> m_color {1.0f, 1.0f, 1.0f, 1.0f};
  std::array<int, 3> m_obj {4, 6, 4}; // Variavel de descrição do obj (vertices, arestas, faces)

  void carregaObj(std::string obj);
};

#endif