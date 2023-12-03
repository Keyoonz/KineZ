#include "Logger.h"

KineZ::Logger KZlogger("KineZ");

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
	if (m_level <= LogLevel::Info) {
		SetConsoleTextAttribute(m_handle, 0x0a);
		std::cout << "[" << m_name << "][INFO] " << message << std::endl;
		SetConsoleTextAttribute(m_handle, 0x0f);
	}
}

void KineZ::Logger::Warn(const char* message)
{
	if (m_level <= LogLevel::Warning) {
		SetConsoleTextAttribute(m_handle, 0x0e);
		std::cout << "[" << m_name << "][WARNING] " << message << std::endl;
		SetConsoleTextAttribute(m_handle, 0x0f);
	}
}

void KineZ::Logger::Error(const char* message)
{
	if (m_level <= LogLevel::Error) {
		SetConsoleTextAttribute(m_handle, 0x0c);
		std::cout << "[" << m_name << "][ERROR] " << message << std::endl;
		SetConsoleTextAttribute(m_handle, 0x0f);
	}
}

void KineZ::Logger::Critical(const char* message)
{
	SetConsoleTextAttribute(m_handle, 0xcf);
	std::cout << "[" << m_name << "][CRITICAL] " << message << std::endl;
	SetConsoleTextAttribute(m_handle, 0x0f);
}

void KineZ::Logger::Info(int value)
{
	if (m_level <= LogLevel::Info) {
		SetConsoleTextAttribute(m_handle, 0x0a);
		std::cout << "[" << m_name << "][INFO] " << value << std::endl;
		SetConsoleTextAttribute(m_handle, 0x0f);
	}
}

void KineZ::Logger::Warn(int value)
{
	if (m_level <= LogLevel::Warning) {
		SetConsoleTextAttribute(m_handle, 0x0e);
		std::cout << "[" << m_name << "][WARNING] " << value << std::endl;
		SetConsoleTextAttribute(m_handle, 0x0f);
	}
}

void KineZ::Logger::Error(int value)
{
	if (m_level <= LogLevel::Error) {
		SetConsoleTextAttribute(m_handle, 0x0c);
		std::cout << "[" << m_name << "][ERROR] " << value << std::endl;
		SetConsoleTextAttribute(m_handle, 0x0f);
	}
}

void KineZ::Logger::Critical(int value)
{
	SetConsoleTextAttribute(m_handle, 0xcf);
	std::cout << "[" << m_name << "][CRITICAL] " << value << std::endl;
	SetConsoleTextAttribute(m_handle, 0x0f);
}

void KineZ::Logger::Info(bool value)
{
	if (m_level <= LogLevel::Info) {
		SetConsoleTextAttribute(m_handle, 0x0a);
		std::cout << "[" << m_name << "][INFO] " << value << std::endl;
		SetConsoleTextAttribute(m_handle, 0x0f);
	}
}

void KineZ::Logger::Warn(bool value)
{
	if (m_level <= LogLevel::Warning) {
		SetConsoleTextAttribute(m_handle, 0x0e);
		std::cout << "[" << m_name << "][WARNING] " << value << std::endl;
		SetConsoleTextAttribute(m_handle, 0x0f);
	}
}

void KineZ::Logger::Error(bool value)
{
	if (m_level <= LogLevel::Error) {
		SetConsoleTextAttribute(m_handle, 0x0c);
		std::cout << "[" << m_name << "][ERROR] " << value << std::endl;
		SetConsoleTextAttribute(m_handle, 0x0f);
	}
}

void KineZ::Logger::Critical(bool value)
{
	SetConsoleTextAttribute(m_handle, 0xcf);
	std::cout << "[" << m_name << "][CRITICAL] " << value << std::endl;
	SetConsoleTextAttribute(m_handle, 0x0f);
}

void KineZ::Logger::Info(const std::string& string)
{
	if (m_level <= LogLevel::Info) {
		SetConsoleTextAttribute(m_handle, 0x0a);
		std::cout << "[" << m_name << "][INFO] " << string << std::endl;
		SetConsoleTextAttribute(m_handle, 0x0f);
	}
}

void KineZ::Logger::Warn(const std::string& string)
{
	if (m_level <= LogLevel::Warning) {
		SetConsoleTextAttribute(m_handle, 0x0e);
		std::cout << "[" << m_name << "][WARNING] " << string << std::endl;
		SetConsoleTextAttribute(m_handle, 0x0f);
	}
}

void KineZ::Logger::Error(const std::string& string)
{
	if (m_level <= LogLevel::Error) {
		SetConsoleTextAttribute(m_handle, 0x0c);
		std::cout << "[" << m_name << "][ERROR] " << string << std::endl;
		SetConsoleTextAttribute(m_handle, 0x0f);
	}
}

void KineZ::Logger::Critical(const std::string& string)
{
	SetConsoleTextAttribute(m_handle, 0xcf);
	std::cout << "[" << m_name << "][CRITICAL] " << string << std::endl;
	SetConsoleTextAttribute(m_handle, 0x0f);
}

void KineZ::Logger::Info(const glm::vec3& position)
{
	if (m_level <= LogLevel::Info) {
		SetConsoleTextAttribute(m_handle, 0x0a);
		std::cout << "[" << m_name << "][INFO] " << position.x << "," << position.y << std::endl;
		SetConsoleTextAttribute(m_handle, 0x0f);
	}

}

void KineZ::Logger::Warn(const glm::vec3& position)
{
	if (m_level <= LogLevel::Warning) {
		SetConsoleTextAttribute(m_handle, 0x0e);
		std::cout << "[" << m_name << "][WARNING] " << position.x << "," << position.y << std::endl;
		SetConsoleTextAttribute(m_handle, 0x0f);
	}
}

void KineZ::Logger::Error(const glm::vec3& position)
{
	if (m_level <= LogLevel::Error) {
		SetConsoleTextAttribute(m_handle, 0x0c);
		std::cout << "[" << m_name << "][ERROR] " << position.x << "," << position.y << std::endl;
		SetConsoleTextAttribute(m_handle, 0x0f);
	}
}

void KineZ::Logger::Critical(const glm::vec3& position)
{
	SetConsoleTextAttribute(m_handle, 0xcf);
	std::cout << "[" << m_name << "][CRITICALS] " << position.x << "," << position.y << std::endl;
	SetConsoleTextAttribute(m_handle, 0x0f);
}

void KineZ::Logger::SetLogLevel(LogLevel level)
{
	m_level = level;
}
