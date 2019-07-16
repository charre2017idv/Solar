#include "CMathCHK.h"



CMathCHK::CMathCHK()
{
}


CMathCHK::~CMathCHK()
{
}


int CMathCHK::Dot(Vector2 A, Vector2 B)
{
	int result = (A.X * B.X);
	result += (A.Y * B.Y);
	return result;
}

float CMathCHK::Mag(Vector2 A)
{
	float result = CuadMag(A);
	if (result <= 0)
	{
		return 0;
	}
	//float result = pow(A.A, 2) + pow(A.B, 2);
	result = sqrt(result);
	return result;
}

float CMathCHK::CuadMag(Vector2 A)
{
	float result = (A.X * A.X) + (A.Y * A.Y);
	if (result <= 0)
	{
		return 0.0f;
		
	}
	return result;
}

Vector2 
CMathCHK::Projection(Vector2 _of, Vector2 _onto, Vector2 prevNode)
{
  Vector2 normal_onto = Norm(_onto);

  normal_onto = mul(normal_onto, Dot(_of, normal_onto));

  return Add(prevNode, normal_onto);
}

Vector2 CMathCHK::Sub(Vector2 A, Vector2 B)
{
	Vector2 result;
	result.X = (A.X - (B.X));
	result.Y = (A.Y - (B.Y));
	return result;
}

Vector2  CMathCHK::Add(Vector2  A, Vector2 B)
{
	Vector2 result;
	result.X = (A.X + B.X);
	result.Y = (A.Y + B.Y);
	return result;
}

Vector2 CMathCHK::mul(Vector2 A, float B)
{
	Vector2 result;
	result.X = A.X * B;
	result.Y = A.Y * B;
	return result;
}

Vector2 CMathCHK::subByNo(Vector2 A, float B)
{
	Vector2 result;
	result.X = A.X - B;
	result.Y = A.Y - B;
	return result;
}

float CMathCHK::xLerp(float x)
{
	int s = 1, pot = 3, den = 0;
	float n, num = 1, sum;

	n = Pi * x / 180;
	sum = n;

	for (int i = 0; i < 4; i++)
	{
		den *= pot * (pot - 1);
		sum += (num / den) * s;
		s *= -1;
		num *= n * n;
		pot += 2;
	}
	return sum;
}

Vector2  CMathCHK::Norm(Vector2  A)
{
	Vector2  result;
  float M = Mag(A);
	if (M <= 0)
	{
		return A;
	}
		result.X = A.X / M;
		result.Y = A.Y / M;
	
	return result;
}
