// Score Rater
// Условия

#include <iostream>

using namespace std;

int main()
{
	if(true)
		cout << "This is always displayed.\n";
	
	if(false)
		cout << "This is never displayed.\n";
	
	int score = 1000;
	
	if(score)
		cout << "At least you didn't score zero.\n";
	
	if(score >= 250)
		cout << "Your score 250 or more. Decent.\n";
	
	if(score >= 500)
	{
		cout << "Your score 500 or more. Nice.\n";
		
		if(score >= 1000)
			cout << "You scored 1000 or more. Impressive!\n";
	}
	
	return 0;
}