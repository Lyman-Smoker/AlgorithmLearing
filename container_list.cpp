//
// Created by lym on 2020-11-03.
// 用于学习列表容器的使用
#include <string.h>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main(){
    list<int> li;
    li.push_back(3);
    li.push_back(6);
    li.push_back(4);
    li.push_back(3);
    //list只能使用迭代器遍历
    list<int>::iterator it=li.begin();
    for(;it!=li.end();it++){
        cout<<*it<<", ";
    }
    cout<<"\n"<<endl;


    return 0;
}

