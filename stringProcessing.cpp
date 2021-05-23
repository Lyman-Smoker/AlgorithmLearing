//
// Created by lym on 2020-11-17.
// 用于学习各种字符串处理方法
#include <string>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
//string replacement(string s){
//    //假定将空格替换成%20这三个字符
//    string res;
//    for(auto c : s){
//        if(c == ' '){
//            res.push_back('%');
//            res.push_back('2');
//            res.push_back('0');
//        }
//        else
//            res.push_back(c);
//    }
//    return res;
//}

int trans2int(string s){
    // 字符串转整型
    int i=atoi(s.c_str());//转为int
    int f=atof(s.c_str());//转为float
    int l=atol(s.c_str());//转为long
    return i;
}

string trans2str(int i){
    // 数字转字符串（以整数为例）
    char str[10];
    sprintf(str,"%d",i);
    string s=str;
    return s;
}

//获取子串
string get_substr(int i,int l, string s){
    /*
     * i:子串开始位置的索引
     * n:子串长度
     * s:原字符串
     */
    return s.substr(i,l);
}

//查找字符串对应元素的位置
bool find_char(string s,char c){
    string::iterator it=find(s.begin(),s.end(),c);
    if(it != s.end())
        //找到
        return true;
    else
        return false;
}

int main(){
    string s="abaab";
    cout<<s.substr(0,2);
    return 0;

}