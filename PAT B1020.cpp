//
// Created by lym on 2021-05-17.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
bool camp(pair<int,float>a,pair<int,float>b){
    return a.second>b.second;
}
int main(){
    int n;
    float d;
    cin>>n>>d;
    float inv[9000]={0};//库存
    float p[9000]={0};//价格
    for(int i=0;i<n;i++){
        scanf("%f",&inv[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%f",&p[i]);
    }
    vector<pair<int,float> > v;
    for(int i=0;i<n;i++){
        v.push_back(make_pair(i,p[i]/inv[i]));
    }
    sort(v.begin(),v.end(),camp);
    float ans=0;
    for(int i=0;i<v.size();i++){
        //库存足够
        if(inv[v[i].first]>=d){
            ans+=p[v[i].first]/inv[v[i].first]*d;
            break;
        }
        //库存不够
        else{
            ans+=p[v[i].first];
            d-=inv[v[i].first];
        }
    }
    printf("%.2f",ans);
    return 0;
}
