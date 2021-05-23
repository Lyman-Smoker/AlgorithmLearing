//
// Created by lym on 2021-05-10.
//
#include <iostream>
using namespace std;

int main(){

    int n;
    cin>>n;
    int school[100001]={0};
    for(int i=0;i<=n;i++){
        int sch,sco;
        cin>>sch>>sco;
        school[sch]+=sco;
    }
    int k=0,ans=-1;
    for(int i=1;i<=n;i++){
        if(school[i]>ans)
        {
            k=i;
            ans=school[i];
        }
    }
    cout<<k<<" "<<ans<<endl;
    return 0;
}