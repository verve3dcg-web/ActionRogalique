// ©2023, XYZ School. All rights reserved.
// Authored by Aleksandr Rybalka (polterageist@gmail.com)

#include <SFML/Graphics.hpp>
//#include "Player.h"
#include "Engine.h"
#include "ResourceSystem.h"
#include "DeveloperLevel.h"
//#include "Matrix2D.h"
#include "GameSettings.h"

using namespace XYZRoguelike;

int main()
{
	SETTINGS.LoadFromJson("settings.json");// Loading from the JSON configuration of the game
	
	XYZEngine::RenderSystem::Instance()->SetMainWindow(new sf::RenderWindow(sf::VideoMode(SETTINGS.SCREEN_WIDTH, SETTINGS.SCREEN_HEIGHT), "XYZRoguelike"));

	ResourceSystem::Instance()->LoadTextureMap("player", SETTINGS.PLAYER_TEXTURES_PATH, { 48, 63 }, 4, false);
	ResourceSystem::Instance()->LoadTextureMap("AI", SETTINGS.PLAYER_TEXTURES_PATH, { 48, 63 }, 4, false);
	ResourceSystem::Instance()->LoadTextureMap("level_floors", SETTINGS.LEVELFLOOR_TEXTURES_PATH, { 16, 16 }, 49, false);
	ResourceSystem::Instance()->LoadTextureMap("level_walls", SETTINGS.LEVELWALL_TEXTURES_PATH, { 16, 16 }, 48, false);

	ResourceSystem::Instance()->LoadSound("music", SETTINGS.MUSIC_PATH);

	auto developerLevel = std::make_shared<DeveloperLevel>();
	developerLevel->Start();

	XYZEngine::Engine::Instance()->Run();

	return 0;
}
