#pragma once
#include "StateGame.h"
#include <SDL.h>
#include "Global.h"
#include <iostream>
#include "StatePlay.h"
#include "Score.h"
#include "Level.h"

class StateMenu :
	public StateGame
{
public:

	Mix_Music * music;
	int indexSelected = 1;

	StateMenu();
	~StateMenu();

	friend void menuOption(int num);
	virtual void update();
	virtual void render();
	virtual bool whenEnter();
	virtual bool whenExit();
	virtual std::string getStateID();
};

