#pragma once
#include "Header.h"
class CShapes
{
public:
	CShapes();
	~CShapes();
public:
	SHAPES m_shape;
	float m_radius;
	float m_x;
	float m_y;
	float m_originX;
	float m_originY;
  sf::Color m_shapeColor;
public:
	void Init(SHAPES shape, sf::Color shapeColor, float radius, float x, float y, float originX, float originY);
	void Destroy();
	void Update(Vector2 newPos);
	void Render(sf::RenderWindow &Wnd, sf::Transform & transform);
};

