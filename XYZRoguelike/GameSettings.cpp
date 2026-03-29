#include "GameSettings.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

// JSON parsing

using json = nlohmann::json;

namespace XYZRoguelike
{
	GameSettings::GameSettings()
	{
		// Initializing calculated values at the first creation
		RecalculateDerivedValues();
	}

	void GameSettings::RecalculateDerivedValues()
	{
		std::cerr << "RecalculateDerivedValues started " << std::endl;
		TEXTURES_PATH = RESOURCES_PATH + "Textures/";
		FONTS_PATH = RESOURCES_PATH + "Fonts/";
		SOUNDS_PATH = RESOURCES_PATH + "Sounds/";

		BLOCK_WIDTH = (SCREEN_WIDTH - (BLOCKS_COUNT_IN_ROW + 1) * BLOCK_SHIFT) / BLOCKS_COUNT_IN_ROW;
	}

	void GameSettings::LoadFromJson(const std::string& filePath)
	{
		std::ifstream file(filePath);
		if (!file.is_open())
		{
			std::cerr << "Warning: Could not open " << filePath << ". Using default C++ settings." << std::endl;
			//RecalculateDerivedValues();
			return;
		}

		try
		{
			json j;
			file >> j;

			// App
			if (j.contains("App")) {
				GAME_NAME = j["App"].value("GameName", GAME_NAME);
				SCREEN_WIDTH = j["App"].value("ScreenWidth", SCREEN_WIDTH);
				SCREEN_HEIGHT = j["App"].value("ScreenHeight", SCREEN_HEIGHT);

				int fps = j["App"].value("Fps", 60);
				if (fps > 0) TIME_PER_FRAME = 1.f / static_cast<float>(fps);
			}

			// Gameplay
			if (j.contains("Gameplay")) {
				ACCELERATION = j["Gameplay"].value("Acceleration", ACCELERATION);
				MAX_APPLES = j["Gameplay"].value("MaxApples", MAX_APPLES);
				BALL_SIZE = j["Gameplay"].value("BallSize", BALL_SIZE);
				BALL_SPEED = j["Gameplay"].value("BallSpeed", BALL_SPEED);
				BREAK_DELAY = j["Gameplay"].value("BreakDelay", BREAK_DELAY);
				BONUS_DURATION = j["Gameplay"].value("BonusDuration", BONUS_DURATION);
				BONUS_PROPABILITY_PERCENT = j["Gameplay"].value("BonusProbabilityPercent", BONUS_PROPABILITY_PERCENT);
			}

			// Platform
			if (j.contains("Platform")) {
				PLATFORM_WIDTH = j["Platform"].value("Width", PLATFORM_WIDTH);
				PLATFORM_HEIGHT = j["Platform"].value("Height", PLATFORM_HEIGHT);
				PLATFORM_SPEED = j["Platform"].value("Speed", PLATFORM_SPEED);
			}

			// Blocks
			if (j.contains("Blocks")) {
				BLOCKS_COUNT_ROWS = j["Blocks"].value("CountRows", BLOCKS_COUNT_ROWS);
				BLOCKS_COUNT_IN_ROW = j["Blocks"].value("CountInRow", BLOCKS_COUNT_IN_ROW);
				BLOCK_SHIFT = j["Blocks"].value("Shift", BLOCK_SHIFT);
				BLOCK_HEIGHT = j["Blocks"].value("Height", BLOCK_HEIGHT);
			}

			// Player
			if (j.contains("Player")) {
				PLAYER_NAME = j["Player"].value("Name", PLAYER_NAME);
				MAX_RECORDS_TABLE_SIZE = j["Player"].value("MaxRecordsTableSize", MAX_RECORDS_TABLE_SIZE);
			}

			// Paths
			if (j.contains("Paths")) {
				RESOURCES_PATH = j["Paths"].value("Resources", RESOURCES_PATH);
				LEVELS_CONFIG_PATH = j["Paths"].value("LevelsConfig", LEVELS_CONFIG_PATH);
			}

			// Recalculating the dependent variables after updating the base ones
			RecalculateDerivedValues();

			std::cout << "Settings successfully loaded from " << filePath << std::endl;
		}
		catch (const json::exception& e)
		{
			std::cerr << "JSON Parsing error in " << filePath << ": " << e.what() << std::endl;
			
		}
	}
}