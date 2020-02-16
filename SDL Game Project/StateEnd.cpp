#include "StateEnd.h"

StateEnd::StateEnd()
{
	bgTexture = Texture::instance()->loadTexture(Texture::instance()->getPath(BG_1));

	score = 0;
	highScore = new HighScore();
}

StateEnd::StateEnd(int playerPoint)
{
	bgTexture = Texture::instance()->loadTexture(Texture::instance()->getPath(BG_1));

	score = playerPoint;
	highScore = new HighScore();
}



StateEnd::~StateEnd()
{
	delete highScore;
	delete bgTexture;
}


void StateEnd::update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{

		if (event.type == SDL_QUIT) {
			Global::quitGame = true;
			Global::machineState.pop();
			return;
		}
	}
	if (SDL_GetTicks() >= NEXT_TIMER_TICK) {

		Global::machineState.pop();
		Global::machineState.push(new StateMenu());
		return;
	}

}

void StateEnd::render()
{
	SDL_RenderCopy(Global::renderer, bgTexture, NULL, NULL);

	Texture::instance()->textureHeading(Texture::instance()->getPath(TTF_FONT), "Game Over ", 50, 150, 150, Global::colorSelect);
	Texture::instance()->textureHeading(Texture::instance()->getPath(TTF_FONT), "Your Score : ", 36, 150, 250, Global::colorSelect);
	Texture::instance()->textureHeading(Texture::instance()->getPath(TTF_FONT), std::to_string(score).c_str(), 60, 240, 350, Global::colorSelect);
	SDL_RenderPresent(Global::renderer);
}
bool StateEnd::whenEnter()
{
	Sound::soundManager.playSound("end");
	cout << "Entering StateEnd.h \n";
	return true;
}

bool StateEnd::whenExit()
{
	return true;
}

std::string StateEnd::getStateID()
{
	return "StateEnd.h";
}
