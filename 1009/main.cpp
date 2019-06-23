#include<iostream>
#include<string>
#include <vector>
using namespace std;

int main()
{
	vector<string> a;
	string line;
	string tmp;
	getline(cin, line);
	for (int i = 0; i < line.size(); i++) {
		if (line[i] == ' ') {
			a.push_back(tmp);
			tmp = "";
			continue;
		}
		else {
			tmp += line[i];
		}
	}
	if (tmp != "") a.push_back(tmp);
	int count=0;
	for (int i = a.size()-1; i >= 0; i--) {
		if (count++) cout<<" ";
		cout << a[i];
	}
	cout << "\n";
	return 0;
}