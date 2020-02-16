#pragma once
#include <SDL.h>
#include "Vector.h"
#include "Animation.h"
#include "Points.h"
#include <list>


using namespace std;

class Entity
{
protected:
	SDL_Renderer* renderer;


public:

	Vector position;
	Vector velocity;
	Vector acceleration;
	bool active = true;
	int speed;
	void drawMarker(Animation* anim);

	Entity();
	~Entity();
	//friend double applyFriction(double value);
	void setRenderer(SDL_Renderer* renderer);
	void destXY(float x, float y);
	float destX();
	float destY();

	virtual void update(float dt);
	virtual void updateMovement(float dt);
	virtual void draw();
	bool detectHit(int x, int y);
	bool detectHit(int x, int y, int w, int h);



	int width;
	int height;

	virtual std::string getStateID() = 0;

	static list<Entity*> *entities;


};



