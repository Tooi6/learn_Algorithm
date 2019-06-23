#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define maxn 256

using namespace std;

struct Node{
    bool have_value;   //是否被赋值过
    int v;
    Node *left, *rigth;
    Node(){
        // 初始化
        have_value=false;
        left=NULL;
        rigth=NULL;
    }
};
Node *root;   //根节点
bool failed;  //判断是否重复赋值
Node* newnode(){
    return new Node();
}
// 根据字符串创建节点（遍历字符串）  LLR)
void addnode(int v,char* s){
    Node *u=root;
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='L'){
            if(u->left==NULL) u->left=newnode();    //如果不存在则创建节点
            u=u->left;
        }else if(s[i]=='R'){
            if(u->rigth==NULL) u->rigth=newnode();
            u=u->rigth;
        }
    }
    if(u->have_value) {failed=true;return;}   //重复赋值，报错
    u->v=v;
    u->have_value=true;
}

char s[maxn];
bool read_input(){
    // 创建一颗新树
    failed=false;
    root=newnode();  //创建根节点
    while(1){
        if(scanf("%s",s) !=1 ) return false;   //全部输入结束！
        if(!strcmp(s,"()")) return true;     //一颗树结束
        int v;
        sscanf(s+1,"%d",&v);
        addnode(v,strchr(s,',')+1);       //LL)
    }
}
vector<int> ans;  //保存答案
// 宽度优先bfs遍历树
bool bfs(){
    queue<Node*> q;
    ans.clear();     //先清空之前的数据
    q.push(root);    //初始时只要根节点
    while(!q.empty()){
        Node* u=q.front(); q.pop();
        if(!u->have_value) {return false;}   //节点没有值，报错
        ans.push_back(u->v);
        if(u->left!=NULL) q.push(u->left);
        if(u->rigth!=NULL) q.push(u->rigth);
    }
    return true;
}


int main()
{
    while(1){
        if(read_input()==false) break;
        else{
            // 一颗树结束
            if(bfs()==false || failed) printf("not complete\n");
            else{
                for(int i=0;i<ans.size();i++){
                    if(i) printf(" ");
                    printf("%d",ans[i]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}