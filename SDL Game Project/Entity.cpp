#include "Entity.h"


void Entity::drawMarker(Animation* anim)
{
	SDL_Rect hitEnemy = { position.x  , position.y  ,width, height };
	anim->draw(hitEnemy);
}

Entity::Entity()
{

}


Entity::~Entity()
{

}

void Entity::setRenderer(SDL_Renderer* renderer) {
	this->renderer = renderer;
}
void Entity::destXY(float x, float y) {
	position.x = x;
	position.y = y;
}
float Entity::destX() {
	return position.x;
}
float Entity::destY() {
	return position.y;
}

void Entity::update(float dt) {

}


void Entity::updateMovement(float dt) {

	velocity.x += (acceleration.x*dt);
	velocity.y += (acceleration.y*dt);

	position.x = position.x + (velocity.x*dt);
	position.y = position.y + (velocity.y*dt);
}


void Entity::draw() {

}

bool Entity::detectHit(int x, int y)
{
	int thisX = position.x;
	int thisY = position.y;
	return (this->active &&	x >= thisX && x <= (thisX + width) && y >= thisY && y <= (thisY + height));
}

bool Entity::detectHit(int x, int y, int w, int h)
{
	Points* thisCenter = new Points(position.x + (width / 2), position.y + (height / 2));
	Points* otherCenter = new Points(x + (w / 2), y + (h / 2));
	int distance = sqrt(pow((otherCenter->x - thisCenter->x), 2) + pow((otherCenter->y - thisCenter->y), 2));
	if (((w / 2) + (width / 2)) > distance || ((h / 2) + (height / 2)) > distance)
		return true;
	else
		return false;
}

list<Entity*>* Entity::entities = NULL;
