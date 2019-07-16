#pragma once
#include "Header.h"
//#include <SFML/Graphics.hpp>
#include "CMathCHK.h"
class CBoid
{
public:
	CBoid();
	~CBoid();
public:
	CMathCHK  Vec2;
  /////////////////////////////////////////
  // Boid Attributes
	Vector2	  m_Dir;
	Vector2   m_Pos;
	Vector2	  m_PF;
	float	    m_aceleration;
	float	    m_mass = 5;
	float     m_velocity;
	sf::Texture Texture;
	sf::Sprite  Sprite;
  /////////////////////////////////////////
  // Prey Attributes
	Vector2   m_preyPos;
	Vector2   m_preyDir;
	float     m_preyVel;
  /////////////////////////////////////////
  // General Variables
	Vector2 wanderpos;
	float	    m_time;
	bool	    b_followPath;
	bool	    b_inPoint;
	bool	    b_follow_arrive = false;	
	int		    follow_pathNum;
	int	      vec2ArrayCount;


	Vector2   m_seekObjetivePos;
	Vector2   follow_pointA;
	Vector2   follow_pointB;
	float     follow_PathRatio;
	float     follow_PointRatio;
	float     follow_Magnitud;

	sf::Text    TextBoids;
	sf::Text    UI;
  sf::Font    font;                                                             //Declare a Font object

	bool isSeek     = false;
	bool isMoveSeek = false;
	bool isFlee		  = false;
	bool isArrive	  = false;
	bool isPersue	  = false;
	bool isEvade	  = false;
	bool isObstacle = false;
	bool isWonder1	= false;
	bool isWonder2	= false;
	bool isWonder3	= false;
	bool isFollow 	= false;
	bool isWalking	= false;
	bool isTracking	= false;
	bool isSeparation	= false;


	int m_currentPoint = 0;
	int m_currentAgent = 0;
	vector<Vector2> m_Nodes;
	vector<CBoid> m_AgentsPos;

  /////////////////////////////////////////
  // Temporal Variables for Debugging
  Vector2   m_temp_SteeringForce;
  Vector2   m_temp_RejectionForce;

public:
	void
  Init
  ( 
    Vector2 Pos, 
    Vector2 Destiny, 
    float Mass, 
    float vel, 
    float color[3],
    string TexPath, 
    vector<Vector2> Nodes
  );
  void
    Destroy();
  void
    Update(Vector2, Vector2 Mario);
  void
    Render(sf::RenderWindow &Wnd);

	Vector2   
  Seek(Vector2  PI, Vector2  PF, float Mag);
	Vector2   
  MoveSeek(Vector2  PI, Vector2  PF, float Mag, float Range, float Time);
	Vector2   
  Flee(Vector2 PI, Vector2 PF, float Mag, float range);
	Vector2   
  Arrive(Vector2 PI, Vector2 PF, float Range, float Magnitude);
	Vector2   
  Pursue(Vector2  PF, Vector2  Dir, Vector2 DO, float Time, float Vel, int Mag);
	Vector2   
  Evade(Vector2 PI, Vector2 PF, Vector2 DO, float Time, float Vel, int Mag);
	Vector2   
  ObstacleAvoidance(Vector2 PI, Vector2 PF, float Mag, float rantio);
	Vector2   
  Wonder1(Vector2 PI, float rangeX, float rangeY, float Mag);
	Vector2   
  Wonder2
  (
    Vector2 PI, 
    Vector2 & Pf, 
    float rangeX, 
    float rangeY, 
    float Mag, 
    float &Time
  );
	Vector2   
  Wonder3(Vector2 PI, Vector2 & Pf, float ratio, float angle, float Mag);
	Vector2   
  PathFinding
  (
    Vector2 PI, 
    Vector2 &PF,
    Vector2 pos, 
    const float pathRatio, 
    float pointRatio,
    float Mag, 
    bool arrivepoin
  );
	Vector2  
  Walking(Vector2 PI, float rangeX, float rangeY, float Mag);
	Vector2   
  NewFollowPath
  (
    Vector2 PIF, 
    float Mag, 
    float nodeRange, 
    float trackRange, 
    vector<Vector2> Nodes
  );
  Vector2 
  Separation(Vector2 PI, Vector2 PF, float Mag, float range);
  Vector2
  FollowTheLeader(Vector2 Leader, float range, int Mag);
};

