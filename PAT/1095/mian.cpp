#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct stu{
    string id;
    int value;
};


bool cmp(stu s1,stu s2){
    if(s1.value!=s2.value){
        return s1.value>s2.value;
    }else{
        return s1.id<s2.id;
    }
}

int main(){
    int N,M;
    cin>>N>>M;
    vector<stu> v(N);
    for(int i=0;i<N;i++){
        cin>>v[i].id>>v[i].value;
    }
    for(int i=1;i<=M;i++){
        int type;
        string op;
        cin>>type>>op;
        printf("Case %d: %d %s\n",i,type,op.c_str());
        ///vector<stu>::iterator it=v.begin();
        vector<stu> v1;
        int count=0;
        int cnt=0;
        if(type==1){
            for(int j=0;j<N;j++){
                if(v[j].id[0]==op[0]) v1.push_back(v[j]);
            }
            sort(v1.begin(),v1.end(),cmp);    //排序
            //输出
            if(v1.size()!=0){
                for(int j=0;j<v1.size();j++)
                    printf("%s %d\n",v1[j].id.c_str(),v1[j].value);
            }else printf("NA\n");
        }else if(type==2){
            for(int j=0;j<N;j++)
                if(v[j].id.substr(1,3)==op) {
                    count+=v[j].value;
                    cnt++;
                }
            //输出
            if(cnt!=0) printf("%d %d\n",cnt,count);
            else printf("NA\n");
        }else if(type==3){
            unordered_map<string,int> m;
            vector<stu> v3;
            /// 统计所有考场的人数  存在m
            for(int j=0;j<N;j++){
                string data=v[j].id.substr(4,6);
                if(data==op){
                    string _kc=v[j].id.substr(1,3);
                    m[_kc]++;
                }
            }
            unordered_map<string,int>::iterator it;
            /// 遍历m，把统计结果存到v3
            for(it=m.begin();it!=m.end();it++){
                stu temp;
                temp.id=it->first;
                temp.value=it->second;
                v3.push_back(temp);
            }
            /// v3排序 value降序   id升序
            sort(v3.begin(),v3.end(),cmp);
            /// 输出
            if(v3.size()!=0){
                for(vector<stu>::iterator it_v3=v3.begin();it_v3!=v3.end();it_v3++){
                    printf("%s %d\n",it_v3->id.c_str(),it_v3->value);
                }
            }else{
                printf("NA\n");
            }
        }

    }
}















