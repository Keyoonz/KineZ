#include "Application.h"
#include <iostream>

namespace KineZ {

		

	Application::Application(int width, int height, const char* title)
		: m_logger(LogLevel::Info, "KineZ"), m_width(width), m_height(height), m_title(title), m_window(nullptr)
	{
		m_logger.Info("Application created");
	}

	Application::~Application()
	{
		m_logger.Info("Application terminated");
	}

	void Application::Run()
	{	

		if (!glfwInit()) {
			m_logger.Error("Initializing GLFW failed.");
			return;
		}
		
		m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
		if (!m_window)
		{
			m_logger.Error("No GLFW window detected");
			glfwTerminate();
		}

		glfwMakeContextCurrent(m_window);

		
		if (!gladLoadGL()) {
			m_logger.Error("Failed to initialize GLAD");

		}
		else {
			m_logger.Info("Using version : " + (std::string)(char*)glGetString(GL_VERSION));
			m_logger.Info("Using renderer : " + (std::string)(char*)glGetString(GL_RENDERER));
		}

		
		

		while(!glfwWindowShouldClose(m_window))
		{
			glClear(GL_COLOR_BUFFER_BIT);

			glfwSwapBuffers(m_window);

			glfwPollEvents();
		}

		glfwTerminate();
	}

}