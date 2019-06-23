#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

bool is_sushu(int t){
    if(t==1 || t==0) return false;
    for(int i=2;i*i<t;i++){
        if(t%i==0) return false;
    }
    return true;
}

int main() {
    int L,K;
    cin>>L>>K;
    string s;
    cin>>s;
    for(int i=0;i<=L-K;i++){
        string temp=s.substr(i,K);
        int tp=atoi(temp.c_str());
        if(is_sushu(tp)) {
            cout<<temp;
            return 0;
        }
    }
    cout<<"404";
    return 0;
}
