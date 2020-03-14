// sum score
// Средняя сумма очков за 3 попытки

#include <iostream>

using std::cout;
using std::cin;
using std::endl;


int main()
{
	int score = 0, tmp;
	
	cout << "Sum of score 1: ";
	cin >> tmp;
	score = tmp;
	
	cout << "Sum of score 2: ";
	cin >> tmp;
	score += tmp;
	
	cout << "Sum of score 3: ";
	cin >> tmp;
	score += tmp;
	
	cout << "\nAverage score: " << score / 3 << endl;
	
	return 0;
}