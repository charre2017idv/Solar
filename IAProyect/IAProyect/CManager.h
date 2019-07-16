#pragma once
#include "Header.h"
#include "CMathCHK.h"
#include "CBoid.h"
#include "CShapes.h"
#include "CText.h"
#include "CTexture.h"
#include "CLevelEditor.h"
class CManager
{
public:
	CManager();
	~CManager();
public:
	CMathCHK	    			Mathlib;
	sf::RenderWindow		m_RenderWindow;
	sf::Event				    m_Event;
	vector<CBoid>			  m_Agents;
	vector<Vector2>			m_objetives;
	vector<Vector2>			m_Nodes;
	CShapes					    _SHAPES;
	vector<CTexture>		m_TEX;
	vector<sf::Text>		Texts;
	vector<CText>			  m_Textos;
  CLevelEditor        _LEVEL_EDITOR;
	
	Vector2 m_Zero = { 0,0 };
	/* Node for track */
	Vector2 DefaultTrackNode = { 0,-100 };

  /////////////////////////////////////////
  // Track Nodes
  NODE _NODE;
	/* This is a single line comment */
	vector <Vector2> Positions;
	float Color1[3] = { 0,255,0 };
	float Color2[3] = { 102,0,204 };
	float Color3[3] = { 0, 226, 255 };
	/////////////////////////////////////////
	// Agents
	CBoid Mario;
	CBoid Luigi;
	CBoid Kong;
	CBoid Toad;
	CBoid Yoshi;
  vector<CBoid> m_AgentsVec;
  /////////////////////////////////////////
  // Text 
	CText _TEXT1;
	CText _TEXT2;
	CText _TEXT3;
	sf::Text HotKey1;
	sf::Text HotKey2;
	sf::Text HotKey3;
  /////////////////////////////////////////
  // Textures
	CTexture _TEX1;
	CTexture _TEX2;
	
	Vector2 MousePos;
  /////////////////////////////////////////
  // Agents Position
	Vector2 defaultpos = { 900,300 };
	Vector2 MarioPos = { 904,500 };
	Vector2 LuigiPos = { 904,450 };
	Vector2 ToadPos = { 904,550 };
	Vector2 YoshiPos = { 904,585 };
	Vector2 KongPos = { 940,480 };
	/* This is a single line comment */
	sf::Font m_font;
  /////////////////////////////////////////
  // Read Nodes from file
  char            cadena[128];
  vector<string>  m_DataFromFile;
  Vector2         m_Temp_Coord;
public:
	void 
  Init();
	void 
  initWindow();
	void 
  Destroy();
	void 
  Update();
  void 
  readNodesfromFile();
};

