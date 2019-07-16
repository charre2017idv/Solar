#include "CBoid.h"



CBoid::CBoid()
{
}


CBoid::~CBoid()
{
}



void CBoid::Init(Vector2 Pos, Vector2 Destiny, float Mass, float vel, float color[3], string TexPath, vector<Vector2> Nodes)
{
	m_Dir = { 0,-1 };
	// Initialize Position
	m_Pos = Pos;
	// Initialize Destiny
	m_PF = Destiny;
	// Initialize Velocity
	m_velocity = vel;
	// Initialize Weight
	m_mass = Mass;
	// Initialize Behavior
	m_Nodes = Nodes;
  // Initialize Agents Vector
 // m_AgentsPos = AgentsPos;
	// Initialize Texture
	if (!Texture.loadFromFile(TexPath))
	{
		cout << "Error de carga de textura" << endl;
	}
	// Initialize Sprite
	Sprite.setTexture(Texture);
	sf::Vector2u sizes = Sprite.getTexture()->getSize();
	int width  = sizes.x >> 1;
	int height = sizes.y >> 1;
	Sprite.setOrigin(width, height);
	Sprite.setScale(1, 1);
	// Initialize Font and text
	TextBoids.setOrigin(45, 45);
	TextBoids.setCharacterSize(20);
	TextBoids.setFillColor(sf::Color::White);

	//UI.setOrigin(45, 45);
	UI.setCharacterSize(20);
	UI.setFillColor(sf::Color::White);

	if (!font.loadFromFile("accid__.ttf"))
	{
		cout << "can't load font" << endl;
	}
}

void 
CBoid::Update(Vector2 PF, Vector2 Mario)
{
	Vector2 SteeringForce;

	if (isSeek)
	{
		SteeringForce = Vec2.Add(SteeringForce, Seek(m_Pos, PF,3.0f));
	}
	if (isFlee)
	{
		SteeringForce = Vec2.Add(SteeringForce, Flee(m_Pos, PF, 50,100));
	}
	if (isArrive)
	{
		SteeringForce = Vec2.Add(SteeringForce, Arrive(m_Pos, PF, 100, 2));
	}
	if (isPersue)
	{
		SteeringForce = Vec2.Add(SteeringForce, Pursue(m_Pos,m_preyPos,m_preyDir,.5f,m_preyVel,5));
	}
	if (isEvade)
	{
		SteeringForce = Vec2.Add(SteeringForce, Evade(m_Pos, m_preyPos, m_preyDir, .1f, m_preyVel, 5));
	}
	if (isObstacle)
	{
		SteeringForce = Vec2.Add(SteeringForce, ObstacleAvoidance(m_Pos, m_preyPos,5.0f,50.0f));
	}
	if (isWonder1)
	{
		SteeringForce = Vec2.Add(SteeringForce, Wonder1(m_Pos,500,500,5.0f));
	}
	if (isWonder2)
	{
		SteeringForce = Vec2.Add(SteeringForce, Wonder2(m_Pos,wanderpos, 500, 500, 20.0f, m_time));
	}
	if (isWonder3)
	{
		SteeringForce = Vec2.Add(SteeringForce, Wonder3(m_Pos, PF, 50, 50, 5.0f));
	}
	if (isFollow)
	{
		SteeringForce = Vec2.Add(SteeringForce, PathFinding(follow_pointA, follow_pointB, m_Pos, follow_PathRatio,follow_PointRatio,follow_Magnitud, b_follow_arrive));
	}
	if (isMoveSeek)
	{
		SteeringForce = Vec2.Add(SteeringForce, MoveSeek(m_Pos, PF, 5.0f,200,m_time));
	}
	if (isWalking)
	{
		SteeringForce = Vec2.Add(SteeringForce, Walking(m_Pos, 500, 500, 1.0f));
	}
	if (isTracking)
	{
		SteeringForce = Vec2.Add(SteeringForce, NewFollowPath(m_Pos, 5.0f, 50, 20, m_Nodes));
	}
  if (isSeparation)
  {
      SteeringForce = Vec2.Add(SteeringForce, Separation(m_Pos, Mario, 5, 100));
  }

  /////////////////////////////////////////
  // Force Data

  float force_mag = Vec2.Mag(SteeringForce);

  /////////////////////////////////////////
  // Direction re-calculation

  SteeringForce = Vec2.mul(SteeringForce, 1 / m_mass);
  m_temp_SteeringForce = SteeringForce;
  
  m_Dir = Vec2.Add(m_Dir, SteeringForce);
  m_Dir = Vec2.Norm(m_Dir);
  /*
	// 1) Restar el steering Force - Direccion
	Vector2 SteeringDirection = Vec2.Sub(SteeringForce, m_Dir );
	// 2) Al resultado del steering force multiplicaar por la masa
	Vector2 newSteeringDirection = Vec2.mul(SteeringForce, m_mass);
	// 3) Sumar la direccion + newSteeringDirection
	Vector2 newDirection = Vec2.Add(m_Dir, newSteeringDirection);
	// 4) Normalizo la nueva direccion calculada
	Vector2 NormNDirection = Vec2.Norm(newDirection);
	// 5) Multiplico por la magnitud de la steering force por mi direccion normalizada
	float MagSteerForce = Vec2.Mag(SteeringForce);
	Vector2 finalDir = Vec2.mul(NormNDirection, MagSteerForce);
	// 6) Mando mi nueva direccion
	Vector2 NormFinalDir = Vec2.Norm(finalDir);
	m_Dir = NormFinalDir;
  */

  /////////////////////////////////////////
  // Physics Calculations

  Vector2 speed_force = Vec2.mul(m_Dir, m_velocity);
  m_Pos = Vec2.Add(speed_force, m_Pos);

  return;
}

