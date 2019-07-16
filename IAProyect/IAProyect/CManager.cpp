#include "CManager.h"



CManager::CManager()
{
}


CManager::~CManager()
{
}

void CManager::Init()
{
  /////////////////////////////////////////
  // Texts
	m_Textos.push_back(_TEXT1);													// Allocate Hot Key 1 Text in vector
	m_Textos.push_back(_TEXT2);													// Allocate Hot Key 2 Text in vector
	m_Textos.push_back(_TEXT3);													// Allocate Hot Key 3 Text in vector
  /////////////////////////////////////////
  // Textures
	m_TEX.push_back(_TEX1);
	m_TEX.push_back(_TEX2);
  /////////////////////////////////////////
  // Node
  readNodesfromFile();

	m_Nodes.push_back(DefaultTrackNode);
  cout << "-----------------------------------" << endl;
  cout << "Track Nodes initialized." << endl;
  /////////////////////////////////////////
  // Agents
	m_Agents.push_back(Mario);
	m_Agents.push_back(Luigi);
	m_Agents.push_back(Kong);
	m_Agents.push_back(Toad);
	m_Agents.push_back(Yoshi);
  cout << "-----------------------------------" << endl;
  cout << "Agents are initialized." << endl;
	/* Initialize Agents */
	MousePos.X = m_Event.mouseMove.x;
	MousePos.Y = m_Event.mouseMove.y;
  //	Positions.push_back(KongPos);
  // Mario
	m_Agents[0].Init
  (
    MarioPos, 
    m_Agents[2].m_Pos,
    55.0f, 
    4.8f, 
    Color1, 
    "Textures\\Mario.png",
    m_Nodes
  );
	m_Agents[0].isTracking = true;
	m_Agents[0].isFlee = true;
  cout << "-----------------------------------" << endl;
  cout << "Agent 0 (Mario) is initialized." << endl;
  // Luigi
	m_Agents[1].Init
  (
    LuigiPos, 
    MousePos,
    50.0f, 
    5.0f, 
    Color2, 
    "Textures\\Luigi.png", 
    m_Nodes
  );
	m_Agents[1].isTracking = true;
	m_Agents[1].isFlee = true;
	//m_Agents[1].isSeparation = true;
  cout << "-----------------------------------" << endl;
  cout << "Agent 1 (Luigi) is initialized." << endl;
  // Kong
  m_Agents[2].Init
  (
    KongPos,
    defaultpos,
    80.0f, 
    4.2f, 
    Color3, 
    "Textures\\kong.png",
    m_Nodes
  );
	m_Agents[2].isTracking = true;
	//m_Agents[2].isSeparation = true;
  cout << "-----------------------------------" << endl;
  cout << "Agent 2 (Kong) is initialized." << endl;
  // Toad 
	m_Agents[3].Init
  (
    ToadPos,
    MousePos, 
    60.0f, 
    4.5f, 
    Color3, 
    "Textures\\Toad.png", 
    m_Nodes
  );
	m_Agents[3].isTracking = true;
	m_Agents[3].isFlee = true;
	//m_Agents[3].isSeparation = true;
  cout << "-----------------------------------" << endl;
  cout << "Agent 3 (Toad) is initialized." << endl;
  // Yoshi
	m_Agents[4].Init
  (
    YoshiPos,
    defaultpos,
    50.0f, 
    5.0f, 
    Color3,
    "Textures\\Yoshi.png", 
    m_Nodes
  );
	m_Agents[4].isTracking = true;
	m_Agents[4].isFlee = true;
	//m_Agents[4].isSeparation = true;
  cout << "-----------------------------------" << endl;
  cout << "Agent 4 (Yoshi) is initialized." << endl;
	/////////////////////////////////////////
	// Load Font
	if (!m_font.loadFromFile("accid__.ttf"))
		cout << "can't load font" << endl;
  else
  {
    cout << "-----------------------------------" << endl;
    cout << "Font is loaded." << endl;
  }
	
}

void CManager::initWindow()
{
	m_RenderWindow.create(
		sf::VideoMode(1920, 1080),
		"Steering Behaviors");
  cout << "-----------------------------------" << endl;
	cout << "InitWindow() is initialized." << endl;
  sf::Vector2u size = { 400,400 };
  m_RenderWindow.setSize(size);
}

void CManager::readNodesfromFile()
{
  ifstream File("NodesDatafile.txt");
  while (!File.eof()) 
  {
    // Read File
    File >> cadena;
    // Allocate Data from file 
    m_DataFromFile.push_back(cadena);
  }
  File.close();
  for (size_t i = 0; i < m_DataFromFile.size(); i++)
  {
    // If temp vector its different from 0
    if (m_Temp_Coord.X != 0 && m_Temp_Coord.Y != 0)
    {
      // Save the coords in vector
      m_Nodes.push_back(m_Temp_Coord);
      m_Temp_Coord = m_Zero; // Restart the Vector2
    }
    // If the index equal to token ':' in vector
    if (m_DataFromFile[i + 1] == ":")
    {
      m_Temp_Coord.X = stof(m_DataFromFile[i]); // Allocate in X position the Number
    }
    // If the vector is empty, end the loop
    if (m_DataFromFile[i + 1] == "")
    {
      cout << "-----------------------------------" << endl;
      cout << "readNodesfromFile() is initialized." << endl;
      break;
    }
    // If the index equal to token '@' in vector
    if (m_DataFromFile[i + 1] == "@")
    {
      m_Temp_Coord.Y = stof(m_DataFromFile[i]); // Allocate in Y position the Number
    }
  }
}
