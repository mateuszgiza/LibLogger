#pragma once

#include <string>
#include <map>

enum Color {
	Normal,
	Red,
	Green,
	BrightBlack,
	BrightRed,
	BrightYellow,
};

class ConsoleColors
{
public:
	ConsoleColors();
	~ConsoleColors();

	static void SetColor(Color color);
	static std::string GetColor(Color color);

private:
	static ConsoleColors m_singleton;

	std::map<Color, std::string> m_colors;
};
