// Menu chooser
// enum

#include <iostream>

using namespace std;

int main()
{
	enum difficulty {
		EASY,
		NORMAL,
		HARD,
	};

	int choice;

	cout << "Difficulty levels:\n\n";
	cout << "Easy:   " << EASY << endl;
	cout << "Normal: " << NORMAL << endl;
	cout << "Hard:   " << HARD << endl;

	do
	{
		cout << "\nChoice: ";
		cin >> choice;

		switch(choice)
		{
			case EASY:
				cout << "You picked Easy.\n";
				break;

			case NORMAL:
				cout << "You picked Normal.\n";
				break;

			case HARD:
				cout << "You picked Hard.\n";
				break;

			default:
				cout << "You made an illegal choice.\n";
				break;
		}
	} while(!(choice >= EASY && choice <= HARD));

	return 0;
}
