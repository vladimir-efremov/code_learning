// Die roller
// ГСЧ

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	// запуск
	int randomnum = rand();

	int die = (randomnum % 6) + 1;
	cout << "You rolled a " << die << endl;

	return 0;
}
