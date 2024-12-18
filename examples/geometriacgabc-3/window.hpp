#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "abcgOpenGL.hpp"
#include "model.hpp"
#include "trackball.hpp"

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

  TrackBall m_trackBallModel;
  TrackBall m_trackBallLight;
  float m_zoom{};

  glm::mat4 m_modelMatrix{1.0f};
  glm::mat4 m_viewMatrix{1.0f};
  glm::mat4 m_projMatrix{1.0f};

  // Shaders
  std::vector<char const *> m_shaderNames{"blinnphong", "texture", "cubereflect", "depth"};
  std::vector<GLuint> m_programs;
  int m_currentProgramIndex{};

  // Mapping mode
  // 0: triplanar; 1: cylindrical; 2: spherical; 3: from mesh
  int m_mappingMode{};

  // Light and material properties
  glm::vec4 m_lightDir{-1.0f, -1.0f, -1.0f, 0.0f};
  glm::vec4 m_Ia{1.0f};
  glm::vec4 m_Id{1.0f};
  glm::vec4 m_Is{1.0f};
  glm::vec4 m_Ka{};
  glm::vec4 m_Kd{};
  glm::vec4 m_Ks{};
  float m_shininess{};

  std::string const m_skyShaderName{"skybox"};
  GLuint m_skyVAO{};
  GLuint m_skyVBO{};
  GLuint m_skyProgram{};

  std::array<float, 4> m_color {1.0f, 1.0f, 1.0f, 1.0f};
  std::array<int, 3> m_obj {4, 6, 4}; // Variavel de descrição do obj (vertices, arestas, faces)
    std::array<glm::vec3, 36> const m_skyPositions{{
      // Front
      {-1, -1, +1}, {+1, -1, +1}, {+1, +1, +1},
      {-1, -1, +1}, {+1, +1, +1}, {-1, +1, +1},
      // Back
      {+1, -1, -1}, {-1, -1, -1}, {-1, +1, -1},
      {+1, -1, -1}, {-1, +1, -1}, {+1, +1, -1},
      // Right
      {+1, -1, -1}, {+1, +1, -1}, {+1, +1, +1},
      {+1, -1, -1}, {+1, +1, +1}, {+1, -1, +1},
      // Left
      {-1, -1, +1}, {-1, +1, +1}, {-1, +1, -1},
      {-1, -1, +1}, {-1, +1, -1}, {-1, -1, -1},
      // Top
      {-1, +1, +1}, {+1, +1, +1}, {+1, +1, -1},
      {-1, +1, +1}, {+1, +1, -1}, {-1, +1, -1},
      // Bottom
      {-1, -1, -1}, {+1, -1, -1}, {+1, -1, +1},
      {-1, -1, -1}, {+1, -1, +1}, {-1, -1, +1}}};

  void createSkybox();
  void renderSkybox();
  void destroySkybox() const;
  void carregaObj(std::string obj);
};

#endif