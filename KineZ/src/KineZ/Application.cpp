#include "Application.h"
#include "Logger.h"
#include "Model.h"
#include "Shader.h"
#include "utils/DoubleLinkedList.h"

namespace KineZ {
Application::Application(int width, int height, const char *title)
    : m_width(width), m_height(height), m_title(title), m_window(nullptr),
      p_camera(0, 0, width, height, 0), ImplementMeshes(nullptr) {
  extern Logger KZlogger;
  KZlogger.Info("Application created");
}

Application::~Application() {
  extern Logger KZlogger;
  KZlogger.Info("Application terminated");
}

void Application::MessageCallback(GLenum source, GLenum type, GLuint id,
                                  GLenum severity, GLsizei length,
                                  const GLchar *message,
                                  const void *userParam) {
  extern Logger KZlogger;
  std::string finalMessage = "[Open GL callback] ";
  finalMessage.append(message);
  KZlogger.Error(finalMessage);
}

void Application::Run() {
  extern Logger KZlogger;
  extern DoubleLinkedList<UpdateItem *> k_updateItems;
  extern DoubleLinkedList<Model *> k_models;

  if (!glfwInit()) {
    KZlogger.Error("Initializing GLFW failed.");
    return;
  }

  glfwSwapInterval(1);

  m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
  if (!m_window) {
    KZlogger.Error("No GLFW window detected");
    glfwTerminate();
  }

  glfwMakeContextCurrent(m_window);

  if (!gladLoadGL()) {
    KZlogger.Error("Failed to initialize GLAD");

  } else {
    KZlogger.Info("Using version : " +
                  (std::string)(char *)glGetString(GL_VERSION));
    KZlogger.Info("Using renderer : " +
                  (std::string)(char *)glGetString(GL_RENDERER));
  }

  glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
  glEnable(GL_DEBUG_OUTPUT);
  glDebugMessageCallback(MessageCallback, NULL);

  ImplementMeshes();
  Shader shader(shaderPaths);

  while (!glfwWindowShouldClose(m_window)) {
    for (int i = 0; i < k_updateItems.size(); i++) {
      k_updateItems[i]->update();
    }

    glClear(GL_COLOR_BUFFER_BIT);
    p_camera.SetupRender(shader);
    for (int i = 0; i < k_models.size(); i++) {
      k_models[i]->Render(shader);
    }

    glfwSwapBuffers(m_window);

    glfwPollEvents();
  }

  glfwTerminate();
}

} // namespace KineZ
