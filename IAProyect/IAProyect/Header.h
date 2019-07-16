#pragma once
#include <vector>
#include <numeric>
#include <vector>
#include <string>
#include <iostream>
#include <time.h>
#include <chrono>
#include <math.h>
#include <ostream>
#include <iostream>     // std::cout, std::ios
#include <sstream>      // std::ostringstream
#include <fstream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#define Pi 3.141592654 
using namespace std;
struct Vector2
{
	float X = 0.0f;
	float Y = 0.0f;
};

struct SHAPES
{
	sf::CircleShape Circle;
	sf::RectangleShape Rectangle;
	sf::Vertex Line;
};

struct NODE
{
  Vector2 Pos;
  NODE * Next;
  NODE * Prev;
};