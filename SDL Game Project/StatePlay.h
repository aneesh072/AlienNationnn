#pragma once
#include <list>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "StateGame.h"
#include "Global.h"
#include <iostream>
#include "Hero.h"
#include <stdlib.h>
#include "Texture.h"
#include "AirMine.h"
#include "StateMenu.h"
#include "StateEnd.h"
#include "HighScore.h"
#include "KeyboardHandler.h"

class StatePlay :
	public StateGame
{
public:
	SDL_Texture* airMineTexture;
	SDL_Texture* heroTexture;
	Animation* heroAnimation;
	Animation* airMineAnimation;
	Hero* hero;
	HighScore* highScore;
	Animation* enemyAnimation;
	SDL_Texture* enemyTexture;
	
	Bullet* bullet;
	int playerPoint;

	SDL_Texture* textTexture;
	SDL_Rect textPosi;
	SDL_Color textColor;
	TTF_Font* font;
	Animation* deathAnimation;
	SDL_Texture* deathTexture;
	

	list<Entity*> entities;


	KeyboardHandler keyboardHandler;

	//TIME STUFF
	Uint32 lastUpdate; //last sdl_ticks
	float dt;//time since last update

	Uint32 TIMER_IN_MILLIS = 3000;
	Uint32 NEXT_TIMER_TICK = SDL_GetTicks() + TIMER_IN_MILLIS;
	int levelNumber;

	StatePlay(int level);
	~StatePlay();

	virtual void update();
	virtual void render();
	virtual bool whenEnter();
	virtual bool whenExit();
	virtual std::string getStateID();
};

