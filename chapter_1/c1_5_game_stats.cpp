// Game stats
// переменные

#include <iostream>

using namespace std;


int main()
{
	int score;
	double distance;
	char play_again;
	bool shields_up;
	short lives, aliens_killed;
	
	score = 0;
	distance = 1200.76;
	play_again = 'y';
	shields_up = true;
	lives = 3;
	aliens_killed = 10;
	
	double engine_temp = 6572.89;
	
	cout << "\nScore: " << score << endl;
	cout << "Distance: " << distance << endl;
	cout << "Play again: " << play_again << endl;
	
	cout << "Lives: " << lives << endl;
	cout << "Aliens killed: " << aliens_killed << endl;
	cout << "Engine temperature: " << engine_temp << endl;
	
	int fuel;
	
	cout << "\nHow much fuel? ";
	cin >> fuel;
	cout << "Fuel: " << fuel << endl;
	
	typedef unsigned short int ushort;
	ushort bonus = 10;
	
	cout << "Bonus: " << bonus << endl;
	
	return 0;
}