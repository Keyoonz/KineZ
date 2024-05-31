#include "Logger.h"

KineZ::Logger KZlogger("KineZ");

KineZ::Logger::Logger(const char *name)
    : m_level(LogLevel::Info), m_name(name) {}

KineZ::Logger::Logger(LogLevel level, const char *name)
    : m_level(level), m_name(name) {}

void KineZ::Logger::Info(const char *message) {
  if (m_level <= LogLevel::Info) {
    std::cout << "\033[0;34m";
    std::cout << "[" << m_name << "][INFO] " << message << std::endl;
    std::cout << "\033[0m";
  }
}

void KineZ::Logger::Warn(const char *message) {
  if (m_level <= LogLevel::Warning) {
    std::cout << "\033[0;33m";
    std::cout << "[" << m_name << "][WARNING] " << message << std::endl;
    std::cout << "\033[0m";
  }
}

void KineZ::Logger::Error(const char *message) {
  std::cout << "\033[0;31m";
  std::cout << "[" << m_name << "][ERROR] " << message << std::endl;
  std::cout << "\033[0m";
}

void KineZ::Logger::Critical(const char *message) {
  std::cout << "\035[0m";
  std::cout << "[" << m_name << "][CRITICAL] " << message << std::endl;
  std::cout << "\033[0m";
}

void KineZ::Logger::Info(int value) {
  if (m_level <= LogLevel::Info) {
    std::cout << "\033[0;34m";
    std::cout << "[" << m_name << "][INFO] " << value << std::endl;
    std::cout << "\033[0m";
  }
}

void KineZ::Logger::Warn(int value) {
  if (m_level <= LogLevel::Warning) {
    std::cout << "\033[0;33m";
    std::cout << "[" << m_name << "][WARNING] " << value << std::endl;
    std::cout << "\033[0m";
  }
}

void KineZ::Logger::Error(int value) {
  if (m_level <= LogLevel::Error) {
    std::cout << "\033[0;31m";
    std::cout << "[" << m_name << "][ERROR] " << value << std::endl;
    std::cout << "\033[0m";
  }
}

void KineZ::Logger::Critical(int value) {
  std::cout << "\035[0m";
  std::cout << "[" << m_name << "][CRITICAL] " << value << std::endl;
  std::cout << "\033[0m";
}

void KineZ::Logger::Info(bool value) {
  if (m_level <= LogLevel::Info) {
    std::cout << "\033[0;34m";
    std::cout << "[" << m_name << "][INFO] " << value << std::endl;
    std::cout << "\033[0m";
  }
}

void KineZ::Logger::Warn(bool value) {
  if (m_level <= LogLevel::Warning) {
    std::cout << "\033[0;33m";
    std::cout << "[" << m_name << "][WARNING] " << value << std::endl;
    std::cout << "\033[0m";
  }
}

void KineZ::Logger::Error(bool value) {
  if (m_level <= LogLevel::Error) {
    std::cout << "\033[0;31m";
    std::cout << "[" << m_name << "][ERROR] " << value << std::endl;
    std::cout << "\033[0m";
  }
}

void KineZ::Logger::Critical(bool value) {
  std::cout << "\035[0m";
  std::cout << "[" << m_name << "][CRITICAL] " << value << std::endl;
  std::cout << "\033[0m";
}

void KineZ::Logger::Info(const std::string &string) {
  if (m_level <= LogLevel::Info) {
    std::cout << "\033[0;34m";
    std::cout << "[" << m_name << "][INFO] " << string << std::endl;
    std::cout << "\033[0m";
  }
}

void KineZ::Logger::Warn(const std::string &string) {
  if (m_level <= LogLevel::Warning) {
    std::cout << "\033[0;33m";
    std::cout << "[" << m_name << "][WARNING] " << string << std::endl;
    std::cout << "\033[0m";
  }
}

void KineZ::Logger::Error(const std::string &string) {
  if (m_level <= LogLevel::Error) {
    std::cout << "\033[0;31m";
    std::cout << "[" << m_name << "][ERROR] " << string << std::endl;
    std::cout << "\033[0m";
  }
}

void KineZ::Logger::Critical(const std::string &string) {
  std::cout << "\035[0m";
  std::cout << "[" << m_name << "][CRITICAL] " << string << std::endl;
  std::cout << "\033[0m";
}

void KineZ::Logger::Info(const glm::vec3 &position) {
  if (m_level <= LogLevel::Info) {
    std::cout << "\033[0;34m";
    std::cout << "[" << m_name << "][INFO] " << position.x << "," << position.y
              << std::endl;
    std::cout << "\033[0m";
  }
}

void KineZ::Logger::Warn(const glm::vec3 &position) {
  if (m_level <= LogLevel::Warning) {
    std::cout << "\033[0;33m";
    std::cout << "[" << m_name << "][WARNING] " << position.x << ","
              << position.y << std::endl;
    std::cout << "\033[0m";
  }
}

void KineZ::Logger::Error(const glm::vec3 &position) {
  if (m_level <= LogLevel::Error) {
    std::cout << "\033[0;31m";
    std::cout << "[" << m_name << "][ERROR] " << position.x << "," << position.y
              << std::endl;
    std::cout << "\033[0m";
  }
}

void KineZ::Logger::Critical(const glm::vec3 &position) {
  std::cout << "\035[0m";
  std::cout << "[" << m_name << "][CRITICALS] " << position.x << ","
            << position.y << std::endl;
  std::cout << "\033[0m";
}

void KineZ::Logger::SetLogLevel(LogLevel level) { m_level = level; }
