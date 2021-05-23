//
// Created by lym on 2021-05-13.
//
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int n=0;
int c[5]={-1,-1,-1,-1};
bool hashTable[5]={false};
void generate(int idx){
//    cout<<idx;
    if(idx==5){
        n++;
//        for(int i=0;i<4;i++)
//            cout<<c[i];
//        cout<<endl;
        return;
    }
    for(int x=0;x<5;x++){
        if(idx==0){
            hashTable[x]=true;
            c[idx]=x;
            generate(idx+1);
            hashTable[x]=false;
            c[idx]=-1;
            continue;
        }
        //如果已被占用
        if(hashTable[x])
            continue;
        bool can_be_eaten=false;
        //遍历前面的皇后
        for(int pre=0;pre<idx;pre++){
            //如果可以被其他皇后吃掉
            if(abs(pre-idx)==abs(c[pre]-x))
            {
                cout<<pre<<idx<<c[pre]<<x<<endl;
                can_be_eaten=true;
                break;
            }
        }
        if(can_be_eaten){
            continue;
        }
        //修改
        c[idx]=x;
        hashTable[x]=true;
        //往下
        generate(idx+1);
        //还原
        c[idx]=-1;
        hashTable[x]=false;

    }
}

int main(){
    generate(0);
    cout<<n<<endl;
    return 0;
}
