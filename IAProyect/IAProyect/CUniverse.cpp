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
  m_SUN.Init(m_sunPos, 0, 69.5700f, 0, 0, 0,0, m_sunColor, nullptr);
  /////////////////////////////////////////
  // Initialize Mercury
  m_SUN.addChild
  (
    CBody(
      Vector2{ 460.1f,0 }, 
      1,
      .02439f,
      460.0f,
      698.0f,
      4.78f,
      579,
      sf::Color(0, 153, 255),
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
