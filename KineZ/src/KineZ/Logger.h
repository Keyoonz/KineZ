#pragma once

#include "Core.h"
#include "glm/glm.hpp"

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
		void Info(    const char* message);
		void Warn(    const char* message);
		void Error(   const char* message);
		void Critical(const char* message);
		void Info(    int value);
		void Warn(    int value);
		void Error(   int value);
		void Critical(int value);
		void Info(    bool value);
		void Warn(    bool value);
		void Error(   bool value);
		void Critical(bool value);
		void Info(    const std::string& string);
		void Warn(    const std::string& string);
		void Error(   const std::string& string);
		void Critical(const std::string& string);
		void Info(    const glm::vec3& position);
		void Warn(    const glm::vec3& position);
		void Error(   const glm::vec3& position);
		void Critical(const glm::vec3& position);
		
		void SetLogLevel(LogLevel level);

	};
}