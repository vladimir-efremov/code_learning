// Hangman
// Игра виселица
#include <iostream>
#include <string>

using namespace std;

// ======================================
int get_user_number(string prompt="Enter a number: ")
{
	int user_number = 0;

	cout << prompt;
	cin >> user_number;

	return user_number;
}

// ======================================
int get_user_number2()
{
	int user_number = 0;

	cout << "Enter a number: ";
	cin >> user_number;

	return user_number;
}

int get_user_number2(string prompt)
{
	int user_number = 0;

	cout << prompt;
	cin >> user_number;

	return user_number;
}
// ======================================
int main()
{
	int user_input = 0;
	user_input = get_user_number();
	user_input = get_user_number("Enter a another number: ");

	// с перегрузкой
	user_input = get_user_number2();
	user_input = get_user_number2("Enter a another number: ");

	cout << endl;

	return 0;
}
