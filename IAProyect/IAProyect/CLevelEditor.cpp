#include "CLevelEditor.h"



CLevelEditor::CLevelEditor()
{
}


CLevelEditor::~CLevelEditor()
{
}

void CLevelEditor::Init(CTexture Background, sf::RenderWindow & Wnd, sf::Sprite sprite, sf::Texture tex, int x, int y, string MapPath, string txtPath)
{
  m_Background = Background;
  m_txtPath = txtPath;
  Background.Init(tex, sprite, 0, 0, 1, 1, 0, 0, MapPath);  
  m_x = x;
  m_y = y;
  sf::Vector2i position;

  if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
  {
    if (!m_isPressed) {
      cout << m_x << " : " << m_y << endl;
      m_NodesDatafile.open(m_txtPath, ios::app);
      m_NodesDatafile << m_x << " : " << m_y << " @" << endl;
      m_NodesDatafile.close();
      m_isPressed = true;
      // break;
    }
  }
  else {
    m_isPressed = false;
  }
  Background.Update();
  Background.Render(Wnd);
}

void CLevelEditor::Destroy()
{
}

void CLevelEditor::Update()
{
  
}

void CLevelEditor::Render(sf::RenderWindow & Wnd)
{
}
