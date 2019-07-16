#include "CText.h"



CText::CText()
{
}


CText::~CText()
{
}

void CText::Init(sf::Text text, sf::Font font, sf::Color color, float x, float y, int charSize, string str)
{
	m_text = text;
	m_font = font;
	m_color = color;
	m_x = x;
	m_y = y;
	m_charSize = charSize;
	m_string = str;
	if (!font.loadFromFile("accid__.ttf"))
		cout << "can't load font" << endl;
}

void CText::Destroy()
{

}

void CText::Update()
{
	m_text.setPosition(m_x,m_y);
	m_text.setCharacterSize(m_charSize);
	m_text.setFillColor(m_color);
	m_text.setFont(m_font);
	m_text.setString(m_string);
}

void CText::Render(sf::RenderWindow & Wnd)
{
	Wnd.draw(m_text);
}
