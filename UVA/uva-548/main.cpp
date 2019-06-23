#include <iostream>
#include <string>
#include <sstream>
#define maxn 10000+5

using namespace std;

int in_order[maxn],post_order[maxn],lch[maxn],rch[maxn];

int n;
bool read_list(int *a){
    string s;
    if(!getline(cin,s)) return false;    //输入结束
    stringstream ss(s);
    n=0;int x;
    while(ss>>x){
        a[n++]=x;
    }
    return n>0;
}

int build(int L1,int R1,int L2,int R2){
    if(L1>R1) return 0;
    int root=post_order[R2];
    int p=L1;
    while(in_order[p]!=root) p++;   //找到in_order下root的位置
    int cnt=p-L1;
    lch[root]=build(L1,p-1,L2,L2+cnt-1);
    rch[root]=build(p+1,R1,L2+cnt,R2-1);
    return root;
}

int best,best_sum;     //最小路径的叶子节点和路径的和
void dfs(int u,int sum){
    sum+=u;
    if(!lch[u] && !rch[u]){
        if(sum<best_sum || (u<best && sum==best_sum)){
            best=u;
            best_sum=sum;
            return;
        }
    }
    if(lch[u]) dfs(lch[u],sum);
    if(rch[u]) dfs(rch[u],sum);
}

int main()
{
    while(read_list(in_order)){
        read_list(post_order);
        build(0,n-1,0,n-1);
        best_sum = 1000000000;
        dfs(post_order[n-1],0);
        cout<<best<<endl;
    }

    return 0;
}