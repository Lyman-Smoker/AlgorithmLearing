//
// Created by lym on 2020-11-12.
// 最大公约数和最小公倍数
#include <stdio.h>
#include <iostream>
using namespace std;

//最大公约数递归形式
int gcd(int a, int b){
    if(b==0)    return a;
    else return gcd(b,a%b);
}

//最大公约数非递归形式
int gcd_unrecursive(int a, int b){
    while(b!=0){//只要b不为0就持续这一过程
        int t=a%b;
        a=b;
        b=t;
    }
    return a;//当b为0时，a即为所求
}

//最小公倍数
int lcm(int a, int b){
    return a*b/gcd(a,b);
}

int main(){
    int a;
    int b;
    cin>>a;
    cin>>b;
    cout<<gcd(a,b);
    return 0;
}

