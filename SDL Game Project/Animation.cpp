#include "Animation.h"


Animation::Animation()
{

}

Animation::~Animation()
{

}


Animation::Animation(SDL_Texture* texture, SDL_Renderer* renderer, int numberOfFrames, int frameWidth, int frameHeight, float frameDuration) {
	this->spriteSheet = texture;
	this->renderer = renderer;
	this->numberOfFrames = numberOfFrames;
	this->frameWidth = frameWidth;
	this->frameHeight = frameHeight;
	this->frameDuration = frameDuration;

	currentFrame = 0;
	frameTimer = 0;
}
void Animation::update(float dt) {
	
	frameTimer += dt;


	if (frameTimer >= frameDuration) {
	
		currentFrame++;
		
		frameTimer = 0;

		
		if (currentFrame >= numberOfFrames) {
			currentFrame = 0;
		}
	}
}
void Animation::draw(int x, int y) {
	
	SDL_Rect clip;
	clip.x = currentFrame*frameWidth;
	clip.y = 0;
	clip.w = frameWidth;
	clip.h = frameHeight;
	
	SDL_Rect dest = { x, y, frameWidth, frameHeight };
	
	SDL_RenderCopy(renderer, spriteSheet, &clip, &dest);
}
void Animation::draw(int x, int y, float scale) {
	
	SDL_Rect clip;
	clip.x = currentFrame*frameWidth;
	clip.y = 0;
	clip.w = frameWidth;
	clip.h = frameHeight;

	
	SDL_Rect dest = { x, y, frameWidth*scale, frameHeight*scale };

	SDL_RenderCopy(renderer, spriteSheet, &clip, &dest);
}
void Animation::draw(int x, int y, double rotationAngle) {
	
	SDL_Rect clip;
	clip.x = currentFrame*frameWidth;
	clip.y = 0;
	clip.w = frameWidth;
	clip.h = frameHeight;
	
	SDL_Rect dest = { x, y, frameWidth, frameHeight };



	SDL_RenderCopyEx(renderer, spriteSheet, &clip, &dest, rotationAngle, NULL, SDL_FLIP_NONE);
}

void Animation::draw(SDL_Rect rect)
{
	SDL_SetRenderDrawColor(Global::renderer, 255, 255, 0, 255);
	SDL_RenderDrawRect(Global::renderer, &rect);
}

