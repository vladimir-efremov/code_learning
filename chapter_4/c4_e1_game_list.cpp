/* Воспользуйтесь векторами и итераторами и напишите программу, позволяющую пользователю
вести список любимых игр. В этой программе у пользователя должны быть такие возможности:
перечислить заголовки всех игр, добавить заголовок игры, удалить заголовок игры.
*/
// Обработки от ошибок типов ввода непредусмотрено (когда вместо числа вводится символ)
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

int main()
{
	vector<string> games;
	
	vector<string>::iterator iter;
	
	string header = "===============================\n\
	*** Commands ***\n\
	[a] Add game\n\
	[d] Delete game\n\
	[l] List games\n\
	[e] Exit program\n\
===============================\n";
	
	string commands = "adle";
	
	string command_input;
	string game_title;

	int count, iter_input;
	
	cout << header;
	
	while(true)
	{
		cout << "\n> ";
		cin >> command_input;
		// command_input = toupper(command_input);
		
		// cout << "command_input = " << command_input << endl;
		
		if(commands.find(command_input) != string::npos)
		{
			// cout << "ui = " << command_input << endl;
			// выход
			if(command_input == "e")
				break;
				
			// ----------------------------------
			if(command_input == "a")
			{
			
				cout << "New title: ";
				// cin >> game_title;
				cin.ignore();
				getline(cin, game_title);
				
				// cout << "[" << game_title << "]\n";
				games.push_back(game_title);
				continue;
			}
			
			// ----------------------------------
			if(command_input == "d")
			{
				cout << "Select number of game: ";
				cin >> iter_input;
				
				if(iter_input < 1 || iter_input > 16)
				{
					cout << "Wrong number.\n";
					continue;
				}
				
				iter_input--;
				
				if(iter_input < games.size())
				{
					games.erase((games.begin() + iter_input));
					
				} else {
					cout << "Wrong number.\n";
				}
				
				
				continue;
			}
				
			// ----------------------------------
			if(command_input == "l")
			{
				if(games.empty())
				{
					cout << "Your favorite list is empty.\n";
					continue;
				}
				
				cout << "*** Your favorite list:\n\n";
				
				count = 0;
				for(iter = games.begin(); iter < games.end(); ++iter)
				{
					cout << "[" << count+1 << "]" << " " << *iter << endl;
					count++;
				}
				continue;
			}
			// ----------------------------------
		} else {
			cout << header;
		}
	}
	
		
	return 0;
}
