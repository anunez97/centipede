// Settings

#ifndef _Settings
#define _Settings

class Settings
{
public:
	Settings() = default;
	Settings(Settings& other) = delete;
	Settings& operator=(Settings& other) = delete;
	~Settings() = default;

	static constexpr float CELL_SIZE = 16.0f; // Size of a grid cell ie. CELL_SIZExCELL_SIZE

	static const int NUM_ROWS = 32; // Number of rows in the grid
	static const int NUM_COLS = 30; // Number of columns

	// Player Area Borders
	static const int TROWBORDER = 23;
	static const int BROWBORDER = 30;
	static const int LCOLBORDER = 0;
	static const int RCOLBORDER = 29;

	static const int MUSHROOM_TNATROW = 3; // Highest row a mushroom can naturally spawn
	static const int MUSHROOM_TROW = 1; // Highest row
	static const int MUSHROOM_BROW = 30; // Lowest row

	static const int SPIDER_TBORDER = 20; // Spider area
	static const int SPIDER_BBORDER = 29; // Spider area

	static const int SCORPION_ROW_LIMIT = 12;

	static constexpr float PLAYER_ZONE_SIZE = 7.0f; // Size of the player zone in rows


	static const int FLEA_SPAWN = 0; // Row the flea spawns on
};

#endif _Settings