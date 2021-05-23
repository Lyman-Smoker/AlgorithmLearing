//
// Created by lym on 2020-11-04.
// 基于栈实现括号匹配算法
//
#include <stdio.h>
#include <stack>
#include <iostream>
using namespace std;
stack<int> s;   //定义一个栈
char str[110];  //保存输入字符串
char ans[110];  //保存输出字符串
int main(){
    while(scanf("%s",str)!=EOF){    //输入字符串，相当于无限循环输入
        int i;
        for(i=0;str[i]!=0;i++){
            if(str[i]=='('){
                s.push(i);
                ans[i]=' ';
            }
            else if(str[i]==')'){
                if(!s.empty()){
                    s.pop();    //站定位置左括号与之匹配，从栈中弹出该已经匹配的左括号
                    ans[i]=' ';
                }
                else ans[i]='?';
            }
            else ans[i]=' ';    //若其为其他字符，则无关，输出空格
        }
        while(!s.empty()){  //当字符串遍历完成后，尚留在堆栈中的左括号无法匹配
            ans[s.top()]='$';
            s.pop();        //弹出
        }
        ans[i]=0;
        cout<<str<<endl;
        cout<<ans<<endl;
    }
    return 0;
}