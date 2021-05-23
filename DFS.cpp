//
// Created by lym on 2021-03-17.
//
/*
 * 深度优先搜索DFS
 * DFS是搜索的手段之一。它从某个状态开始，不断地转移状态直到不能再转移，然后回退到前一步的状态，继续转移到其他状态，直到得到最终的解
 */
#include <iostream>
using namespace std;
//例题：给定整数a1,a2,...,an判断是否可以从中选出若干数，使它们的和恰好为k
//input:
//  n=4
//  a={1,2,4,7}
//  k=13
//output:
//  Yes
int n1,k1;
int a1[20];
bool dfs1(int i,int sum){
    if(i==n1)    return sum==k1;
    //加的情况
    if(dfs1(i+1,sum+a1[i]))   return true;
    //不加的情况
    if(dfs1(i+1,sum))    return true;
    return false;
}
void solve1(){
    if(dfs1(0,0))    cout<<"Yes"<<endl;
    else    cout<<"No"<<endl;
    return;
}

//例题2：Lake Counting问题
int n2,m2;
char a2[100][100];
void dfs2(int x,int y){
    a2[x][y]='.';
    //遍历周围八个点
    for(int dx=-1;dx<=1;dx++)
        for(int dy=-1;dy<=1;dy++){
            int nx=x+dx;
            int ny=y+dy;
            if(nx>=0 && nx<n2 && ny>=0 && ny<n2 && a2[nx][ny]=='W') dfs2(nx,ny);
        }
}
void solve2(){
    int pool=0;
    for(int i=0;i<n2;i++)
        for (int j = 0; j < m2; ++j) {
            if(a2[i][j]=='W'){
                dfs2(i,j);
                pool++;
            }
        }
    cout<<pool<<endl;
}