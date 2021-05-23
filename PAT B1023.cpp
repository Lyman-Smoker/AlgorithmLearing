//
// Created by lym on 2021-05-17.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int main(){
    int f[10];
    for(int i=0;i<10;i++){
        cin>>f[i];
    }
    for(int i=0;i<10;i++){
        if(i!=0 && f[i]!=0){
            cout<<i;
            f[i]--;
            break;
        }
    }
    for(int i=0;i<10;i++){
        while(f[i]!=0){
            cout<<i;
            f[i]--;
        }
    }
    return 0;
}
