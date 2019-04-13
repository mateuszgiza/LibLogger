#pragma once

#include <string>

enum LogLevel {
	Trace = 0,
	Debug = 1,
	Info = 2,
	Warning = 3,
	Error = 4,
	Fatal = 5
};

std::string toString(LogLevel& level);

class ILogger
{
public:
	virtual ~ILogger() {}

	virtual void Log(LogLevel level, std::string message) = 0;
	virtual void Trace(std::string message) = 0;
	virtual void Debug(std::string message) = 0;
	virtual void Info(std::string message) = 0;
	virtual void Warning(std::string message) = 0;
	virtual void Error(std::string message) = 0;
	virtual void Fatal(std::string message) = 0;
};

class LoggerBase : public ILogger {
public:
	virtual ~LoggerBase() {}

	void Trace(std::string message) override {
		Log(LogLevel::Trace, message);
	}

	void Debug(std::string message) override {
		Log(LogLevel::Debug, message);
	}

	void Info(std::string message) override {
		Log(LogLevel::Info, message);
	}

	void Warning(std::string message) override {
		Log(LogLevel::Warning, message);
	}

	void Error(std::string message) override {
		Log(LogLevel::Error, message);
	}

	void Fatal(std::string message) override {
		Log(LogLevel::Fatal, message);
	}
};
