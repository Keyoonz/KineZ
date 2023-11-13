#include "Application.h"
#include "utils/DoubleLinkedList.h"

#include <iostream>

namespace KineZ {

		

	Application::Application(int width, int height, const char* title)
		: m_logger(LogLevel::Info, "KineZ"), m_width(width), m_height(height), m_title(title), m_window(nullptr), p_camera(0, 0, width, height)
	{
		m_logger.Info("Application created");
	}

	Application::~Application()
	{
		m_logger.Info("Application terminated");
	}

	void Application::Run()
	{	
		extern DoubleLinkedList<UpdateItem*> k_updateItems;
		extern DoubleLinkedList<RenderItem*> k_renderItems;


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
			for (int i = 0; i < k_updateItems.size(); i++) {
				k_updateItems[i]->update();
			}
			
			
			glClear(GL_COLOR_BUFFER_BIT);
			for (int i = 0; i < k_renderItems.size(); i++) {
				k_renderItems[i]->render(p_camera);
			}


			glfwSwapBuffers(m_window);

			glfwPollEvents();
		}

		glfwTerminate();
	}

}