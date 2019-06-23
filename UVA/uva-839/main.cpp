#include <cstdio>

using namespace std;

bool solve(int &W){    //参数为引用类型，传入后返回总重量
    int w1,d1,w2,d2;
    scanf("%d%d%d%d",&w1,&d1,&w2,&d2);
    bool b1=true;
    bool b2=true;
    if(!w1) b1=solve(w1);   //w1==0时计算左子树的总重量w1
    if(!w2) b2=solve(w2);   //w2==0时计算左子树的总重量w2
    W=w1+w2;
    return b1&&b2&&(w1*d1==w2*d2);
}

int main()
{
    int T,W;
    scanf("%d",&T);
    while(T--){
        if(solve(W)) printf("YES\n");
        else printf("NO\n");
        if(T) printf("\n");
    }

    return 0;
}