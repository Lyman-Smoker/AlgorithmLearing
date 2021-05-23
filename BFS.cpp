//
// Created by lym on 2021-03-17.
//
/*
 * 广度优先搜索
 * BFS也是搜索手段之一，从某个状态触发搜索所有可以到达的状态
 */
#include <iostream>
using namespace std;
//例题：迷宫最短路径
int n,m;
int a[100][100];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int min_d=10000;
int gx,gy;
int sx,sy;
int BFS(int x,int y){
    int dm=10000;
    if(a[x][y]=='#')    return dm;
    a[x][y]='#';
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(a[nx][ny]=='#' || nx>=n || nx<0 || y>=m || ny<0)  continue;
        if(nx==gx && ny==gy)    return 1;
        int d=BFS(nx,ny)+1;
        if(d<dm)
            dm=d;
    }
    return dm;
}

int solution(){
    return BFS(sx,sy);
}