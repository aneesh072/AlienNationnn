#pragma once
#include<SDL_mixer.h>
#include <string>
#include <list>

using namespace std;


struct SoundListing {
	Mix_Chunk* sound;
	string name;
};

class Sound
{
public:
	list<SoundListing> sounds;

	Sound();
	~Sound();
	void loadSound(string name, string file);
	void playSound(string name);

	static Sound soundManager;


};


