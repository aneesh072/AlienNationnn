#include "Vector.h"


Vector::Vector()
{
	x = 0;
	y = 0;
}


Vector::Vector(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector Vector::minus(Vector other)
{
	Vector n;
	n.x = x - other.x;
	n.y = y - other.y;

	return n;
}

float Vector::magni()
{
	return sqrt(pow(x, 2) + pow(y, 2));
}


Vector Vector::setAngle(float radians)
{
	Vector vector = *this;

	vector.x = cos(radians) * 50;
	vector.y = sin(radians) * 50;

	return vector;
}
