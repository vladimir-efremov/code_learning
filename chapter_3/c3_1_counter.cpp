// Counter
// массивы for
#include <iostream>

using namespace std;

int main()
{
	cout << "Счет вперед:\n";
	for(int i=0; i<10; ++i)
		cout << i << " ";

	cout << "\n\nСчет назад:\n";
	for(int i=9; i>=0; --i)
		cout << i << " ";

	cout << "\n\nСчет пятерками:\n";
	for(int i=0; i<=50; i+=5)
		cout << i << " ";

	cout << "\n\nСчет без аргументов:\n";
	int count = 0;
	for(; count<10;)
		cout << ++count << " ";

	cout << "\n\nСчет во вложенных циклах:\n";
	const int ROWS = 5, COLUMNS = 3;
	for(int i=0; i<ROWS; ++i)
	{
		for(int j=0; j<COLUMNS; ++j)
			cout << i << "." << j << " ";

		cout << endl;
	}
	return 0;
}
