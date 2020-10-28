// Inventory Referencer
// Демонстрация возврата ссылки
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string &ref_to_element(vector<string> &inventory, int i);

// ==============================
int main()
{
	vector<string> inventory;

	inventory.push_back("Sword");
	inventory.push_back("Armor");
	inventory.push_back("Shield");

	// отображается строка на которую указывает возвращенная ссылка
	cout << "Sending the returned reference to cout:\n";
	cout << ref_to_element(inventory, 0) << "\n\n";

	// присваивает одну ссылку другой - малозатратная операция присваивания
	cout << "Assigning the returned reference to another reference.\n";
	string &r_str = ref_to_element(inventory, 1);
	cout << "Sending the new reference to cout:\n";
	cout << r_str << "\n\n";

	//копирует строковый объект - затратная операция присваивания
	cout << "Assigning the returned reference to a string object.\n";
	string str = ref_to_element(inventory, 2);
	cout << "Sending the new string object to cout:\n";
	cout << str << "\n\n";

	// изменение строкового объекта посредством возвращенной ссылки
	cout << "Altering an object through a returned reference.\n";
	r_str = "Healing Potion";
	cout << "Sending the altered object to cout:\n";
	cout << inventory[1] << endl;

	return 0;
}

// ==============================
// параметр vec - это константная ссылка на вектор строк
string &ref_to_element(vector<string> &vec, int i)
{
	return vec[i];
}
