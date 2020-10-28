// Swap
// Демонстрация передачи ссылок для изменения переменных-аргументов
#include <iostream>

using namespace std;

void bad_swap(int x, int y);
void good_swap(int &x, int &y);

// ==============================
int main()
{
	int my_score = 100;
	int your_score = 2500;

	cout << "Original scores:\n";
	cout << "My score:   " << my_score << endl;
	cout << "Your score: " << your_score << endl;

	// ----------------------------------
	cout << "\nCalling bad_swap()\n";
	bad_swap(my_score, your_score);

	cout << "My score:   " << my_score << endl;
	cout << "Your score: " << your_score << endl;

	// ----------------------------------
	cout << "\nCalling good_swap()\n";
	good_swap(my_score, your_score);

	cout << "My score:   " << my_score << endl;
	cout << "Your score: " << your_score << endl;

	return 0;
}

// ==============================
void bad_swap(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}

// ==============================
void good_swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}
