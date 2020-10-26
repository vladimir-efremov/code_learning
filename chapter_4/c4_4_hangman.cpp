// Hangman
// Игра виселица
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main()
{
	const int MAX_WRONG = 8; // макс. доп-е кол-во ошибок
	vector<string> words;
	
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");
	words.push_back("OBJECT");
	words.push_back("PLAYER");
	
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	
	const string THE_WORD = words[0]; // слово для отгадывания
	
	int user_wrong = 0;
	string so_far(THE_WORD.size(), '-');
	string used = "";
	
	// ====================================
	cout << "Welcome to Hangman. Good luck!\n";
	
	char guess;
	
	// ====================================
	while((user_wrong < MAX_WRONG) && (so_far != THE_WORD))
	{
		cout << "\n\nYou have " << (MAX_WRONG - user_wrong) << " incorrect guesses left.";
		cout << "\nYou've used the following letters:" << used << endl;
		cout << "\nSo far. The word is: " << so_far << endl;
	
		cout << "\nEnter your guess: ";
		cin >> guess;
		
		guess = toupper(guess);
		
		while(used.find(guess) != string::npos)
		{
			cout << "\nYou've already guessed " << guess << endl;
			cout << "Enter your guess: ";
			cin >> guess;
			guess = toupper(guess);
		}
		
		used += guess;
		
		if(THE_WORD.find(guess) != string::npos)
		{
			cout << "That's right! " << guess << " is in the word.\n";
			for(int i=0; i<THE_WORD.length(); ++i)
			{
				if(THE_WORD[i] == guess)
					so_far[i] = guess;
			}
		} else {
			cout << "Sorry. " << guess << " isn't in the word.\n";
			++user_wrong;
		}
	}
	
	if(user_wrong == MAX_WRONG)
		cout << "\nYou've been hanged!";
	
	else
		cout << "\nYou guessed it!";
	
	cout << "\nThe word was " << THE_WORD << endl;
		
	return 0;
}
