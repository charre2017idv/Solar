#pragma once
#include "Header.h"
class CText
{
public:
	CText();
	~CText();
public:
	sf::Text m_text;
	sf::Font m_font;
	sf::Color m_color;
	int m_charSize;
	float m_x;
	float m_y;
	string m_string;
public:
	void Init(sf::Text text, sf::Font font, sf::Color color, 
			  float x, float y, int charSize, string str);
	void Destroy();
	void Update();
	void Render(sf::RenderWindow &Wnd);
};

