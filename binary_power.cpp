//
// Created by lym on 2020-11-19.
// 二分求幂算法
#include <iostream>
#include <stdio.h>
using namespace std;
int get_power(int a,int b){
    int result=1;
    while(b){
        if(b%2==1)
            result *=a;
        a*=2;
        b/=2;
    }
}

int main(){

    return 0;
}
