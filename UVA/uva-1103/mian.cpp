#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

//0表示空白位置,-1表示不能访问了.

const int maxn = 510;

int n, m,kase,a[maxn][maxn],flag[maxn][maxn],cnt,num[6];
char s16[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
char fuhao[6] = { 'A', 'D', 'J', 'K', 'S', 'W' };
int s2[16][4] =
{
    { 0, 0, 0, 0 }, { 0, 0, 0, 1 }, { 0, 0, 1, 0 }, { 0, 0, 1, 1 },
    { 0, 1, 0, 0 }, { 0, 1, 0, 1 }, { 0, 1, 1, 0 }, { 0, 1, 1, 1 },
    { 1, 0, 0, 0 }, { 1, 0, 0, 1 }, { 1, 0, 1, 0 }, { 1, 0, 1, 1 },
    { 1, 1, 0, 0 }, { 1, 1, 0, 1 }, { 1, 1, 1, 0 }, { 1, 1, 1, 1 }
};

void dfs1(int x,int y)
{
    if (x < 0 || x > n + 1 || y < 0 || y > m + 1 || a[x][y] != 0)    // 越界或=-1或=1；
        return;
    a[x][y] = -1;
    dfs1(x - 1, y);
    dfs1(x + 1, y);
    dfs1(x, y - 1);
    dfs1(x, y + 1);
}

void dfs2(int x, int y)
{
    if (x < 0 || x > n + 1 || y < 0 || y > m + 1 || a[x][y] == -1)
        return;
    if (a[x][y] == 0)    //图像内的空白区域
    {
        cnt++;     //计数
        dfs1(x, y);
        return;
    }
    a[x][y] = -1;
    dfs2(x - 1, y);
    dfs2(x + 1, y);
    dfs2(x, y - 1);
    dfs2(x, y + 1);
}

int main()
{
    while (scanf("%d%d", &n, &m) == 2 && (n || m))
    {
        memset(a, 0, sizeof(a));
        memset(num, 0, sizeof(num));
        //输入，转化为2进制存入a
        for (int i = 1; i <= n; i++)
        {
            getchar();    //接收回车
            char ch;
            int tot = 0;
            for (int j = 1; j <= m; j++)
            {
                scanf("%c", &ch);   //输入16进制
                for (int k = 0; k < 16; k++)    //16进制转2进制  存入a
                {
                    if (ch == s16[k])
                    {
                        for (int l = 0; l < 4; l++)
                            a[i][++tot] = s2[k][l];
                        break;
                    }
                }
            }
        }
        m *= 4;
        // dfs把图像周围的空白区域设置为不可访问（-1）
        dfs1(0, 0);
        //从每个黑点开始递归，遇到空白区域cnt++，并dfs1
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j] == 1)
                {
                    cnt = 0;
                    dfs2(i, j);
                    if (cnt == 0)
                        num[5]++;
                    if (cnt == 1)
                        num[0]++;
                    if (cnt == 2)
                        num[3]++;
                    if (cnt == 3)
                        num[2]++;
                    if (cnt == 4)
                        num[4]++;
                    if (cnt == 5)
                        num[1]++;
                }
        printf("Case %d: ", ++kase);
        for (int i = 0; i <= 5; i++)
        {
            while (num[i]--)
                printf("%c", fuhao[i]);
        }
        printf("\n");
    }

    return 0;
}
