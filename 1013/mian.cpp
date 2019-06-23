#include <cstdio>
#include <iostream>
#define maxn 1000000
using namespace std;

int a[maxn];

int main() {
	int M, N;
	cin >> M >> N;
	int n = 1,i = 2;
	while (n<=N)
	{
		int flag=1;
		for (int j = 2; j*j <= i; j++) {
			if (i%j == 0) { flag = 0; break; }
		}
		if (flag) a[n++] = i;
		i++;
	}
	int count=0;
	for (M; M <= N; M++) {
		if (count == 10) { cout << endl; count = 0; }
		if (count++) cout << " ";
		cout << a[M];
	}
	return 0;
}