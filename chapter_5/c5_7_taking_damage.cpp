// Демонстрация подстановки функций
#include <iostream>

using namespace std;

int radiation(int health);

// ==========================================
int main()
{
	int health = 80;
	cout << "Your health is: " << health << endl;

	health = radiation(health);
	cout << "After radiation exposure your health is: " << health << endl;

	health = radiation(health);
	cout << "After radiation exposure your health is: " << health << endl;

	health = radiation(health);
	cout << "After radiation exposure your health is: " << health << endl;

	return 0;
}

// ==========================================
inline int radiation(int health)
{
	return (health / 2);
}
