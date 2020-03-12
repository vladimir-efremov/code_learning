// Play again 2.0
// do while

#include <iostream>

using namespace std;

int main()
{
		
	char again = 'y';
	
	do
	{
		cout << "\n**Played an exciting game**";
		cout << "\nDo yo want to play again? (y/n): ";
	
		cin >> again;
	} while(again == 'y');
	
	cout << "\nOkay, bye.";	
		
	return 0;
}