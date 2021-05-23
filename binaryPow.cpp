//
// Created by lym on 2021-05-20.
//
#include <iostream>

using namespace std;
typedef long long ll;
//求a^b%m
ll binaryPow(ll a,ll b,ll m){
    if (b==0)   return 1;
    if(b%2==1)  return a* binaryPow(a,b-1,m)%m;
    else{
        ll mul=binaryPow(a,b/2,m);
        return mul *mul %m;
    }
}
