#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N,L,H;
struct student{
    int de;
    int cai;
    int no;
    int tot;
    int leave=5;
    student(int no,int de,int cai){
        this->no=no;
        this->de=de;
        this->cai=cai;
        if(de>=L && cai>=L){
            if(de>=H && cai>=H){
                this->leave=1;
            }else if(de>=H && cai<=H){
                this->leave=2;
            }else if(de>cai && de<=H && cai<=H){
                this->leave=3;
            }else {
                this->leave=4;
            }
        }else{
            this->leave=5;
        }
        this->tot=de+cai;
    }
};
bool cmp(student s1,student s2){
    if(s1.leave!=s2.leave) return s1.leave<s2.leave;
    else if(s1.tot!=s2.tot) return s1.tot>s2.tot;
    else {
        if(s1.de!=s2.de) return s1.de>s2.de;
        else return s1.no<s2.no;
    }
}
vector<student> vec;

int main(){
    scanf("%d%d%d",&N,&L,&H);
    int cnt=0;
    while(N--){
        int no,de,cai;
        scanf("%d%d%d",&no,&de,&cai);
        student s=student(no,de,cai);
        if(s.leave<5){
            vec.push_back(s);
        }
    }
    sort(vec.begin(),vec.end(),cmp);
    printf("%d\n",vec.size());
    for(vector<student>::iterator it=vec.begin();it!=vec.end();it++){
        student s=*it;
        printf("%d %d %d\n",s.no,s.de,s.cai);
    }

}



















