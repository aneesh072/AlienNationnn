#include "Texture.h"


Texture* Texture::textureInst = NULL;


Texture::Texture()
{
}


Texture::~Texture()
{
	SDL_DestroyTexture(texture);
	texture = NULL;


}
std::string Texture::getPoint(int score)
{
	return("Score : " + score);
}
std::string Texture::getStateID()
{
	return std::string();
}
Texture * Texture::instance()
{
	if (textureInst == NULL) {
		textureInst = new Texture();
	}
	return textureInst;
}
SDL_Texture * Texture::loadTexture(std::string path)
{

	texture = NULL;
	surface = IMG_Load(path.c_str());
	//SDL_Surface* background = SDL_LoadBMP("assets/background1.bmp");
	if (surface == NULL) {
		std::cout << "Loading image - FAILED: " << IMG_GetError() << std::endl;
		return texture;
	}


	texture = SDL_CreateTextureFromSurface(Global::renderer, surface);

	if (texture == NULL) {
		std::cout << "Create texture - FAILED: " << SDL_GetError() << std::endl;
		return texture;
	}
	SDL_FreeSurface(surface);
	return texture;
}
void Texture::textureHeading(std::string path, std::string text, int size, int x, int y, SDL_Color color)
{
	
	TTF_Font* font = TTF_OpenFont(path.c_str(), size);

	
	SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
	if (surface == NULL) {
		std::cout << "Render text - FAILED: " << IMG_GetError() << std::endl;
	}
	texture = SDL_CreateTextureFromSurface(Global::renderer, surface);
	if (texture == NULL) {
		std::cout << "Texture create  - FAILED: " << SDL_GetError() << std::endl;
	}
	SDL_FreeSurface(surface);

	//text destination
	SDL_Rect textPosi;
	textPosi.x = x;
	textPosi.y = y;

	SDL_QueryTexture(texture, NULL, NULL, &textPosi.w, &textPosi.h);
	SDL_RenderCopy(Global::renderer, texture, NULL, &textPosi);

}

std::string Texture::getPath(std::string path)
{
	std::string assetPath = SDL_GetBasePath();
	assetPath.append(path);
	return assetPath;
}