// Inventory Displayer
// Демонстрация работы с константными ссылками
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void display(const vector<string> &inventory);

// ==============================
int main()
{
	vector<string> inventory;

	inventory.push_back("Sword");
	inventory.push_back("Armor");
	inventory.push_back("Shield");

	display(inventory);

	return 0;
}

// ==============================
// параметр vec - это константная ссылка на вектор строк
void display(const vector<string> &vec)
{
	cout << "Your items:\n";

	for(vector<string>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter)
		cout << "- " << *iter << endl;
}
