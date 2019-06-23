#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

struct stu{
    char name[11];
    char no[11];
    int sc;
};
int main()
{
   int n;
   cin>>n;
   stu max,min;
   max.sc=-1;
   min.sc=101;
   while(n--){
        stu s;
        scanf("%s %s %d",&s.name,&s.no,&s.sc);
        if(s.sc>max.sc){
            max=s;
        }
        if(s.sc<min.sc){
            min=s;
        }
   }
    cout<<max.name<<" "<<max.no<<endl;
    cout<<min.name<<" "<<min.no<<endl;
    return 0;
}
