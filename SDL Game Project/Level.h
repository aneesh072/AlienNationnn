#pragma once

#include "StateMenu.h"
class Level :public StateGame
{
public:
	Level();
	~Level();
	virtual void update();
	virtual void render();
	virtual bool whenEnter();
	virtual bool whenExit();
	virtual std::string getStateID();
	friend void levelOption(int num);

	int indexSelected = 1;
};

