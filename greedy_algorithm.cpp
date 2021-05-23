//
// Created by lym on 2021-03-18.
//
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
//贪心法系列例题

//例题1：硬币问题
//这时贪心法中最简单的例子，考虑从大面值到小面值即可
//所有面值
const int v[6]={1,5,10,50,100,500};
//每种面值的张数
int c[6];

void solve1(){
    int a;
    int ans=0;
    for(int i=5;i<0;i--){
        //钞票使用的张数
        int t=min(a/v[i],c[i]);
        a-=t*v[i];
        ans+=t;
    }
    cout<<ans<<endl;
}

//例题2：区间问题
//这个题并不像‘硬币问题那么简单，我们可以想到狠毒偶贪心算法：
//1）在可选工作中，每次都选取开始时间最早的工作
//2）在可选工作中，每次都选取结束时间最早的工作   √
//3）在可选工作中，每次都选取用时最短的工作
//4）在可选工作中，每次都选取与最少可选工作有重叠的工作
//
const int MAX_N=100000;
//输入:S-开始时间，T-结束时间

//用于对工作排序的pair数组
pair<int,int> itv[MAX_N];
void solve2(){
    int N,S[MAX_N],T[MAX_N];
    // 对pair进行字典序比较
    // 为了让结束时间早的工作排前面，把T存入first，S存入second
    for(int i =0;i<N;i++){
        itv[i].first=T[i];
        itv[i].second=S[i];
    }
    sort(itv,itv+N);
    // t是最后所选工作的结束时间
    int ans=0,t=0;
    for(int i=0;i<N;i++){
        if(t<itv[i].second){
            ans++;
            t=itv[i].first;
        }
    }
    cout<<ans<<endl;
}

// 字典序最小问题
// input: N=6,S="ACDBCB"
// output:T="ABCBCD"
void solve3(){
    int N;
    string S;
    cin>>N;
    cin>>S;
    int a=0,b=N-1;
    string T="";
    while(a!=b){
        if(S[a]<S[b]) {
            T += S[a];
            a += 1;
        }
        else {
            T += S[b];
            b -= 1;
        }

    }
    T+=S[a];
    cout<<T<<endl;
}
int main(){
    solve3();
    return 0;
}
