// Hero's inventory
// Работа с массивами
#include <iostream>
#include <string>

using namespace std;

int main()
{
	const int MAX_ITEMS = 10;
	string inventory[MAX_ITEMS];
	int num_items = 0;
	
	inventory[num_items++] = "sword";
	inventory[num_items++] = "armor";
	inventory[num_items++] = "shield";
	
	// ===================================
	cout << "You items:\n";
	for(int i=0; i<num_items; ++i)
		cout << inventory[i] << endl;
	
	// ==================================
	cout << "\nYou trade your sword for a battle axe.\n";
	
	inventory[0] = "battle axe";
	
	// ===================================
	cout << "You items:\n";
	for(int i=0; i<num_items; ++i)
		cout << inventory[i] << endl;
	
	// ==================================
	cout << "\nThe item name '" << inventory[0] << "' has " << inventory[0].size() << " letters in it.\n";
	
	cout << "\nYou find a healing potion.\n";
	
	if(num_items < MAX_ITEMS)
		inventory[num_items++] = "healing potion.";
	else
		cout << "You have too many items and can't carry another.";
	
	// ===================================
	cout << "You items:\n";
	for(int i=0; i<num_items; ++i)
		cout << inventory[i] << endl;
	
	// ==================================
	
	return 0;
}
