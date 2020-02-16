#pragma once
#include<string>
#include<SDL.h>

class StateGame
{
public:
	bool finish = false;


	virtual void update() = 0;
	virtual void render() = 0;
	virtual bool whenEnter() = 0;
	virtual bool whenExit() = 0;
	virtual std::string getStateID() = 0;
	SDL_Texture* bgTexture;

};

