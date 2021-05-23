//
// Created by lym on 2021-05-10.
//

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include <unordered_map>
#include <cstring>
#include <cstdio>
using namespace std;
//根据second的值降序排序
bool cmp2(pair<string, int>a, pair<string, int>b)
{
    if(a.second!=b.second) return a.second > b.second;
    else return strcmp(a.first,b.first)<0;
}

int main(){
    int N;
    cin>>N;
    int total_testees=0;
    vector<pair<string , int> > v;
    unordered_map<string,int> ma;
    for(int i=0;i<N;i++){
        int K;
        cin>>K;
        total_testees+=K;
        for(int j=0;j<K;j++){
            string regis;
            int score;
            cin>>regis>>score;
            v.push_back(make_pair(regis,score));
            ma[regis]=i+1;
        }
    }
    sort(v.begin(), v.end(), cmp2);
    cout<<total_testees<<endl;
    int fin_rank=1;
    unordered_map<int,vector<int> > local_rank;
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<" ";
        if(i==0)
            cout<<fin_rank;
        else if(v[i].second==v[i-1].second)
            cout<<fin_rank;
        else
        {
            fin_rank=i+1;
            cout<<fin_rank;
        }
        cout<<" "<< ma[v[i].first]<<" ";

        cout<<endl;
    }
    return 0;
}