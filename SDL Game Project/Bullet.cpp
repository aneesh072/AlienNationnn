#include "Bullet.h"

Bullet::Bullet()
{
	animation = NULL;
	active = true;

}


Bullet::~Bullet()
{
}

void Bullet::setAnimation(Animation* animation) {
	this->animation = animation;

}


void Bullet::update(float dt) {
	if (active) {
		position.y -= bulletSpeed;
		updateMovement(dt);
	}
}

void Bullet::draw() {
	if (active) {
		SDL_SetRenderDrawColor(Global::renderer, 255, 51, 153, 0);
		SDL_Rect bulletRect = { position.x  , position.y , 4, 20 };
		SDL_RenderFillRect(Global::renderer, &bulletRect);
		if (Global::isDebug)
			drawMarker(animation);
	}
}


std::string Bullet::getStateID()
{
	return "bullet";
}
