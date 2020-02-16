#include "Level.h"



Level::Level()
{
	bgTexture = Texture::instance()->loadTexture(Texture::instance()->getPath(BG_1));
}


Level::~Level()
{
	delete bgTexture;
}



void Level::update()
{



	//gameOverAnimation->draw(WIN_WIDTH / 2 - 50, WIN_HEIGHT / 2 + 300);
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{

		if (event.type == SDL_QUIT) {
			Global::quitGame = true;
			Global::machineState.pop();
			return;
		}
		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
				//exit loop
				Global::machineState.push(new StateMenu());
				return;
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_RETURN) {

				switch (indexSelected) {
				case 1:
				case 2:
					Global::machineState.push(new StatePlay(indexSelected));
					break;
				case 3:
					Global::machineState.push(new StateMenu());
					break;
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




void Level::render()
{
	SDL_RenderCopy(Global::renderer, bgTexture, NULL, NULL);

	menuOption(indexSelected);
	SDL_RenderPresent(Global::renderer);
}

bool Level::whenEnter()
{
	Sound::soundManager.playSound("end");
	cout << "Entering StateEnd.h \n";
	return true;
}

bool Level::whenExit()
{
	return true;
}

std::string Level::getStateID()
{
	return "Level.h";
}
void levelOption(int num) {


	Texture::instance()->textureHeading(Texture::instance()->getPath(TTF_FONT), "Level 1", 55, 300, 170, Global::colorDeselect);
	Texture::instance()->textureHeading(Texture::instance()->getPath(TTF_FONT), "Level 2", 55, 300, 270, Global::colorDeselect);
	Texture::instance()->textureHeading(Texture::instance()->getPath(TTF_FONT), "Exit", 55, 300, 370, Global::colorDeselect);
	switch (num) {
	case 1:
		Texture::instance()->textureHeading(Texture::instance()->getPath(TTF_FONT), "Level One", 55, 300, 170, Global::colorSelect);
		break;
	case 2:
		Texture::instance()->textureHeading(Texture::instance()->getPath(TTF_FONT), "Level Two", 55, 300, 270, Global::colorSelect);
		break;
	case 3:
		Texture::instance()->textureHeading(Texture::instance()->getPath(TTF_FONT), "Exit", 55, 300, 370, Global::colorSelect);
		break;
	}
}