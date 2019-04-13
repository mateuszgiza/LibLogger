#pragma once

#include <string>
#include "Logger.h"

class ConsoleLogger : public LoggerBase
{
public:
	ConsoleLogger();
	virtual ~ConsoleLogger();

	void Log(LogLevel level, std::string message) override;
	
	void Trace(std::string message) override;
	void Debug(std::string message) override;
	void Info(std::string message) override;
	void Warning(std::string message) override;
	void Error(std::string message) override;
	void Fatal(std::string message) override;
};

