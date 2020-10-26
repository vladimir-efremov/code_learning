// Демонстрация работы с областями видимости
#include <iostream>

using namespace std;

void func();

// ==========================================
int main()
{
	int tmp = 5;
	cout << "In main() tmp is: " << tmp << endl;

	func();
	cout << "Back in main() tmp is: " << tmp << endl;
	{
		cout << "In main() in a new scope tmp is: " << tmp << endl;
		cout << "Creating new tmp in new scope.\n";
		int tmp = 10;

		cout << "In main() in a new scope tmp is: " << tmp << endl;
	}

	cout << "At end of main() tmp created in new scope no longer exists.\n";
	cout << "At end of main() tmp is: " << tmp << endl;

	return 0;
}

// ==========================================
void func()
{
	int tmp = -5;
	cout << "In func() tmp is: " << tmp << endl;
}
