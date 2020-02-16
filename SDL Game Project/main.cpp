

#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include<SDL_image.h>

#include<stdlib.h>
#include<time.h>
#include<iostream>

#include"Global.h"
#include"StateMenu.h"
#include"AssetManager.h"
#include"Sound.h"
#include"Hero.h"
using namespace std;


int main(int argc, char** argv) {
	srand(time(NULL));

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		cout << "SDL failed: " << SDL_GetError() << endl;
		system("pause");
		return -1;
	}


	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		cout << "SDL image - FAILED: " << IMG_GetError() << endl;
		SDL_Quit();
		system("pause");
		return -1;
	}


	Global::window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN /*| SDL_WINDOW_FULLSCREEN*/);

	if (Global::window != NULL) {
		cout << "Window created!" << endl;
	}
	else
	{
		cout << "Failed to create window!" << endl;
		return -1;
	}

	//create renderer to help draw stuff to the screen
	Global::renderer = SDL_CreateRenderer(Global::window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (Global::renderer != NULL)
	{
		cout << "Renderer created!" << endl;
	}
	else
	{
		cout << "Renderer FAILED!" << endl;
		return -1;
	}
	//destX global game state to reference this renderer for global access

	if (TTF_Init() != 0)
	{
		cout << "Sdl ttf failed: " << TTF_GetError() << endl;
		system("pause");
		SDL_Quit();
		return -1;
	}


	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
		cout << "Mixer error: " << Mix_GetError() << endl;
		SDL_Quit();
		system("pause");
		return -1;
	}



	SDL_Texture* bgTexture = Texture::instance()->loadTexture(Texture::instance()->getPath(BG_1));



	//load sound

	Sound::soundManager.loadSound("laser", SOUND_FIRE);
	Sound::soundManager.loadSound("start", SOUND_START);
	Sound::soundManager.loadSound("die", DEAD_SOUND);
	Sound::soundManager.loadSound("end", SOUND_END);


	Global::machineState.push(new StateMenu());

	bool loop = true;
	while (loop) {

		Global::machineState.update();
		Global::machineState.render();

		if (Global::quitGame || Global::machineState.stateGame.empty())
			loop = false;

		SDL_RenderCopy(Global::renderer, bgTexture, NULL, NULL);

	}

	Global::machineState.clearAll();


	Mix_PausedMusic();


	SDL_DestroyRenderer(Global::renderer);
	SDL_DestroyWindow(Global::window);

	SDL_Quit();

	return 0;
}