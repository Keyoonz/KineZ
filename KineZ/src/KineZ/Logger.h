#pragma once

#include "Core.h"
#include <Windows.h>
#include <iostream>

namespace KineZ {

	enum KINEZ_API LogLevel
	{
		Info, Warning, Error, Critical
	};

	class KINEZ_API Logger
	{

	private:
		LogLevel m_level;
		HANDLE m_handle;
		const char* m_name;
	public:
		Logger(const char* name);
		Logger(LogLevel level, const char* name);
		void Info(const char* message);
		void Warn(const char* message);
		void Error(const char* message);
		void Critical(const char* message);
		void SetLogLevel(LogLevel level);

	};
	
	//Logger KZLogger(LogLevel::Info);
}