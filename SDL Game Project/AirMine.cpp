#include "AirMine.h"

AirMine::AirMine()
{



	speed = rand() % 2 + 5;


}

AirMine::~AirMine()
{
}

void AirMine::setAnimation(Animation* animation) {
	this->animation = animation;
	height = this->animation->frameHeight;
	width = this->animation->frameWidth;
}

void AirMine::update(float dt) {
	if (active) {

		if (position.y > WIN_HEIGHT + 100)
		{
			active = false;

		}

		position.y += speed;
		updateMovement(dt);
	}
}

void AirMine::draw() {
	if (active) {

		animation->draw(position.x, position.y);
		//draw hitbox
		if (Global::isDebug)
			drawMarker(animation);
	}
}

std::string AirMine::getStateID()
{
	return "airMine";
}




AirMine AirMine::airMine;

