#include <ConsoleColors.h>
#include <iostream>

ConsoleColors ConsoleColors::m_singleton = ConsoleColors();

ConsoleColors::ConsoleColors()
{
	m_colors[Normal] = "\x1b[0m";
	m_colors[Red] = "\x1b[31m";
	m_colors[Green] = "\x1b[32m";
	m_colors[BrightBlack] = "\x1b[90m";
	m_colors[BrightRed] = "\x1b[91m";
	m_colors[BrightYellow] = "\x1b[93m";
}


ConsoleColors::~ConsoleColors()
{
}

void ConsoleColors::SetColor(Color color)
{
	std::cout << GetColor(color);
}

std::string ConsoleColors::GetColor(Color color)
{
	return m_singleton.m_colors[color];
}
