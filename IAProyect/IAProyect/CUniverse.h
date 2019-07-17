#pragma once
#include "Header.h"
#include "CBody.h"
#include "CMathCHK.h"
class CUniverse
{
public:
  CUniverse();
  ~CUniverse();
public:
  CMathCHK Math;
  int tempRatio ;
  /////////////////////////////////////////
  // Sun
  CBody m_SUN;
  Vector2 m_sunPos = { 1000,500 };
  float m_sunRadius = 69.5700f;
  sf::Color m_sunColor = { 255, 255, 0 };
  /////////////////////////////////////////
  // Mercury
  Vector2 m_mercuryPor = { 579, 0 };
  Vector2 m_venusPos = { 1082, 0 };
  Vector2 m_earthPos = { 1496, 0 };
  Vector2 m_marsPos = { 2279, 0 };
  Vector2 m_jupiterPos = { 7783, 0 };
  Vector2 m_centroUniverse = {0,0};
public:
  void
  Init();
  void
  Destroy();
  void
  Update(float deltaTime);
  void
  Render(sf::RenderWindow &Wnd);
};

