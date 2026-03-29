#pragma once
#include <string>

namespace XYZRoguelike
{
	class GameSettings {
	private:
		GameSettings();

	public:
		static GameSettings& Instance() {
			static GameSettings gameWorld;
			return gameWorld;
		}

		// Json upload method
		void LoadFromJson(const std::string& filePath);
		
		// Метод для перерасчета зависимых переменных (пути, BLOCK_WIDTH и т.д.)
		void RecalculateDerivedValues();

		// Resources path
		std::string RESOURCES_PATH = "Resources/";
		std::string TEXTURES_PATH;
		std::string FONTS_PATH;
		std::string SOUNDS_PATH;
		std::string LEVELS_CONFIG_PATH = "Resources/levels.config";

		// Game settings constants
		float ACCELERATION = 10.f;
		int MAX_APPLES = 80;
		////////////////////////////////////////////////
		// Resources path
		std::string PLAYER_TEXTURES_PATH = "Resources/TextureMaps/Player.png";

		std::string LEVELFLOOR_TEXTURES_PATH = "Resources/TextureMaps/Floor.png";
		std::string LEVELWALL_TEXTURES_PATH = "Resources/TextureMaps/Wall.png";
		// Sounds
		std::string MUSIC_PATH = "Resources/Music/Music.ogg";
		// Screen Settings
		unsigned int SCREEN_WIDTH = 1280;
		unsigned int SCREEN_HEIGHT = 720;
		/////////////////////////////////////////////////



		float TIME_PER_FRAME; // Вычисляется из FPS

		unsigned int BALL_SIZE = 20;
		unsigned int BALL_SPEED = 400;

		unsigned int PLATFORM_WIDTH = 60;
		unsigned int PLATFORM_HEIGHT = 20;
		float PLATFORM_SPEED = 300.f;

		unsigned int BLOCKS_COUNT_ROWS = 4;
		unsigned int BLOCKS_COUNT_IN_ROW = 15;
		unsigned int BLOCK_SHIFT = 5;
		unsigned int BLOCK_WIDTH; // Вычисляется
		unsigned int BLOCK_HEIGHT = 20;

		int MAX_RECORDS_TABLE_SIZE = 5;
		std::string PLAYER_NAME = "Player"; // Заменили const char* на std::string

		std::string GAME_NAME = "ArkanoidGame";
		float BREAK_DELAY = 1.f;
		float BONUS_DURATION = 30.f;
		int BONUS_PROPABILITY_PERCENT = 5;
	};
}

#define SETTINGS XYZRoguelike::GameSettings::Instance()