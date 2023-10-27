#pragma once

#include "Core.h"
#include "Logger.h"

namespace KineZ {
	class KINEZ_API Application {
	private:
		KineZ::Logger m_logger;
	public:
		Application();
		virtual ~Application();


		void Run();

	};

	// To be defined in CLIENT
	Application* CreateApplication();
}