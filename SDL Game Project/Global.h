#pragma once

#include <SDL.h>
#include"MachineState.h"


class Global
{
public:
	Global();
	~Global();

	static SDL_Color colorSelect;
	static SDL_Color colorDeselect;
	static SDL_Texture* bgTexture;
	static SDL_Window* window;
	static SDL_Renderer* renderer;
	static bool quitGame;

	static MachineState machineState;
	static bool isDebug;

};


