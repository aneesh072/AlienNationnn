#pragma once
#include "StateGame.h"
#include "StateMenu.h"
#include "HighScore.h"
class Score :
	public StateGame
{
public:
	Score();
	~Score();



	HighScore* highScore;
	virtual void update();
	virtual void render();
	virtual bool whenEnter();
	virtual bool whenExit();
	virtual std::string getStateID();
};

