// Uva 297
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int len = 32;    //1024=32*32
const int maxn = 1024 + 10;
char s[maxn];
int buf[len][len];     //数组表示改块是否为黑
int cot;
void draw(char *s,int &p,int r, int c, int w){//&p：结点位置（这里必须用引用，利用引用记录p每次改变的位置）；(r,c);每个块的左上角坐标;w:边长
    char ch = s[p++];
    if(ch == 'p'){
        draw(s, p, r    , c+w/2, w/2);//1,(r,c)分别表示四个位置的左上角，每次矩阵缩小2倍
        draw(s, p, r    , c    , w/2);//2
        draw(s, p, r+w/2, c    , w/2);//3
        draw(s, p, r+w/2, c+w/2, w/2);//4
    }
    else if(ch == 'f'){
        for(int i=r;i<r+w;i++)//将(r,c)开始边长为w全部计数
            for(int j=c;j<c+w;j++)
                if(buf[i][j] == 0) buf[i][j] = 1,cot++;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        memset(buf,0,sizeof(buf));
        cot = 0;
        for(int i=0;i<2;i++){
            scanf("%s",s);
            int p=0;
            draw(s,p,0,0,len);
        }
        printf("There are %d black pixels.\n",cot);
    }
    return 0;
}