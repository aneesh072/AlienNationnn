#pragma once

#include<iostream>
#include<SDL.h>
#include<SDL_ttf.h>
#include<SDL_image.h>
#include "Global.h"
#include "AssetManager.h"
#include "Hero.h"
class Texture : public Entity
{
public:

	static Texture* textureInst;
	static Texture* instance();
	SDL_Texture* texture;

	SDL_Surface* surface;
	std::string path;

	SDL_Texture * loadTexture(std::string path);
	void textureHeading(std::string path, std::string text, int size, int x, int y, SDL_Color color);

	std::string getPath(std::string path);
	std::string getPoint(int Score);

	virtual std::string getStateID();

private:
	Texture();
	~Texture();

};

