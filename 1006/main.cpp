#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int b,s,g;
    b=n/100;
    s=(n/10)%10;
    g=n%10;
    while(b--){
        printf("B");
    }
    while(s--){
        printf("S");
    }
    for(int i=1;i<=g;i++){
        printf("%d",i);
    }
    return 0;
}
