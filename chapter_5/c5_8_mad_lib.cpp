// Формирует краткую историю на основе польз-го ввода
#include <iostream>
#include <string>

using namespace std;

string ask_text(string prompt);
int ask_number(string prompt);
void tell_story(string name, string noun, int number, string bodypart, string verb);

// ==========================================
int main()
{

	cout << "Welcome to Mad Lib:\n";
	cout << "Answer the following questions to help create a new story.\n";

	string name = ask_text("Please enter a name: ");
	string noun = ask_text("Please enter a plural noun: ");
	int number = ask_number("Please enter a number: ");
	string bodypart = ask_text("Please enter a body part: ");
	string verb = ask_text("Plese enter a verb: ");

	tell_story(name, noun, number, bodypart, verb);

	return 0;
}

// ==========================================
string ask_text(string prompt)
{
	string text;
	cout << prompt;
	cin >> text;

	return text;
}

// ==========================================
int ask_number(string prompt)
{
	int num;
	cout << prompt;
	cin >> num;

	return num;
}

// ==========================================
void tell_story(string name, string noun, int number, string bodypart, string verb)
{
	cout << "\nHere's your story:\n\n";
	cout << "The famous explorer " << name << " had nearly given up a life-long quest to find\n";
	cout << "The Lost City of " << noun << " when one day, the " << noun << " found the explorer.\n";
	cout << "Surrounded by " << number << " " << noun << ", a tear came to " << name << "'s " << bodypart << ".\n";
	cout << "After all this time, the quest was finally over. And then, the " << noun << " promptly devoured " << name << ".\n";
	cout << "The moral of the story? Be careful what you " << verb << " for.\n\n";
}
