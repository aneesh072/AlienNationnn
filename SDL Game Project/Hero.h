#pragma once
#include "Entity.h"
#include "Animation.h"
#include "Bullet.h"
#include "AssetManager.h"
#include "Texture.h"
#include "Sound.h"

#include<stdlib.h>
#include <list>
#include<math.h>
#include <fstream>

class Hero : public Entity
{
private:
	Animation* animation;
	SDL_Event* event;
	int score;
	ofstream fout;
	ifstream fin;

public:
	Hero();
	~Hero();

	void setAnimation(Animation* animation);

	void shoot();
	void setPoint(int);
	int getPoint(void);

	int bolletOnX = 5;
	int bolletOnY = -25;
	virtual void update(float dt);
	virtual void draw();
	virtual std::string getStateID();
	list<Bullet* > bullets;
	static Hero hero;
};

