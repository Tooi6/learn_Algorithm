#include <iostream>
#include <stack>
#define maxn 1000+5

using namespace std;

int out[maxn];
int main()
{
    int n;
    while(cin>>n && n){

        while(1){
            cin>>out[1];
            if(out[1]==0) break;
            for(int i=2;i<=n;i++){
                cin>>out[i];   //输入出栈顺序
            }
            int out_no=1;     //出栈下标
            int in=1;     //入栈顺序
            stack<int> s;
            bool flag=true;
            while(out_no<=n){
                if(in==out[out_no]) {
                    //直接出栈
                    in++;
                    out_no++;
                }else if(!s.empty() && out[out_no]==s.top()){
                    //栈顶就是要出战的
                    s.pop();
                    out_no++;
                }else if(in<=n){
                    s.push(in);
                    in++;
                }else{
                    flag=false;
                    break;
                }
            }
            if(flag) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        cout<<endl;

    }

    return 0;
}
