#include <iostream>
#define maxn 100

using namespace std;

char a[maxn],b[maxn],c[maxn],d[maxn];
int main() {

    string day[8]= {"MON","TUE","WED","THU","FRI","SAT","SUN"};
    int hour;
    int minuter;
    cin>>a>>b>>c>>d;
    int count=0;
    for(int i=0; i<maxn; i++) {
        //day
        if(count==0 && a[i]==b[i] && a[i]>='A' && a[i]<='G') {
            int t=a[i]-'A';
            cout<<day[t]<<" ";
            count++;
            continue;
        }
        //hour
        if(count==1 && a[i]==b[i] && ( (a[i]>='0'&&a[i]<='9') || (a[i]>='A'&&a[i]<='N')) ){
            if(a[i]>='A'&&a[i]<='N')
                {hour=a[i]-'A'+10;break;}
            if(a[i]>='0'&&a[i]<='9')
                {hour=a[i]-'0';break;}
        }
    }
    //minuter
    for(int i=0;i<maxn;i++){
        if(c[i]==d[i] && isalpha(c[i])) {minuter=i;break;}
    }
    if(hour>=10) cout<<hour<<":";
    else cout<<"0"<<hour<<":";

    if(minuter>=10) cout<<minuter;
    else cout<<"0"<<minuter;
    return 0;
}
