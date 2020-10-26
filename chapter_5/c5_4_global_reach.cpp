// Демонстрация работы с глобальными переменными
#include <iostream>

using namespace std;

int glob = 10;

void global_access();
void global_hide();
void global_change();

// ==========================================
int main()
{
	cout << "In main() glob is: " << glob << endl;

	global_access();
	global_hide();

	cout << "In main() glob is: " << glob << endl;

	global_change();

	return 0;
}

// ==========================================
void global_access()
{
	cout << "In global_access() glob is: " << glob << endl;
}

// ==========================================
void global_hide()
{
	int glob = 0;
	cout << "In global_hide() glob is: " << glob << endl;
}

// ==========================================
void global_change()
{
	glob = -10;
	cout << "In global_change() glob is: " << glob << endl;
}
