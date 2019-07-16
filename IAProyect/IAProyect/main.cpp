//#include <SFML/Window.hpp>
//#include <SFML/Graphics.hpp>
#include "Header.h"
#include "CManager.h"
#include "CUniverse.h"

#include "CTimer.h"
#define RANGE 50.0f
float g_speed = 100;
float g_speedZoom = 0.2;
CManager _MANAGER;
float t = 0;
float changeX = 0.0f;
float changeY = 0.0f;
bool isDebug = false;
bool isDebugDir = false;
bool isDebugsteer = false;
bool isDebugReject = false;
Vector2 User;
sf::Texture BGTex;
sf::Sprite BGSprite;
sf::Texture MouseTex;
sf::Sprite MouseSprite;

 ofstream NodesDatafile;

 vector<Vector2> PlanetCoords;
 vector<float> planetSize;
 vector<sf::Color> PlanetColor;

 CUniverse SistemaSolar;
 CTimer Timer;

 void zoom(const float &speed);
 void move(const float &speed, const float &dirX, const float &diry);


void update()
{
  SistemaSolar.Update(Timer.GetDeltaTime());
  SistemaSolar.Render(_MANAGER.m_RenderWindow);
//   for (size_t i = 0; i < PlanetCoords.size(); i++)
// 	{
// 		SHAPES Circle;
// 		_MANAGER._SHAPES.Init(
// 			Circle, 
//       PlanetColor[i],
//       planetSize[i], 
//       PlanetCoords[i].X, 
// 			PlanetCoords[i].Y, 
//       planetSize[i],
//       planetSize[i]
//     );
// 
//     sf::Transform transform;
//     sf::Vector2f vec = { PlanetCoords[i].X, PlanetCoords[i].Y };
//     transform.rotate(45.0f,vec);
// 		//_MANAGER._SHAPES.Update();
// 		_MANAGER._SHAPES.Render(_MANAGER.m_RenderWindow, transform);
// 	}
// 	_MANAGER.m_TEX[0].Init(
// 		BGTex, 
// 		BGSprite, 
// 		0, 0, 1, 1, 0, 0, 
// 		"Textures\\track2.png");
// 	
// 	_MANAGER.m_TEX[1].Init(
// 		MouseTex, 
// 		MouseSprite,
// 		User.X, User.Y, 
// 		1, 1, 26 >> 1, 37 >> 1, 
// 		"Textures\\P.png");

// 	for (size_t i = 0; i < _MANAGER.m_TEX.size(); i++)
// 	{
// 		_MANAGER.m_TEX[i].Update();
// 		_MANAGER.m_TEX[i].Render(_MANAGER.m_RenderWindow);
// 	}
// 																				// Draw Hot Keys Text
// 	_MANAGER.m_Textos[0].Init(
// 		_MANAGER.HotKey1, 
// 		_MANAGER.m_font, 
// 		sf::Color::White, 
// 		750, 30, 20, "HOT KEYS");
// 	_MANAGER.m_Textos[1].Init(
// 		_MANAGER.HotKey2, 
// 		_MANAGER.m_font, 
// 		sf::Color::White, 
// 		750, 60, 20, "'D' - DEBUG");
// 	_MANAGER.m_Textos[2].Init(
// 		_MANAGER.HotKey3, 
// 		_MANAGER.m_font, 
// 		sf::Color::White, 
// 		750, 90, 20,
// 		"'ESC' - ESCAPE");
// 
// 	for (size_t i = 0; i < _MANAGER.m_Textos.size(); i++)
// 	{
// 		_MANAGER.m_Textos[i].Update();
// 		_MANAGER.m_Textos[i].Render(_MANAGER.m_RenderWindow);
// 	}
// 																				// Draw Debug Data
// 	if (isDebug)								
// 	{
// 		for (size_t i = 0; i < _MANAGER.m_Nodes.size(); i++)
// 		{
// 			if (i < _MANAGER.m_Nodes.size() - 2)
// 			{
// 				sf::Vertex line[] =
// 				{
// 					sf::Vertex(sf::Vector2f(
// 						_MANAGER.m_Nodes[i].X,  _MANAGER.m_Nodes[i].Y)),
// 					sf::Vertex(sf::Vector2f(
// 						_MANAGER.m_Nodes[i + 1].X,  _MANAGER.m_Nodes[i + 1].Y))
// 				};
// 				_MANAGER.m_RenderWindow.draw(line, 2, sf::Lines);
// 			}
// 			else
// 			{
// 				sf::Vertex line[] =
// 				{
// 					sf::Vertex(sf::Vector2f(
// 						_MANAGER.m_Nodes[_MANAGER.m_Nodes.size() - 2].X, 
// 						_MANAGER.m_Nodes[_MANAGER.m_Nodes.size() - 2].Y)),
// 					sf::Vertex(sf::Vector2f(
// 						_MANAGER.m_Nodes[0].X,  _MANAGER.m_Nodes[0].Y))
// 				};
// 				_MANAGER.m_RenderWindow.draw(line, 2, sf::Lines);
// 			}
// 		}
// 		for (size_t i = 0; i < _MANAGER.m_Nodes.size(); i++)
// 		{
// 			SHAPES Circle;
// 			_MANAGER._SHAPES.Init(
// 				Circle, 15, _MANAGER.m_Nodes[i].X - 10, 
// 				_MANAGER.m_Nodes[i].Y, 15 >> 1, 15 >> 1);
// 			_MANAGER._SHAPES.Update();
// 			_MANAGER._SHAPES.Render(_MANAGER.m_RenderWindow);
// 		}
// 		for (size_t i = 0; i < _MANAGER.m_Nodes.size(); i++)
// 		{
// 			sf::Text NodeNumber;
// 			NodeNumber.setPosition(_MANAGER.m_Nodes[i].X, _MANAGER.m_Nodes[i].Y);
// 			NodeNumber.setCharacterSize(20);
// 			NodeNumber.setFillColor(sf::Color::White);
// 			NodeNumber.setFont(_MANAGER.m_font);
// 			ostringstream ss;
// 			ss << i;
// 			string s(ss.str());
// 			NodeNumber.setString(s);
// 			_MANAGER.m_RenderWindow.draw(NodeNumber);
// 		}
// 		for (size_t i = 0; i < _MANAGER.m_Agents.size(); i++)
// 		{
// 			sf::Text Stats;
// 			Stats.setPosition(_MANAGER.m_Agents[i].m_Pos.X, _MANAGER.m_Agents[i].m_Pos.Y + 20);
// 			Stats.setCharacterSize(15);
// 			Stats.setFillColor(sf::Color::White);
// 			Stats.setFont(_MANAGER.m_font);
// 			ostringstream ss;
// 			ss << _MANAGER.m_Agents[i].m_Pos.X;
// 			string s(ss.str());
// 			ostringstream ss2;
// 			ss2 << _MANAGER.m_Agents[i].m_Pos.Y;
// 			string s2(ss2.str());
// 			Stats.setString("X: " + s + " Y: " + s2);
// 			
// 			_MANAGER.m_RenderWindow.draw(Stats);
// 		}
//	}
// 	for (size_t i = 0; i < _MANAGER.m_Agents.size(); i++)
// 	{
// 		_MANAGER.m_Agents[i].Update(User, _MANAGER.m_Agents[0].m_Pos);
//       sf::Vertex DirLine[] =
//       {
//         sf::Vertex(sf::Vector2f(
//           _MANAGER.m_Agents[i].m_Pos.X,  _MANAGER.m_Agents[i].m_Pos.Y)),
//         sf::Vertex
//         (
//           sf::Vector2f
//           (
//             (_MANAGER.m_Agents[i].m_Pos.X + _MANAGER.m_Agents[i].m_Dir.X * 100),
//             (_MANAGER.m_Agents[i].m_Pos.Y + _MANAGER.m_Agents[i].m_Dir.Y * 100)
//           ),sf::Color::Magenta
//         )
//       };
//     
//     
//      sf::Vertex SteerLine[] =
//      {
//         sf::Vertex(sf::Vector2f(
//           _MANAGER.m_Agents[i].m_Pos.X,  _MANAGER.m_Agents[i].m_Pos.Y)),
//         sf::Vertex
//         (
//           sf::Vector2f
//           (
//             (_MANAGER.m_Agents[i].m_Pos.X + _MANAGER.m_Agents[i].m_temp_SteeringForce.X * 500),
//             (_MANAGER.m_Agents[i].m_Pos.Y + _MANAGER.m_Agents[i].m_temp_SteeringForce.Y * 500)
//           ), sf::Color::Red
//         )
//       };
//     
//     
//     sf::Vertex RejectionLine[] =
//     {
//       sf::Vertex(sf::Vector2f(
//         _MANAGER.m_Agents[i].m_Pos.X,  _MANAGER.m_Agents[i].m_Pos.Y)),
//       sf::Vertex
//       (
//         sf::Vector2f
//         (
//           (_MANAGER.m_Agents[i].m_Pos.X + _MANAGER.m_Agents[i].m_temp_RejectionForce.X * 3),
//           (_MANAGER.m_Agents[i].m_Pos.Y + _MANAGER.m_Agents[i].m_temp_RejectionForce.Y * 3)
//         ), sf::Color::Blue
//       )
//     };
//     _MANAGER.m_Agents[i].Render(_MANAGER.m_RenderWindow);
//     if (isDebugDir || isDebug)
//       _MANAGER.m_RenderWindow.draw(DirLine, 2, sf::Lines);
//     if (isDebugsteer || isDebug)
//       _MANAGER.m_RenderWindow.draw(SteerLine, 2, sf::Lines);
//     if (isDebugReject || isDebug)
//       _MANAGER.m_RenderWindow.draw(RejectionLine, 2, sf::Lines);
// 	}
// 	t += .2;
// 	_MANAGER.m_RenderWindow.draw(MouseSprite);
}




