#include "Hero.h"



Hero::Hero()
{
	animation = NULL;
	this->score = getPoint();

}


Hero::~Hero()
{

}

void Hero::setAnimation(Animation* animation) {
	this->animation = animation;
	height = this->animation->frameHeight;
	width = this->animation->frameWidth;
}


void Hero::shoot() {

	Bullet* bullet = new Bullet();
	bullet->setRenderer(Global::renderer);
	bullet->destXY(position.x + bolletOnX, position.y + bolletOnY);

	bullets.push_back(bullet);

	Sound::soundManager.playSound("laser");

}

void Hero::update(float dt) {

	for (auto bullet = bullets.begin(); bullet != bullets.end(); bullet++)
	{

		if ((*bullet)->position.y < -100)
		{
			(*bullet)->active = false;

		}
		else {
			(*bullet)->update(dt);

		}

	}
}

void Hero::draw() {
	if (active) {
		animation->draw(position.x, position.y);

		for (auto bullet : bullets) {

			bullet->draw();
		}
		if (Global::isDebug)
			drawMarker(animation);

	}

}

Hero Hero::hero;


std::string Hero::getStateID()
{
	return "hero";
}
void Hero::setPoint(int score)
{
	this->score = score;
	fout.open(highScoreFile);
	fout << score;
	fout.close();
}

int Hero::getPoint(void)
{
	fin.open(highScoreFile);
	fin >> score;
	fin.close();
	return score;
}