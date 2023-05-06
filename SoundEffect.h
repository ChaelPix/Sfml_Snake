#pragma once
#include <SFML/Audio.hpp>
#include <iostream>

class SoundEffect
{
	private :
		sf::SoundBuffer buffer;
		sf::Sound sfxSound;

public :
	SoundEffect();

	void Initialize(std::string filename);

	void play();
};

