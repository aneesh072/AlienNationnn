#include "StatePlay.h"


StatePlay::StatePlay(int level) {

	levelNumber = level;
	playerPoint = 0;
	highScore = new HighScore();
	Entity::entities = &entities;

	if (levelNumber == 1)
		bgTexture = Texture::instance()->loadTexture(Texture::instance()->getPath(BG_1));
	else
		bgTexture = Texture::instance()->loadTexture(Texture::instance()->getPath(BG_2));

	heroTexture = Texture::instance()->loadTexture(Texture::instance()->getPath(SPRITE_PLAYER));
	heroAnimation = new Animation(heroTexture, Global::renderer, 3, 16, 24, 0.1);

	airMineTexture = Texture::instance()->loadTexture(Texture::instance()->getPath(SPRITE_AIRMINE));
	airMineAnimation = new Animation(airMineTexture, Global::renderer, 3, 17, 16, 0.1);

	enemyTexture = Texture::instance()->loadTexture(Texture::instance()->getPath(ENEMY_SPRITE));
	enemyAnimation = new Animation(enemyTexture, Global::renderer, 1, 30, 30, 0.1);

	hero = new Hero();

	hero->setAnimation(heroAnimation);
	hero->setRenderer(Global::renderer);
	hero->destXY(WIN_WIDTH - 50, WIN_HEIGHT - 100);

	entities.push_back(hero);

	keyboardHandler.hero = hero;
	lastUpdate = SDL_GetTicks();

}

StatePlay::~StatePlay()
{

	SDL_DestroyTexture(heroTexture);
	SDL_DestroyTexture(airMineTexture);
	SDL_DestroyTexture(enemyTexture);
	delete highScore;
	delete hero;
}

void StatePlay::update() {

	//time management
	Uint32 timeDiff = SDL_GetTicks() - lastUpdate;
	dt = timeDiff / 1000.0;
	lastUpdate = SDL_GetTicks();


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
				
			
				Global::machineState.pop(); //which will kill this screen
				Global::machineState.push(new Level());
				return;
			}

		}

		keyboardHandler.update(&event);
	}

	keyboardHandler.updateHeldKeys();



	//managing airMine and enemy rendering depending on time 

	if (SDL_GetTicks() >= NEXT_TIMER_TICK) {
		printf("no of  sdl %d \n", SDL_GetTicks());
		// Gap from left and right 80 px
		int x = (rand() % (WIN_WIDTH - 160)) + 80;
		// airMine start above screen
		int y = -100;
		int animationSelector = rand() % 40;
		AirMine *airMine = new AirMine();
		if (animationSelector < 5) {

			airMine->setAnimation(airMineAnimation);
		}
		else {
			airMine->setAnimation(enemyAnimation);
		}
		airMine->setRenderer(Global::renderer);
		airMine->destXY(x, y);
		entities.push_back(airMine);
		//AirMine::airMine.push(airMine);

		NEXT_TIMER_TICK = SDL_GetTicks() + TIMER_IN_MILLIS;
	}
	//delete entities if they are inactive
	for (auto entity = entities.begin(); entity != entities.end();)
	{
		if ((*entity)->active)
			entity++;
		else
		{
			//not active
			delete *entity;
			entity = entities.erase(entity);
		}
	}

	// removing bullets form list of bullets
	for (auto bullet = hero->bullets.begin(); bullet != hero->bullets.end();)
	{
		if ((*bullet)->active) {
			bullet++;
		}
		else
		{
			//not active
			delete *bullet;
			bullet = hero->bullets.erase(bullet);
		}
	}

	//updating entities
	for (auto entity : entities) {
		if (entity->active)
			entity->update(dt);
	}

	//checking collission and removing entities if they collied
	for (auto entity : entities) {
		if (entity->getStateID() == "airMine") {
			AirMine*  airMine = (AirMine*)entity;
			for (auto bullet = hero->bullets.begin(); bullet != hero->bullets.end();) {
				if ((*bullet)->active && airMine->detectHit((*bullet)->position.x, (*bullet)->position.y))
				{
					Sound::soundManager.playSound("explode");
					if (levelNumber == 1)
						playerPoint += 10;
					else
						playerPoint += 15;

					(*bullet)->active = false;
					airMine->active = false;
				}
				bullet++;
			}

			if (hero->active && airMine->detectHit(hero->position.x, hero->position.y, hero->width, hero->height)) {

				airMine->active = false;
				hero->active = false;
				highScore->setHighScore(playerPoint);
				//creating death animation
				deathTexture = Texture::instance()->loadTexture(Texture::instance()->getPath(DEAD));
				deathAnimation = new Animation(deathTexture, Global::renderer, 1, 15, 15, 0.1);
				Hero* dhero = new Hero();
				dhero->setAnimation(deathAnimation);
				dhero->setRenderer(Global::renderer);
				dhero->destXY(airMine->position.x, airMine->position.y);
				entities.push_back(dhero);
				Sound::soundManager.playSound("die");
				render();
				SDL_Delay(2000);
				Global::machineState.push(new StateEnd(playerPoint));
			}

		}
	}


}



void StatePlay::render() {
	SDL_RenderCopy(Global::renderer, bgTexture, NULL, NULL);
	for (auto entity : entities) {
		entity->draw();
	}

	Texture::instance()->textureHeading(Texture::instance()->getPath(TTF_FONT), "Score : ", 30, 400, 15, Global::colorSelect);
	Texture::instance()->textureHeading(Texture::instance()->getPath(TTF_FONT), std::to_string(playerPoint).c_str(), 30, 420, 50, Global::colorSelect);
	SDL_RenderPresent(Global::renderer);

}

bool StatePlay::whenEnter() {
	Sound::soundManager.playSound("start");
	cout << "Enter state gameplay" << endl;
	return true;
}

bool StatePlay::whenExit() {
	cout << "Exit state Gameplay" << endl;
	return true;
}

std::string StatePlay::getStateID() {
	return "playState";
}