void CBoid::Render(sf::RenderWindow &Wnd)
{ 
	Sprite.setPosition(m_Pos.X, m_Pos.Y);
	
  // UI
  TextBoids.setFont(font);
	UI.setFont(font);
	ostringstream ss;
	ss << m_Pos.X;
	string s(ss.str());

	ostringstream ss2;
	ss2 << m_Nodes.size();
	string s2(ss2.str());

	TextBoids.setPosition(m_Pos.X, m_Pos.Y);
	//UI.setString("Nodos : " + s2);
	//UI.setPosition(750,10);
	//Wnd.draw(UI);
	Wnd.draw(Sprite);
	Wnd.draw(TextBoids);
}

Vector2 CBoid::Seek(Vector2 PI, Vector2 PF, float Mag)
{
	//Text.setString("Seek");


	Vector2 m_Dir = Vec2.Sub(PF, PI);
	m_Dir = Vec2.Norm(m_Dir);
	m_Dir.X *= Mag;
	m_Dir.Y *= Mag;
	return m_Dir;
}

Vector2 CBoid::Flee(Vector2 PI, Vector2 PF, float Mag, float range)
{
	TextBoids.setString("Flee");
	Vector2 m_Dir = Vec2.Sub(PF, PI);

	float MagDir = Vec2.Mag(m_Dir);

	if (MagDir < range)
	{
		Vector2 normVec = Vec2.Norm(m_Dir);

		normVec.X *= -Mag;
		normVec.Y *= -Mag;
		return normVec;
	}
	else
	{
		Vector2 Zero = { 0,0 };
		return Zero;
	}
}

Vector2 CBoid::Arrive(Vector2 PI, Vector2 PF, float Range, float Mag)
{

	Vector2 VecToTarget = Vec2.Sub(PF, PI);
	float DistToTarget = Vec2.Mag(VecToTarget);
	
	if (DistToTarget <= Range)
	{
		TextBoids.setString("Arrive");
		float d = DistToTarget / Range;
		d *= Mag;
		
		return Seek(PI, PF, d);
	}
	else
	{
		TextBoids.setString("Seek");
		return Seek(PI, PF, Mag);
	}
  }

Vector2 CBoid::Pursue(Vector2 PI, Vector2 PF, Vector2 DO, float Time, float Vel, int Mag)
{
	TextBoids.setString("Pursue");

	Vector2 Dir ;
	Vector2 PP;
	Vector2 F;

	float Dist;
	float PPDist;

	PP = Vec2.mul(DO, Time*Vel);
	PP = Vec2.Add(PP, PF);
	//PP = Vec2.Sub(PP, PI);
	PPDist = Vec2.Mag(Vec2.Sub(PP, PI));
	Dir = Vec2.Sub(PF, PI);
	Dist = Vec2.Mag(Dir);

	if (Dist < PPDist)
	{
		PP = Vec2.mul(DO, Dist);
		PP = Vec2.Add(PP, PF);
	}

	F = Seek(PI, PP, Mag);
	return F;
}

