#include "CShapes.h"



CShapes::CShapes()
{
}


CShapes::~CShapes()
{
}

void CShapes::Init(SHAPES shape, sf::Color shapeColor, float radius, float x, float y, float originX, float originY)
{
	m_shape = shape;															// Set shape type
  m_shapeColor = shapeColor;
	m_radius = radius;															// Set circle radius
	m_x = x;																	// Set position 'x'
	m_y = y;																	// Set position 'y'
	m_originX = originX;
	m_originY = originY;
}

void CShapes::Destroy()
{

}

void CShapes::Update()
{
	m_shape.Circle.setRadius(m_radius);											                      // Update circle radius
	m_shape.Circle.setPosition(m_x, m_y);										                      // Update position of circles
	m_shape.Circle.setOrigin(m_originX, m_originY);
	m_shape.Circle.setOutlineThickness(2);										                    // Update outline
	m_shape.Circle.setOutlineColor(m_shapeColor);						            // Update outline color
	m_shape.Circle.setFillColor(m_shapeColor);					            // Update circle color
}

void CShapes::Render(sf::RenderWindow & Wnd, sf::Transform & transform)
{

	Wnd.draw(m_shape.Circle,transform);													// Render the shape
}
