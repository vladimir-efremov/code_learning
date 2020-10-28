// Referencing
// Демонстрация работы со ссылками
#include <iostream>

using namespace std;

int main()
{
	int score = 1000;
	int &r_score = score;

	cout << "Score: " << score << endl;
	cout << "&Score: " << r_score << "\n\n";

	// ----------------------------
	cout << "Adding 500 to Score\n";

	score += 500;
	cout << "Score: " << score << endl;
	cout << "&Score: " << r_score << "\n\n";

	// ----------------------------
	cout << "Adding 500 to &Score\n";

	r_score += 500;
	cout << "Score: " << score << endl;
	cout << "&Score: " << r_score << "\n\n";

	return 0;
}
