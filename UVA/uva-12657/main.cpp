// Uva12657
#include <cstdio>
#include <algorithm>
#define maxn 100005
using namespace std;

int right[maxn];
int left[maxn];

void link(int L,int R){
    right[L]=R;left[R]=L;
}

int main()
{
    int n,m;
    int kase=0;
    while(scanf("%d%d",&n,&m)==2){
        for(int i=1;i<=n;i++){
            right[i]=(i+1)%(n+1);
            left[i]=i-1;
        }
        right[0]=1;    //right[0]相当于head
        left[0]=n;
        int inv=0;    //执行4操作标志
        while(m--){
            int op,x,y;
            scanf("%d",&op);
            if(op==4) inv=!inv;
            else{
                //执行123操作
                scanf("%d%d",&x,&y);
                if(op==3 && right[y]==x) swap(x,y);
                if(op!=3 && inv ) op=3-op;    //执行过4操作，op=1变为op=2
                if(op==1 && x==left[y]) continue;
                if(op==2 && x==right[y]) continue;

                int lx=left[x],rx=right[x],ly=left[y],ry=right[y];
                if(op==1){
                    link(lx,rx);link(ly,x);link(x,y);
                }else if(op==2){
                    link(lx,rx);link(y,x);link(x,ry);
                }else if(op==3){
                    if(right[x]==y){ //x，y相邻
                        link(lx,y);link(y,x);link(x,ry);
                    }else{
                        link(lx,y);link(y,rx);link(ly,x);link(x,ry);
                    }
                }

            }
        }
        //计算结果输出
        long long ans=0;
        int b=0;
        for(int i = 1;i <= n;i++){
            if(inv){
                //执行过4操作，求偶数位之和
                b=right[b];
                if(i%2==0) ans+=b;
            }else{
                b=right[b];
                if(i%2==1) ans+=b;
            }
        }
        printf("Case %d: %lld\n",++kase,ans);
    }
    return 0;
}
