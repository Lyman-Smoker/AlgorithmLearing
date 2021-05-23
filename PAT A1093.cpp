//
// Created by lym on 2021-05-20.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    string str;
    cin>>str;
    int n =str.length();
    int p_count[100001]={0};
    int t_count[100001]={0};
    vector<int> a_idx;
    for(int i=0;i<n;i++){
        if(str[i]=='P' and i!=n-1){
            p_count[i+1]=p_count[i]+1;
        }
        else if(i!=n-1){
            p_count[i+1]=p_count[i];
        }
        if(str[n-i-1]=='T' && (n-i-1)!=0){
            t_count[n-i-2]=t_count[n-i-1]+1;
        }
        else if((n-i-1)!=0){
            t_count[n-i-2]=t_count[n-i-1];
        }
        if(str[i]=='A'){
            a_idx.push_back(i);
        }
    }
    int ans=0;
//    for(int i=0;i<n;i++){
//        cout<<p_count[i]<<' ';
//    }
//    cout<<endl;
//    for(int i=0;i<n;i++){
//        cout<<t_count[i]<<' ';
//    }
//    cout<<endl;
    for(int i=0;i<a_idx.size();i++){
//        cout<<a_idx[i]<<' ';
        ans+=p_count[a_idx[i]]*t_count[a_idx[i]];
        ans=ans%1000000007;
    }
    cout<<(ans)%1000000007;
    return 0;

}
