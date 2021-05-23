//
// Created by lym on 2020-11-08.
//
#include <iostream>
#include <queue>
#include <string>
#include <stdio.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > Q;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        while(!Q.empty()){
            //对新的一组数据，先清空
            Q.pop();
        }
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            Q.push(x);//将权值放入堆中
        }
        int ans=0;
        while(Q.size()>1){
            int a = Q.top();
            Q.pop();
            int b = Q.top();
            Q.pop();//取出两个最小的元素，它们为同一个节点的左右儿子且该双亲节点的权值为他们的和
            ans+=a+b;//将该双亲节点的权值放回堆中
            Q.push(a+b);
        }
        cout<<ans<<endl;
    }
    return 0;
}