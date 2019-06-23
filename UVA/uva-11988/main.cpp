#include <cstdio>
#include <cstring>
using namespace std;
#define maxl 100005

int main()
{
    char s[maxl];
    while(~scanf("%s",s+1))
    {
        int Next[maxl]={0};
        int cur=0,last=0;

        for (int i = 1; s[i]; ++i)
        {
            if(s[i]=='[')    cur=0;
            else if(s[i]==']')    cur=last;
            else
            {
                //链表插入操作
                Next[i]=Next[cur];
                Next[cur]=i;
                //last的更新
                if(cur==last)    last=i;
                //cur的更新
                cur=i;
            }
        }

        for (int i = Next[0]; i != 0; i = Next[i])
            if (s[i]!='['&&s[i]!=']')
                printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}