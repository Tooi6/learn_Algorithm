#include <cstdio>
#define maxn 100000

int a[maxn];
 
using namespace std;

int main() {
	int N, M;
	scanf("%d%d",&N,&M);
	M %= N;
	if (N < 1) return 0;
	for (int i = 0; i < N; i++) 
		scanf("%d",&a[i]);
	int count = 0;
	for (int i = N - M; i < N ; i++) {
		if (count++) printf(" ");
		printf("%d",a[i]);
	}
	for (int i = 0; i < N - M; i++) {
		if (count++) printf(" ");
		printf("%d", a[i]);
		if (i == N - M - 1) printf("\n");
	}
	return 0;
}