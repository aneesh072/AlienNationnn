#include "Score.h"



Score::Score()
{
	bgTexture = Texture::instance()->loadTexture(Texture::instance()->getPath(BG_1));

	highScore = new HighScore();
}


Score::~Score()
{
	delete highScore;
	delete bgTexture;
}

void Score::update()
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
			//see if ESC key was pressed
			if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {

				Global::machineState.pop(); //which will kill this screen
				Global::machineState.push(new StateMenu());
				return;
			}
		}


	}

}

void Score::render()
{
	SDL_RenderCopy(Global::renderer, bgTexture, NULL, NULL);
	int * scores = highScore->getHighScores();
	int yOfText = 150;
	Texture::instance()->textureHeading(Texture::instance()->getPath(TTF_FONT), "Scores : ", 50, 160, 50, Global::colorSelect);
	for (int i = 0; i <= 5; i++) {
		string score = std::to_string(*(scores + i));
		Texture::instance()->textureHeading(Texture::instance()->getPath(TTF_FONT), (score).c_str(), 50, 250, yOfText, Global::colorSelect);
		yOfText += 50;
	}
	SDL_RenderPresent(Global::renderer);
}

bool Score::whenEnter()
{
	Mix_Music*  music = Mix_LoadMUS(SOUND_INTRO);
	Mix_PlayMusic(music, -1);
	cout << "Entering StateEnd.h \n";
	return true;
}

bool Score::whenExit()
{
	return true;
}

std::string Score::getStateID()
{
	return "score";
}
