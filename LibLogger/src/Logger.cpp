#include <Logger.h>

std::string toString(LogLevel& level) {
	std::string str;

	switch (level)
	{
	case LogLevel::Trace:
		str = "TRACE";
		break;
	case LogLevel::Debug:
		str = "DEBUG";
		break;
	case LogLevel::Info:
		str = "INFO";
		break;
	case LogLevel::Warning:
		str = "WARNING";
		break;
	case LogLevel::Error:
		str = "ERROR";
		break;
	case LogLevel::Fatal:
		str = "FATAL";
		break;
	default:
		str = "UNKNOWN";
		break;
	}

	return str;
}
