#pragma once
#include "Entity.h"
#include "Global.h"
#include "AssetManager.h"
#include "Animation.h"
#include <cmath>

class Bullet : public Entity
{
public:

	Animation* animation;
	Bullet();
	~Bullet();

	const int bulletSpeed = 5;


	void setAnimation(Animation* animation);
	void update(float dt);
	void draw();

	virtual std::string getStateID();
};

