#pragma once
#include "Header.h"
class CMathCHK
{
public:
	CMathCHK();
	~CMathCHK();
public:
	float A;
	float B;
public:

	int Dot(Vector2, Vector2);
	float Mag(Vector2);
	float CuadMag(Vector2);
	Vector2 Norm(Vector2);

  Vector2 Projection(Vector2, Vector2, Vector2);
	Vector2 Sub(Vector2, Vector2);
	Vector2 Add(Vector2, Vector2);
	Vector2 mul(Vector2, float);
	Vector2 subByNo(Vector2, float);

	float xLerp(float x);
};

