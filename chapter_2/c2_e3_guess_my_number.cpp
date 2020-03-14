// Guess my number
// Угадывание чисел

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	int tries = 0, rate_max = 100, rate_min = 1;
	int guess, secret, select, lastnum = 0;

	cout << "\n[CPU] Добро пожаловать в Угадай число\n";
	cout << "\n[CPU] Загадайте число от 1 до 100: ";
	cin >> secret;

	int expr1;
	do
	{
		if(rate_max != rate_min)
			expr1 = rate_max - rate_min;
		else
			expr1 = 1;
			
		guess = rand() % expr1 + rate_min + 1;

		if(guess == lastnum)
			continue;

		cout << "\n\n[CPU] Это " << guess << "?\n\n";

		++tries;

		do
		{
			cout << "1 - Слишком большое!\n";
			cout << "2 - Слишком маленькое!\n";
			cout << "3 - Это оно!\n";
			cin >> select;

			switch(select)
			{
				// число слишком большое или маленькое - отсекаем диапазон
				case 1:
					rate_max = guess - 1;
					break;

				case 2:
					rate_min = guess + 1;
					break;

				case 3:
					break;

				default:
					break;
			}
		} while(!(select >= 1 && select <= 3));

		if(select != 3 && guess == secret)
			cout << "[CPU] Я умею читать ваши мысли...\n";

		if(select == 3)
			break;

		if(tries == 10)
			cout << "\n[CPU] Странно...";

		if(tries == 15)
				cout << "\n[CPU] Что это за число такое?";

		if(tries == 20)
				cout << "\n[CPU] Я такой тупой...";

	} while(guess != secret);
		cout << "[CPU] Ура! Я угадал число за " << tries << " попыток.\n";

	return 0;
}
