// Designers network
// использование логических операторов

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string username, password;
	bool success;

	cout << "\tGame designer's network\n";

	do {
		cout << "\nUsername: ";
		cin >> username;

		cout << "Password: ";
		cin >> password;

		if(username == "S.Meier" && password == "civilization")
		{
			cout << "\nHey, Sid.\n";
			success = true;
		} else if(username == "S.Miyamoto" && password == "mariobros")
		{
			cout << "\nWhat's up, Shigeru?\n";
			success = true;
		} else if(username == "W.Wright" && password == "thesims")
		{
			cout << "\nHow goes it, Will?\n";
			success = true;
		} else if(username == "guest" && password == "guest")
		{
			cout << "\nWelcome, guest.\n";
			success = true;
		} else
		{
			cout << "\nYour login failed.\n";
			success = false;
		}

	} while(!success);

	return 0;
}
