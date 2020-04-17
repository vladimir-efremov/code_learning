// Word jumble
// Головоломка "словомеска"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	enum fields {WORD, HINT, NUM_FIELDS};
	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS][NUM_FIELDS] = {
		{"wall", "Do you feel you're banging your head against something?"},
		{"glasses", "These might help you see the answer."},
		{"labored", "Going slowly, is it?"},
		{"persistent", "Keep at it."},
		{"jumble", "It's what the game is all about."}
	};
	
	// ==================================
	srand(static_cast<unsigned int>(time(0)));
	
	int choice = rand() % NUM_WORDS;
	
	string word = WORDS[choice][WORD];
	string hint = WORDS[choice][HINT];
	
	// ==================================
	string jumble = word;
	int length = jumble.size();
	
	int index1, index2;
	char tmp;
	// ==================================
	for(int i=0; i<length; ++i)
	{
		index1 = rand() % length;
		index2 = rand() % length;
		
		tmp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = tmp;
	}
	
	// ==================================
	cout << "\t\tWelcome to Word Jumble!\n\n";
	cout << "Unscramble the letters to make a word.\n";
	cout << "Enter 'hint' for a hint.\n";
	cout << "Enter 'quit' to quit the game.\n\n";
	cout << "The Jumble is: " << jumble;
	
	string guess;
	
	cout << "\n\nYour guess: ";
	cin >> guess;
	
	// ==================================
	while((guess != word) && (guess != "quit"))
	{
		if(guess == "hint")
			cout << hint;
		else
			cout << "Sorry, that's not it.";
		
		cout << "\n\nYour guess: ";
		cin >> guess;
	}
	
	if(guess == word)
		cout << "\nThat's it! You guessed it!\n";
	
	cout << "Thanks for playing.\n";
	
	// ==================================
	// ==================================
	// ==================================
	
	return 0;
}
