#include "CTexture.h"



CTexture::CTexture()
{
}


CTexture::~CTexture()
{
}



void CTexture::Init(sf::Texture tex, sf::Sprite sprite, float posX, float posY, float scaleX, float scaleY, float originX, float originY, string src)
{
	m_tex = tex;
	m_sprite = sprite;
	m_posX = posX;
	m_posY = posY;
	m_scaleX = scaleX;
	m_scaleY = scaleY;
	m_originX = originX;
	m_originY = originY;

	if (!m_tex.loadFromFile(src))
	{
		cout << "can't load Texture" + src << endl;
	}
}

void CTexture::Destroy()
{
}

void CTexture::Update()
{
	m_sprite.setTexture(m_tex);
	m_sprite.scale(m_scaleX, m_scaleY);
	m_sprite.setPosition(m_posX,m_posY);
	m_sprite.setOrigin(m_originX,m_originY);
}

void CTexture::Render(sf::RenderWindow & Wnd)
{
	Wnd.draw(m_sprite);
}
