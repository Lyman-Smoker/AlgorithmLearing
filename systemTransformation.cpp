//
// Created by lym on 2020-11-11.
// C++进制转换方法
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
void anySystem(int n,int p);
int main(){
    //库函数实现八进制、十六进制输出
    int test=64;
    cout<<"DEC:"<<test<<endl;
    cout<<"OCT:"<<oct<<test<<endl;//八进制
    cout<<"HEX:"<<hex<<test<<endl;//十六进制
    anySystem(55,7);
    return 0;
}
// 十进制转任意进制

void anySystem(int n,int p){
    int s[100],m=0,c;
    while (n!=0)//数制转换，结果存入数组s[m]
    {
        c=n%p;
        n=n/p;
        m++;s[m]=c;   //将余数按顺序存入数组s[m]中
    }

    for(int k=m;k>=1;k--)//输出转换后的序列
    {
        if(s[k]>=10) //若为十六进制等则输出相对应的字母
            cout<<(char)(s[k]+55);
        else         //否则直接输出数字
            cout<<s[k];
    }

}

