#pragma once
#include "StateGame.h"
#include "StateMenu.h"
#include "HighScore.h"
class StateEnd :public StateGame
{
public:
	StateEnd();
	StateEnd(int score);
	~StateEnd();

	SDL_Texture* gameOverTexture;
	Animation* gameOverAnimation;
	int score;
	HighScore* highScore;
	SDL_Rect textPosi;
	SDL_Texture* textTexture;

	Uint32 TIMER_IN_MILLIS = 400;
	Uint32 NEXT_TIMER_TICK = SDL_GetTicks() + TIMER_IN_MILLIS;
	virtual void update();
	virtual void render();
	virtual bool whenEnter();
	virtual bool whenExit();
	virtual std::string getStateID();
};

