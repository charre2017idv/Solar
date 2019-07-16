#pragma once
#include "Header.h"
class CTexture
{
public:
	CTexture();
	~CTexture();
public:
	sf::Texture m_tex;
	sf::Sprite  m_sprite;
	float m_posX;
	float m_posY;
	float m_scaleX;
	float m_scaleY;
	float m_originX;
	float m_originY;
public:
	void Init(sf::Texture tex, sf::Sprite sprite, 
			  float posX, float posY,
			  float scaleX, float scaleY, 
			  float originX, float originY,
			  string src);
	void Destroy();
	void Update();
	void Render(sf::RenderWindow &Wnd);
};

