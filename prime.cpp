//
// Created by lym on 2020-11-12.
//
//如何确定一个数是素数？
#include <iostream>
#include <math.h>
#include <vector>
#include <stdio.h>
using namespace std;
bool judge(int x){
    if(x<=1) return false;
    int bound=(int)sqrt(x)+1;
    for (int i=2;i<bound;i++){
        //使用取余可以防止越界
        if(x%i==0)return false;
    }
    return true;
}

vector<int> prime_factorization(int x){
    // 分解质因数
    vector<int> prime;
    int o=x;
    int bound=(int)sqrt(x)+1;
    for(int i=2;i<=x;i++){
        if(x%i==0){
            prime.push_back(i);
            x=x/i;
            i--;
        }
    }
    return prime;
}

int main(){
    vector<int>::iterator it;
    vector<int>res;
    res=prime_factorization(14);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
    return 0;
}
