#include "SoundEffect.h"

SoundEffect::SoundEffect()
{
	
}

void SoundEffect::Initialize(std::string filename)
{
	buffer.loadFromFile("Ressources/" + filename);
	sfxSound.setBuffer(buffer);
}

void SoundEffect::play()
{
	sfxSound.play();
}