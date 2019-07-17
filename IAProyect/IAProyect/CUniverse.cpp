#include "CUniverse.h"



CUniverse::CUniverse()
{
}


CUniverse::~CUniverse()
{
}

void CUniverse::Init()
{
  
  /////////////////////////////////////////
  // Initialize Sun
  m_SUN.Init(m_sunPos, 0,tempRatio + 69.5700f, 0, 0, 0,0, m_sunColor, nullptr);
  /////////////////////////////////////////
  // Initialize Mercury
  m_SUN.addChild
  (
    CBody(
      Vector2{ 460.1f,0 }, 
      1,
      tempRatio + .02439f,
      460.0f,
      698.0f,
      4.78f,
      579,
      sf::Color(0, 153, 255),
      &m_SUN
    )
  );   
  /////////////////////////////////////////
  // Venus
  m_SUN.addChild
  (
    CBody(
      Vector2{ 1074.1f,0 },
      1,
      tempRatio + .06052f,
      1074.0f,
      1090.0f,
      3.50f,
      1082,
      sf::Color(255, 102, 0),
      &m_SUN
    )
  );
  /////////////////////////////////////////
  // Earth
  m_SUN.addChild
  (
    CBody(
      Vector2{ 1470.1f,0 },
      1,
      tempRatio + .06378f,
      1470.0f,
      1520.0f,
      3.50f,
      1496,
      sf::Color(51, 204, 51),
      &m_SUN
    )
  );
  /////////////////////////////////////////
  // Mars
  m_SUN.addChild
  (
    CBody(
      Vector2{ 2067.1f,0 },
      1,
      tempRatio + .03397f,
      2067.0f,
      2491.0f,
      3.50f,
      2279,
      sf::Color(255, 0 ,0),
      &m_SUN
    )
  );
  /////////////////////////////////////////
  // Jupiter
  m_SUN.addChild
  (
    CBody(
      Vector2{ 7409.1f,0 },
      1,
      tempRatio + .7150f,
      7409.0f,
      8157.0f,
      3.50f,
      7785,
      sf::Color(255, 204, 0),
      &m_SUN
    )
  );
}

void CUniverse::Update(float deltaTime)
{

  m_SUN.Update(nullptr, deltaTime);
  for (int i = 0; i < m_SUN.m_children.size(); i++)
  {
    m_SUN.m_children[i].Update(&m_SUN, deltaTime);
  }
}

void CUniverse::Render(sf::RenderWindow & Wnd)
{
  /////////////////////////////////////////
  // Draw the sun
  m_SUN.Render(Wnd);
  /////////////////////////////////////////
  // Draw Sun's children
  for (int i = 0; i < m_SUN.m_children.size(); i++)
  {
    m_SUN.m_children[i].Render(Wnd);
  }
}
