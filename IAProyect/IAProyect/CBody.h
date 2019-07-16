#pragma once
#include "Header.h"
#include "CShapes.h"
#include "CMathCHK.h"
class CBody
{
public:
  CBody();
  CBody(
    Vector2 pos,
    float mass,
    float radius,
    float perihelius,
    float aphelius,
    float cirlceSpeed,
    float circleRadius,
    sf::Color color, 
    CBody * parent
  );
  ~CBody();
public:
  CMathCHK m_Math;
  CBody * m_parent;
  vector<CBody> m_children;
  /////////////////////////////////////////
  // Attributes
  Vector2 m_pos;
  float m_mass;
  float m_direction_X;
  float m_direction_Y;
  float m_perihelius;
  float m_aphelius;
  float m_circleRadius;
  float m_currentSpeed;
  float m_circleSpeed;
  float m_radius;
  SHAPES m_shapes;
  CShapes Circle;
  sf::Color m_color;
  sf::Transform m_transform;
public:
  void
  Init 
  (
    Vector2 pos, 
    float mass,
    float radius,
    float perihelius,
    float aphelius,
    float cirlceSpeed,
    float circleRadius,
    sf::Color color,
    CBody * parent
  );
  void
  Destroy();
  void
  Update(CBody * parent, float deltaTime);
  void
  Render(sf::RenderWindow &Wnd);
  void 
  Move(float deltaTime);
  void 
  setParent(CBody * parent);
  void 
  addChild(CBody  child);
};

