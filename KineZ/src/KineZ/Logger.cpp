#include "Logger.h"

KineZ::Logger::Logger(const char* name)
	: m_level(LogLevel::Info), m_handle(GetStdHandle(STD_OUTPUT_HANDLE)), m_name(name)
{
}

KineZ::Logger::Logger(LogLevel level, const char* name)
	: m_level(level), m_handle(GetStdHandle(STD_OUTPUT_HANDLE)), m_name(name)
{
}

void KineZ::Logger::Info(const char* message)
{
	SetConsoleTextAttribute(m_handle, 0x0a);
	std::cout << "["<< m_name << "][INFO] " << message << std::endl;
	SetConsoleTextAttribute(m_handle, 0x0f);
}

void KineZ::Logger::Warn(const char* message)
{
	SetConsoleTextAttribute(m_handle, 0x0e);
	std::cout << "[" << m_name << "][WARNING] " << message << std::endl;
	SetConsoleTextAttribute(m_handle, 0x0f);
}

void KineZ::Logger::Error(const char* message)
{
	SetConsoleTextAttribute(m_handle, 0x0c);
	std::cout << "[" << m_name << "]ERROR] " << message << std::endl;
	SetConsoleTextAttribute(m_handle, 0x0f);
}

void KineZ::Logger::Critical(const char* message)
{
	SetConsoleTextAttribute(m_handle, 0xcf);
	std::cout << "[" << m_name << "]CRITICAL] " << message << std::endl;
	SetConsoleTextAttribute(m_handle, 0x0f);
}

void KineZ::Logger::SetLogLevel(LogLevel level)
{
	m_level = level;
}
