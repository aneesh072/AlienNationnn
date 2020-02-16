#pragma once
#include "Entity.h"
#include "Global.h"
#include "Animation.h"
#include "AssetManager.h"
#include<stdlib.h>


class AirMine : public Entity
{
public:

	Animation* animation;


	AirMine();
	~AirMine();
	void setAnimation(Animation* animation);
	void update(float dt);
	void draw();
	virtual std::string getStateID();

	list<AirMine*> airMines;
	static AirMine airMine;


};