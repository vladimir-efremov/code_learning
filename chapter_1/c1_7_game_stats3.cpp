// Game stats 3.0
// константы

#include <iostream>

using namespace std;


int main()
{
	const int ALIEN_POINTS = 150;
	int aliens_killed = 10;
	int score = aliens_killed * ALIEN_POINTS;
	
	cout << "Score: " << score << endl;
	
	enum difficulty {
		NOVICE,
		EASY,
		NORMAL,
		HARD,
		UNBEATABLE
	};
	
	difficulty myDifficulty = EASY;
	
	enum ship_cost {
		FIGHTER_COST = 25,
		BOMBER_COST,
		CRUISER_COST = 50
	};
	
	ship_cost myShipCost = BOMBER_COST;
	
	cout << "\nTo upgrade my ship to a Cruiser will cost " << (CRUISER_COST - myShipCost) << " resource points.\n";
	
	return 0;
}