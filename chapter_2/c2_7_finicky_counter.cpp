// Finicky counter
// do while

#include <iostream>

using namespace std;

int main()
{
	int count = 0;
	while(true)
	{
		++count;
		if(count > 10)
			break;

		if(count == 5)
			continue;
		cout << count << endl;
	}

	return 0;
}
