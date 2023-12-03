#include "Application.h"
#include "utils/DoubleLinkedList.h"
#include "Shader.h"

namespace KineZ {

	

	Application::Application(int width, int height, const char* title)
		: m_width(width), m_height(height), m_title(title), m_window(nullptr), p_camera(0, 0, width, height, 0)
	{
		extern Logger KZlogger;
		KZlogger.Info("Application created");
	}

	Application::~Application()
	{
		extern Logger KZlogger;
		KZlogger.Info("Application terminated");
	}

	void Application::Run()
	{	
		extern Logger KZlogger;
		extern DoubleLinkedList<UpdateItem*> k_updateItems;
		extern DoubleLinkedList<RenderItem*> k_renderItems;


		if (!glfwInit()) {
			extern Logger KZlogger;
			KZlogger.Error("Initializing GLFW failed.");
			return;
		}
		
		m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
		if (!m_window)
		{
			KZlogger.Error("No GLFW window detected");
			glfwTerminate();
		}

		glfwMakeContextCurrent(m_window);

		
		if (!gladLoadGL()) {
			KZlogger.Error("Failed to initialize GLAD");

		}
		else {
			KZlogger.Info("Using version : " + (std::string)(char*)glGetString(GL_VERSION));
			KZlogger.Info("Using renderer : " + (std::string)(char*)glGetString(GL_RENDERER));
		}

		
		Shader shader("shaders/vertex.glsl", "shaders/vertex.glsl");
		

		while(!glfwWindowShouldClose(m_window))
		{
			for (int i = 0; i < k_updateItems.size(); i++) {
				k_updateItems[i]->update();
			}
			

			glClear(GL_COLOR_BUFFER_BIT);
			for (int i = 0; i < k_renderItems.size(); i++) {
				k_renderItems[i]->render();
			}


			glfwSwapBuffers(m_window);

			glfwPollEvents();
		}

		glfwTerminate();
	}

}