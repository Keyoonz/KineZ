#include "Application.h"

namespace KineZ {

	

	Application::Application()
		: m_logger(LogLevel::Info, "KineZ")
	{
		m_logger.Info("Application created");
		m_logger.Warn("Application created");
		m_logger.Error("Application created");
		m_logger.Critical("Application created");
		  
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (true)
		{

		}
	}

}