#pragma once

#include "Logger.h"
#include "UpdateItem.h"
#include "Model.h"
#include "Camera.h"

#include "OpenGlRelated.h"
#include "Shader.h"

namespace KineZ {
	class Application {
	private:
		int m_width, m_height;
		const char* m_title;
		GLFWwindow* m_window;
		static void Application::MessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
	protected:
		Camera p_camera;
	public:
		KineZ::ShaderPaths shaderPaths;
		void (*ImplementMeshes)(void);
		Application(int width, int height, const char* title);
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}