Vector2 CBoid::Evade(Vector2 PI, Vector2 PF, Vector2 DO, float Time, float Vel, int Mag)
{
	TextBoids.setString("Evade");

	Vector2 Dir;
	Vector2 PP;
	Vector2 F;

	float Dist;
	float PPDist;

	PP = Vec2.mul(DO, Time*Vel);
	PP = Vec2.Add(PP, PF);
	//PP = Vec2.Sub(PP, PI);
	PPDist = Vec2.Mag(Vec2.Sub(PP, PI));
	Dir = Vec2.Sub(PF, PI);
	Dist = Vec2.Mag(Dir);

	if (Dist < PPDist)
	{
		//PP = Vec2.mul(DO, Dist);
		//PP = Vec2.Add(PP, PF);
		Vector2 result;
		result = Vec2.Norm(PP);
		Dir = Vec2.Norm(Dir);
		result = Vec2.Add(result,Dir);
		PP = result;
	}

	F = Flee(PI, PP, Mag,30);
	return F;
}

Vector2 CBoid::ObstacleAvoidance(Vector2 PI, Vector2 PF, float Mag, float rantio)
{

	Vector2 Dir;
	Vector2 F = { 0,0 };
	Dir = Vec2.Sub(PF, PI);
	float Dist = Vec2.Mag(Dir);
	if (Dist < rantio)
	{
		TextBoids.setString("Obstacle Avoidance");
		F = Flee(PI, PF, Mag * 100, rantio);
	}
	return F;

	//return Vector2();
}

Vector2 CBoid::Wonder1(Vector2 PI, float rangeX, float rangeY, float Mag)
{
	srand(time(NULL));
	float x = ((float)rand() / (float)RAND_MAX)*rangeX; // Genera una posicion aleatoria entre 0 y el numero flotante.
	float y = ((float)rand() / (float)RAND_MAX)*rangeY; // Genera una posicion aleatoria entre 0 y el numero flotante.

	Vector2 wonderPos = { x,y };

	return Seek(PI, wonderPos, Mag);
}

Vector2 CBoid::Wonder2(Vector2 PI, Vector2 & Pf, float rangeX, float rangeY, float Mag, float &Time)
{
	
	if (Time >= 3)
	{
		Time = 0;
		//srand(time(NULL));
		float x = ((float)rand() / (float)RAND_MAX)*rangeX; // Genera una posicion aleatoria entre 0 y el numero flotante.
		//srand(time(NULL));
		float y = ((float)rand() / (float)RAND_MAX)*rangeY; // Genera una posicion aleatoria entre 0 y el numero flotante.
		Pf = { x,y };

	}
	return Seek(PI, Pf, Mag);

	return Vector2();
}

Vector2 CBoid::Wonder3(Vector2 PI, Vector2 & PF, float ratio, float angle, float Mag)
{
	TextBoids.setString("Wonder 3");

	Vector2 F;
	Vector2 PP;
	Vector2 Plane = { 1,0 };
	Vector2 Dir = Vec2.Sub(PF, PI);
	PP = PF;
	float Dist = Vec2.Mag(Dir);
	Dir = Vec2.Norm(Dir);
	if (Dist>ratio)
	{
		float midAngle = angle / 2;
		float tetha = acos(((Vec2.Dot(Dir, Plane)) / (Vec2.Mag(Dir)*Vec2.Mag(Plane))));
		float randAngle = ((float)rand() / (float)RAND_MAX) * angle;
		randAngle -= midAngle;
		float randPoint = randAngle + tetha + ratio;
		float Coss = cos(randPoint)+ tetha + ratio;
		float Sinn = sin(randPoint)+ tetha + ratio;
		PP.X += Coss;
		PP.Y += Sinn;
	}
	F = Seek(PI, PP, Mag);

	return F;
}

Vector2 CBoid::PathFinding(Vector2 PI, Vector2 &PF, Vector2 pos, const float pathRatio, float pointRatio, float Mag, bool arrivepoint)
{
	Vector2 F;

	F = Seek(pos, PF, Mag);
	float vecX;
	float minX;
	float maxX;
	float vecY;
	float minY;
	float maxY;
	if (PI.X < PF.X)
	{
		minX = PI.X;
		maxX = PF.X;
	}
	else
	{
		minX = PF.X;
		maxX = PI.X;
	}
	if (PI.Y < PF.Y)
	{
		minY = PI.Y;
		maxY = PF.Y;
	}
	else
	{
		minY = PF.Y;
		maxY = PI.Y;
	}
	int resultx = 0;
	int resulty = -1;
	for (int x = minX; x < maxX; x++)
	{
		for (int y = minY; y < maxY; y++)
		{
			vecX = (x*x) + ((-PI.X - pos.X)*x) + (-PI.X * -pos.X);
			vecY = (y*y) + ((-PI.Y - pos.Y)*y) + (-PI.Y * -pos.Y);
			resultx = x;
			resulty = y;
			if (vecX == -vecY)
			{
				break;
			}
		}
		if (vecX == -vecY)
		{
			break;
		}
	}
	Vector2 PP = { resultx, resulty };
	Vector2 dir = PP;
	dir = Vec2.Sub(dir, pos);
	float dist = Vec2.Mag(dir);
	if (dist > pathRatio)
	{
		F = Vec2.Add(F, Seek(pos, PP, Mag * 4));
	}
	dir = PF;
	dir = Vec2.Sub(dir, pos);
	dist = Vec2.Mag(dir);
	if (dist <= pointRatio)
	{
		arrivepoint = true;
	}
	else
	{
		arrivepoint = false;
	}
	return F;

}

