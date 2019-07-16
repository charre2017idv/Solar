#pragma once
#include "Header.h"
static class CTimer
{
public:
  CTimer()  = default;
  ~CTimer() = default;
public:
  std::chrono::duration <double, ratio<1>> m_deltaTime;

  std::chrono::time_point<std::chrono::steady_clock> m_lastTime;
  std::chrono::time_point<std::chrono::steady_clock> m_currentTime;
public:
  void
  start();
  float
  GetDeltaTime();
};

