#include "CTimer.h"


void CTimer::start()
{
  m_lastTime = std::chrono::high_resolution_clock::now(); // Get the current tick
}

float CTimer::GetDeltaTime()
{
  m_currentTime = std::chrono::high_resolution_clock::now(); // Get the current tick
  m_deltaTime = std::chrono::duration_cast<std::chrono::duration<double, ratio<1>>> (m_currentTime - m_lastTime);

  m_lastTime = m_currentTime;

  return m_deltaTime.count();
}