Vector2 CBoid::MoveSeek(Vector2 PI, Vector2 PF, float Mag, float Range, float Time)
{
	Vector2 m_Dir = Vec2.Sub(PF, PI);

	float MagDir = Vec2.Mag(m_Dir);

	if (MagDir < Range)
	{
		TextBoids.setString("Seek");

		isWalking = false;
		Sprite.setColor(sf::Color::Red);
		return Seek(PI, PF, Mag);
	}
	else
	{
		TextBoids.setString("Walking");

		Vector2 Zero = { 0,0 };
		Sprite.setColor(sf::Color::Blue);
		//Zero.A = sin(Time);
		//Zero.B = sin(Time);
		isWalking = true;
		return Zero;
	}
}

Vector2 CBoid::Walking(Vector2 PI, float rangeX, float rangeY, float Mag)
{
	srand(time(NULL));
	float x = ((float)rand() / (float)RAND_MAX)*rangeX;							              // Genera una posicion aleatoria entre 0 y el numero flotante.
	float y = ((float)rand() / (float)RAND_MAX)*rangeY;							              // Genera una posicion aleatoria entre 0 y el numero flotante.

	Vector2 wonderPos = { x,y };

	return Seek(PI, wonderPos, Mag);
}

Vector2 CBoid::NewFollowPath(Vector2 PI, float Mag, float nodeRange, float trackRange, vector<Vector2> Nodes)
{
	Vector2 VecToTarget = Vec2.Sub(Nodes[m_currentPoint], PI);                    // Dir vector
	float DistToTarget = Vec2.Mag(VecToTarget);                                   // Mag of  Dir vector
    
	Vector2 Zero = { 0,0 };                                                       // A Default Vector in Zero
  if (m_currentPoint >= Nodes.size() - 1)                           
    m_currentPoint = 0;

  if (DistToTarget <= nodeRange)                                                // Check if target is in range of node
  { 
    m_currentPoint++;                                                           // Change the Node
    return Seek(PI, Nodes[m_currentPoint], Mag);
  }

  Vector2 P;
  Vector2 V;
  Vector2 Q;	

  if (m_currentPoint == 0)
  {
    P = Vec2.Sub(Nodes[m_currentPoint], Nodes[Nodes.size() - 2]);               // Calculate the vector path of the line
    V = Vec2.Sub(PI, Nodes[Nodes.size() - 2]);                                  // Calculate the dir between the pos and the past node
    Q = Vec2.Projection(V, P, Nodes[Nodes.size() - 2]);                         // Calculate the projection that generates the new point pos
  }
  else
  {
    P = Vec2.Sub(Nodes[m_currentPoint], Nodes[m_currentPoint - 1]);         
    V = Vec2.Sub(PI, Nodes[m_currentPoint - 1]);
    Q = Vec2.Projection(V, P, Nodes[m_currentPoint - 1]);
  }

  // attraction force

  Vector2 F = Vec2.Sub(Q, PI);                                                  // Calculate the rejection of the end - start
  m_temp_RejectionForce = Vec2.mul(Vec2.Norm(F), Vec2.Mag(F));                  // Pass the  rejection vector
 

  TextBoids.setString("Seek");

  if (Vec2.Mag(F) > trackRange)
  {
                                                                                // Seek to rejected point
    return Vec2.Add(
      Seek(PI, Nodes[m_currentPoint], Mag), 
      Vec2.mul(Vec2.Norm(F), Vec2.Mag(F) * .01f));
  }
  else
    return Vec2.Add(Seek(PI, Nodes[m_currentPoint], Mag), Zero); 

}

Vector2 CBoid::Separation(Vector2 PI, Vector2 PF, float Mag, float range)
{
  Vector2 m_Dir = Vec2.Sub(PF, PI);

  float MagDir = Vec2.Mag(m_Dir);

  if (MagDir < range)
  {
    Vector2 normVec = Vec2.Norm(m_Dir);

    normVec.X *= -Mag;
    normVec.Y *= -Mag;
    return normVec;
  }
  else
  {
    Vector2 Zero = { 0,0 };
    return Zero;
  }
}
