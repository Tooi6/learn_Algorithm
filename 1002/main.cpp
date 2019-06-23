#include <cstdio>
#include <iostream>
#include <cstring>
#define maxn 1000

using namespace std;

int v[maxn];
string s[11]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu","shi"};
int main()
{
    char ch;
    int n=0;
    while(ch=getchar()){
        if(ch=='\n') break;
        n+=ch-'0';
    }
    int i=0;
    while(n>0){
        int x=n%10;
        v[i++]=x;
        n/=10;
    }
    int flag=0;
    while(i){
        if(flag++) cout<<" ";
        cout<<s[v[--i]];
    }
    return 0;
}
