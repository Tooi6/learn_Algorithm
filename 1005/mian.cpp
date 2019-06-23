#include <cstdio>
#define maxn 10005
using namespace std;

int n[maxn];
int main()
{
    int k;
    scanf("%d",&k);
    while(k--){
        int x;
        scanf("%d",&x);
        n[x]=1;
    }
    for(int i=1;i<=100;i++){
        if(n[i]==1){
            int x=i;
            while(x>1){
                if(x%2==0){
                    x=x/2;
                }else{
                    x=(3*x+1)/2;
                }
                n[x]=0;
            }
        }
    }
    int flag=0;
    for(int i=100;i>0;i--){
        if(n[i]==1) {
            if(flag++) printf(" ");
            printf("%d",i);
        }
    }
    return 0;
}
