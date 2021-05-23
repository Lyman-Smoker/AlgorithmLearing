//
// Created by lym on 2021-05-10.
//
#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans=0;
    while (true){
        if (n==1)
            break;
        if(n%2==0){
            n/=2;
        }
        else{
            n=3*n+1;
            n/=2;
        }
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}