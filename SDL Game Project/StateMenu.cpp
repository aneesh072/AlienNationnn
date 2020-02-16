#include "StateMenu.h"
#include "Texture.h"
#include "StatePlay.h"


StateMenu::StateMenu()
{
	bgTexture = Texture::instance()->loadTexture(Texture::instance()->getPath(BG_1));
}


StateMenu::~StateMenu()
{

	delete bgTexture;
}


void StateMenu::update() {

	SDL_Event event;
	//int score = Hero::hero.getPoint();
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT) {
			//exit our loop,
			Global::quitGame = true;
			Global::machineState.pop();
			return;

		}
		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
				//exit loop
				Global::quitGame = true;
				Global::machineState.pop();
				return;
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_RETURN) {
				Mix_FreeMusic(music);
				switch (indexSelected) {
				case 1:
					Global::machineState.push(new Level());
					break;
				case 2:
					Global::machineState.push(new Score());
					break;
				case 3:
					Global::quitGame = true;
					Global::machineState.pop();
					return;
				}
			}

			if (event.key.keysym.scancode == SDL_SCANCODE_UP) {
				indexSelected--;
				if (indexSelected <= 0) {
					indexSelected = 3;
				}
			}

			if (event.key.keysym.scancode == SDL_SCANCODE_DOWN) {
				indexSelected++;
				if (indexSelected > 3) {
					indexSelected = 1;
				}
			}
		}
	}



}
void StateMenu::render() {
	SDL_RenderCopy(Global::renderer, bgTexture, NULL, NULL);
	Texture::instance()->textureHeading(Texture::instance()->getPath(TTF_FONT), "Alien Nation", 60, 80, 50, Global::colorSelect);
	menuOption(indexSelected);
	SDL_RenderPresent(Global::renderer);

}
bool StateMenu::whenEnter() {

	music = Mix_LoadMUS(SOUND_INTRO);
	Mix_PlayMusic(music, -1);
	std::cout << "Entering stare menu" << std::endl;
	return true;

}
bool StateMenu::whenExit() {

	std::cout << "Exiting state menu" << std::endl;
	return true;
}
std::string StateMenu::getStateID() {
	return "menuState";
}

void menuOption(int num) {


	Texture::instance()->textureHeading(Texture::instance()->getPath(TTF_FONT), "Play", 45, 230, 370, Global::colorDeselect);
	Texture::instance()->textureHeading(Texture::instance()->getPath(TTF_FONT), "Score", 45, 230, 470, Global::colorDeselect);
	Texture::instance()->textureHeading(Texture::instance()->getPath(TTF_FONT), "Exit", 45, 230, 570, Global::colorDeselect);
	switch (num) {
	case 1:
		Texture::instance()->textureHeading(Texture::instance()->getPath(TTF_FONT), "Play", 45, 230, 370, Global::colorSelect);
		break;
	case 2:
		Texture::instance()->textureHeading(Texture::instance()->getPath(TTF_FONT), "Score", 45, 230, 470, Global::colorSelect);
		break;
	case 3:
		Texture::instance()->textureHeading(Texture::instance()->getPath(TTF_FONT), "Exit", 45, 230, 570, Global::colorSelect);
		break;
	}
}