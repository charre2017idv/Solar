#pragma once
#include "Header.h"
#include "CTexture.h"
class CLevelEditor
{
public:
  CLevelEditor();
  ~CLevelEditor();
public:
  CTexture m_Background;  string m_txtPath;
  ofstream m_NodesDatafile;
  bool m_isPressed = false;
  int m_x;
  int m_y;
public:
  void Init(CTexture Background, sf::RenderWindow & Wnd, sf::Sprite sprite, sf::Texture tex, int x, int y, string MapPath, string txtPath);
  void Destroy();
  void Update();

  void Render(sf::RenderWindow &Wnd);
};

