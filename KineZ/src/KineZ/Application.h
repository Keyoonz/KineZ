#pragma once

#include "Core.h"
#include "Logger.h"
#include "UpdateItem.h"
#include "RenderItem.h"
#include "Camera.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace KineZ {
	class KINEZ_API Application {
	private:
		int m_width, m_height;
		const char* m_title;
		Logger m_logger;
		GLFWwindow* m_window;
	protected:
		Camera p_camera;
	public:
		Application(int width, int height, const char* title);
		virtual ~Application();

		void Run();

	};

	// To be defined in CLIENT
	Application* CreateApplication();
}