#include <cstdio>
#include <iostream>

using namespace std;


int main() {
	int k, e;
	int count = 0;
	/*cin >> k >> e;
	if (e == 0) {
		if (count++) cout << " ";
		cout << "0 0";
	}
	else {
		if (count++) cout << " ";
		cout << k * e << " " << e - 1;
	}*/
	while (cin >> k >> e)
	{
		
		if (e != 0) {
			if (count++) cout << " ";
			cout << k * e << " " << e - 1;
		}
		if (e == 0 && count == 0) {
			cout << "0 0";
			
		}
	}

	return 0;
}