void EventHandler()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    isDebug = true;
  else
    isDebug = false;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1))
    isDebugDir = true;
  else
    isDebugDir = false;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2))
    isDebugsteer = true;
  else
    isDebugsteer = false;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3))
    isDebugReject = true;
  else
    isDebugReject = false;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
    exit(1);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
  {
    move(g_speed, -1, 0);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
  {
    move(g_speed, 1, 0);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
  {
    move(g_speed, 0, -1);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
  {
    move(g_speed, 0, 1);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::PageUp))
  {
    zoom(1.2);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::PageDown))
  {
    zoom(0.8);
  }
}

int main()
{
//   Vector2 sunPos = { 1000,500 };
//   Vector2 mercuryPor = { 579, 0 };
//   Vector2 venusPos = { 1082, 0 };
//   Vector2 earthPos = { 1496, 0 };
//   Vector2 MarsPos = { 2279, 0 };
//   Vector2 jupiterPos = { 7783, 0 };
 	_MANAGER.initWindow();
  SistemaSolar.Init();
// 	//_MANAGER.Init();
//   /////////////////////////////////////////
//   // Sol
//   PlanetCoords.push_back(sunPos);
//   planetSize.push_back(69.5700f);
//   PlanetColor.push_back(sf::Color(255, 255, 0));
//   /////////////////////////////////////////
//   // Mercurio
//   PlanetCoords.push_back(_MANAGER.Mathlib.Add(sunPos, mercuryPor));
//   planetSize.push_back(.02439f);
//   PlanetColor.push_back(sf::Color(0, 153, 255));
//   /////////////////////////////////////////
//   // Venus
//   PlanetCoords.push_back(_MANAGER.Mathlib.Add(sunPos, venusPos));
//   planetSize.push_back(.06052f);
//   PlanetColor.push_back(sf::Color(255, 102, 0));
//   /////////////////////////////////////////
//   // Tierra
//   PlanetCoords.push_back(_MANAGER.Mathlib.Add(sunPos, earthPos));
//   planetSize.push_back(.06378f);
//   PlanetColor.push_back(sf::Color(51, 204, 51));
//   /////////////////////////////////////////
//   // Marte
//   PlanetCoords.push_back(_MANAGER.Mathlib.Add(sunPos, MarsPos));
//   planetSize.push_back(.03797f);
//   PlanetColor.push_back(sf::Color(255, 0, 0));
//   /////////////////////////////////////////
//   // Jupiter
//   PlanetCoords.push_back(_MANAGER.Mathlib.Add(sunPos, jupiterPos));
//   planetSize.push_back(.71492f);
//   PlanetColor.push_back(sf::Color(255, 204, 0));
  Timer.start();
	float timer = 0;
	//_MANAGER.m_RenderWindow.setFramerateLimit(60);
	while (_MANAGER.m_RenderWindow.isOpen())
	{
		while (_MANAGER.m_RenderWindow.pollEvent(_MANAGER.m_Event))
		{
			if (sf::Event::Closed == _MANAGER.m_Event.type)
			{
				_MANAGER.m_RenderWindow.close();
			}
			if (_MANAGER.m_Event.type == sf::Event::Resized)
			{
				// update the view to the new size of the window
				//sf::FloatRect visibleArea(0, 0, _MANAGER.m_Event.size.width, _MANAGER.m_Event.size.height);
				//_MANAGER.m_RenderWindow.setView(sf::View(visibleArea));
			}
      EventHandler();
		}
		_MANAGER.m_RenderWindow.clear();
	  update();
    int x = sf::Mouse::getPosition(_MANAGER.m_RenderWindow).x;
    int y = sf::Mouse::getPosition(_MANAGER.m_RenderWindow).y;
    //_MANAGER._LEVEL_EDITOR.Init(_MANAGER.m_TEX[0], _MANAGER.m_RenderWindow, BGSprite, BGTex, x, y, "Textures\\track2.png", "NodesDatafile.txt");
    //EditLevel();
		timer += 1;
		_MANAGER.m_RenderWindow.display();
	}
	return 0;
}

void zoom(const float &speed)
{
  for (size_t i = 0; i < PlanetCoords.size(); i++)
  {
    //PlanetCoords[i].X += speed;
    //PlanetCoords[i].Y += speed;
    float sizeAnte = planetSize[i];
    float speedAnte = g_speed;
    float planetCoordx = PlanetCoords[i].X;
    float planetCoordy = PlanetCoords[i].Y;

    planetSize[i] = sizeAnte*speed;
    PlanetCoords[i].X = planetCoordx * speed;
    //PlanetCoords[i].Y = planetCoordy * speed;
    //g_speed = speedAnte * speed;
  }
}
void move(const float &speed, const float &dirX, const float &diry)
{
  for (size_t i = 0; i < PlanetCoords.size(); i++)
  {
    PlanetCoords[i].X += dirX * speed;
    PlanetCoords[i].Y += diry * speed;
  }
}