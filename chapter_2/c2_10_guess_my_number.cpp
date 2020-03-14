// Guess my number
// Угадывание чисел

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	int secret = rand() % 100 + 1; // 1..100
	int tries = 0, guess;

	cout << "\nДобро пожаловать в Угадай число\n\n";

	do
	{
		cout << "Угадайте число: ";
		cin >> guess;

		++tries;

		if(guess > secret)
			cout << "Слишком большое!\n\n";
		else if(guess < secret)
			cout << "Слишком маленькое!\n\n";
		else
			cout << "Это оно! Вы получили его за " << tries << " попыток!\n";

	} while(guess != secret);

	return 0;
}
