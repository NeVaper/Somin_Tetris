#pragma once

#include <string>
#include <memory>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

#include "json.hpp"

const std::string settingsPath{ "settings.json" };

const std::string initPlayMode{ "Casual" };

const std::string initMusicMode{ "Unmuted" };
const std::string initSoundMode{ "Unmuted" };

const std::vector<std::pair<std::string, std::pair<int, int>>> playModes
// Difficulty - Starting level - Lines before new level
{
	{"Casual", {0 , 20} },
	{"Easy"  , {0 , 4} },
	{"Normal", {10, 6} },
	{"Hard"  , {20, 12} }
};

class Settings
{
public:
	static const std::string getPlayMode();
	static const std::string nextPlayMode();
	static const std::pair<int, int> getPlayDifficulty();

	static const std::string getMusicMode();
	static const std::string muteMusic();
	static const std::string unmuteMusic();
	static const bool isMusicMuted();

	static const std::string getSoundMode();
	static const std::string muteSound();
	static const std::string unmuteSound();
	static const bool isSoundMuted();

	static void setIfMaxScore(int score);
	static int getMaxScore();

	static void setIfMaxLine(int line);
	static int getMaxLine();

	static void setIfMaxLevel(int level);
	static int getMaxLevel();

	static void setIfMaxTimeWithoutI(int timeWithoutI);
	static int getMaxTimeWithoutI();

	Settings(const std::string &path);
	~Settings();

private:
	std::string m_path;

	nlohmann::json m_json;

	static Settings& get() 
	{ 
		static Settings m_settings{ settingsPath };
		return m_settings;
	}

	Settings(Settings const &) = delete;
	void operator=(Settings const &) = delete;
};
