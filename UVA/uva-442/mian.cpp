#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct Matrix{
    int a,b;
    Matrix(int x=0,int y=0){
        a=x;
        b=y;
    }
}m[26];

int main()
{
    int n;
    cin>>n;
    while(n--){
        char ch;
        int a,b;
        cin>>ch>>a>>b;
        m[ch-'A'].a=a;
        m[ch-'A'].b=b;
    }
    string exp;
    while(cin>>exp){
        stack<Matrix> s;
        int ret=0;
        bool flag=true;
        for(int i=0;i<exp.length();i++){
            if( isalpha(exp[i]) ){
                //字母入栈
                s.push(m[exp[i]-'A']);
            }else if(exp[i]==')'){
                //右括号 出栈，计算，结果入栈
                Matrix m1=s.top(); s.pop();
                Matrix m2=s.top(); s.pop();
                if(m1.a!=m2.b)    //后进先出！！！
                    {flag=false;break;}   //出错无法相乘
                ret+=m1.a*m1.b*m2.a;
                s.push(Matrix(m2.a,m1.b));
            }
        }
        if(flag) cout<<ret<<endl;
        else cout<<"error"<<endl;
    }
    return 0;
}