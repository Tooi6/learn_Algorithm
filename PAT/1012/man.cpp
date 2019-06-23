#include <iostream>
#include <cstdio>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
	vector<int> A1, A2, A3, A4, A5;
	int n;
	cin >> n;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x % 5 == 0 && x % 2 == 0) A1.push_back(x);
		if (x % 5 == 1)A2.push_back(x);
		if (x % 5 == 2)A3.push_back(x);
		if (x % 5 == 3)A4.push_back(x);
		if (x % 5 == 4)A5.push_back(x);
	}
	double A[6] = {0};
	for (int i = 0; i < A1.size(); i++) {
		A[1] += A1[i];
	}
	int flag = 1;
	for (int i = 0; i < A2.size(); i++) {
		if (flag) 
			A[2] += A2[i];
		else  A[2] -= A2[i];
		flag = !flag;
	}
	A[3] = A3.size();
	for (int i = 0; i < A4.size(); i++) {
		A[4] += A4[i];
	}
	A[4] = A[4] / A4.size();
	for (int i = 0; i < A5.size(); i++)
	{
		if (A5[i]>A[5]) A[5] = A5[i];
	}
	if (A1.size()) cout << A[1];
	else cout << "N";
	if (A2.size()) cout << " " << A[2];
	else cout << " N";
	if (A3.size()) cout << " " << A[3];
	else cout << " N";
	if (A4.size()) printf(" %.1f",A[4]);
	else cout << " N";
	if (A5.size()) cout << " " << fixed << setprecision(0) << A[5];
	else cout << " N";
	return 0;
}