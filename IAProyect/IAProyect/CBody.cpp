#include "CBody.h"



CBody::CBody()
{
}

CBody::CBody(Vector2 pos, float mass, float radius, float perihelius, float aphelius, float cirlceSpeed, float circleRadius, sf::Color color, CBody * parent)
{
  m_parent = parent;
  m_direction_X = 1;
  m_pos = pos;
  m_mass = mass;
  m_radius = radius;
  m_perihelius = perihelius;
  m_aphelius = aphelius;
  m_circleSpeed = cirlceSpeed;
  m_currentSpeed = cirlceSpeed;
  m_circleRadius = circleRadius;
  /////////////////////////////////////////
  // Init circle attributes for planet
  Circle.Init(m_shapes, color, radius, pos.X, pos.Y, radius, radius);
}


CBody::~CBody()
{
}

void CBody::Init(Vector2 pos, float mass, float radius, float perihelius, float aphelius, float cirlceSpeed, float circleRadius, sf::Color color, CBody * parent)
{
  m_parent = parent;
  m_direction_X = -1;
  m_pos = pos;
  m_mass = mass;
  m_radius = radius;
  m_perihelius = perihelius;
  m_aphelius = aphelius;
  m_circleSpeed = cirlceSpeed;
  m_circleRadius = circleRadius;
  /////////////////////////////////////////
  // Init circle attributes for planet
  Circle.Init(m_shapes, color, radius, pos.X, pos.Y, radius, radius);
}


void CBody::Move(float deltaTime)
{  
  if (m_pos.X <= -(m_aphelius - 0.5f))
  {
    m_direction_X = 1;
  }
  else if (m_pos.X >= (m_perihelius - 0.5f))
  {
    m_direction_X = -1;
  }

  float test = (abs(m_pos.Y) / m_circleRadius);
  m_pos.X += m_currentSpeed * (abs(m_pos.Y + 0.1f) / m_circleRadius) * m_direction_X;

  ////Y position
  if (m_pos.X > 0.0f)
  {
    m_pos.Y = sqrt(abs(1 - (pow(m_pos.X, 2) / pow(m_perihelius, 2)))) * m_circleRadius * m_direction_X;
  }
  else
  {
    m_pos.Y = sqrt(abs(1 - (pow(m_pos.X, 2) / pow(m_aphelius, 2)))) * m_circleRadius * m_direction_X;
  }
}

void CBody::setParent(CBody * parent)
{
  m_parent = parent;
}

void CBody::addChild(CBody child)
{
  m_children.push_back(child);
}

void CBody::Update(CBody * parent, float deltaTime)
{
  m_pos.X -= m_circleSpeed * deltaTime;
  if (parent)
    Circle.Update(m_Math.Add(parent->m_pos, m_pos));
  else
    Circle.Update( m_pos );

  if (m_parent)
    Move(deltaTime);
}

void CBody::Render(sf::RenderWindow & Wnd)
{
  Circle.Render(Wnd,m_transform);
}
