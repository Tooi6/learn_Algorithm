// Uva679
#include <cstdio>
//#include <cstring>
//#define maxd 20

using namespace std;

//int s[1<<maxd];  //开关状态，最大节点数2^maxd -1

int main()
{
    //int D,I;
    /*while(scanf("%d%d",&D,&I)==2){
        int n=(1<<D)-1;    // 节点数
        memset(s,0,n);     //开关 初始化为0
        int k;
        for(int i=0;i<I;i++){
            k=1;     //记录最后的值
            while(k<n){
                s[k]=!s[k];
                if(s[k]!=0) k=k*2;
                else k=k*2+1;
            }
        }
        printf("%d",k/2);
    }*/  //超时

    //根据I的奇偶性判断他应该往左还是往右
    //I为奇数时，他是第（i+1）/2个往左走的球
    //I为偶数时，他是第 i/2个往左走的球
    int n;
    while(scanf("%d",&n) && n!=-1){
        int D,I;
        for(int t=0;t<n;t++){
            scanf("%d%d",&D,&I);
            int k=1;
            for(int i=0;i<D-1;i++){
                if(I%2==1){
                    k=k*2;
                    I=(I+1)/2;
                }else{
                    k=k*2+1;
                    I=I/2;
                }
            }
            printf("%d\n",k);
        }
    }
    return 0;
}