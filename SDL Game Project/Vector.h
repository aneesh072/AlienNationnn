#pragma once
#include <math.h>

class Vector
{
public:

	float x, y;

	Vector();
	Vector(float x, float y);
	float speedMove;
	float angle;
	

	Vector setAngle(float radians);
	float magni();
	Vector minus(Vector other);
	
	
};


