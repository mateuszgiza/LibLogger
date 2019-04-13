#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

#include <ConsoleLogger.h>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <sstream>
#include <ConsoleColors.h>

ConsoleLogger::ConsoleLogger()
{
}

ConsoleLogger::~ConsoleLogger()
{
}

void ConsoleLogger::Log(LogLevel level, std::string message)
{
	using namespace std::chrono;

	auto time_now = system_clock::to_time_t(system_clock::now());
	auto time_now_string = std::put_time(std::localtime(&time_now), "%T");

	std::ostringstream time_stream;
	time_stream << "[" << time_now_string << "]";

	std::ostringstream level_stream;
	level_stream << "[" << toString(level) << "]";

	std::cout  
		<< std::setw(10)
		<< time_stream.str()
		<< std::setw(10)
		<< level_stream.str()
		<< std::setw(2) << ""
		<< message 
		<< std::endl;
}

void ConsoleLogger::Trace(std::string message)
{
	ConsoleColors::SetColor(Color::BrightBlack);
	LoggerBase::Trace(message);
	ConsoleColors::SetColor(Color::Normal);
}

void ConsoleLogger::Debug(std::string message)
{
	ConsoleColors::SetColor(Color::Normal);
	LoggerBase::Debug(message);
	ConsoleColors::SetColor(Color::Normal);
}

void ConsoleLogger::Info(std::string message)
{
	ConsoleColors::SetColor(Color::Green);
	LoggerBase::Info(message);
	ConsoleColors::SetColor(Color::Normal);
}

void ConsoleLogger::Warning(std::string message)
{
	ConsoleColors::SetColor(Color::BrightYellow);
	LoggerBase::Warning(message);
	ConsoleColors::SetColor(Color::Normal);
}

void ConsoleLogger::Error(std::string message)
{
	ConsoleColors::SetColor(Color::BrightRed);
	LoggerBase::Error(message);
	ConsoleColors::SetColor(Color::Normal);
}

void ConsoleLogger::Fatal(std::string message)
{
	ConsoleColors::SetColor(Color::Red);
	LoggerBase::Fatal(message);
	ConsoleColors::SetColor(Color::Normal);
}
