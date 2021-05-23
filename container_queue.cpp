//
// Created by lym on 2020-11-08.
//
#include <iostream>
#include <queue>
/*
 * 队列特点：先进先出
 * cpp queue实现方式：只能访问第一个和最后一个元素。
 * 只能在容器的末尾添加新元素，只能从头部移出元素
 * cpp queue没有迭代器
 */
using namespace std;
int main(){
    queue<double> q;
    for(int i=0;i<10;i++){
        q.push(i);
    }
    if(!q.empty()){
        cout<<"the queue is not emtpy";
        cout<<", and the size of the queue is "<<q.size()<<endl;
    }
    cout<<"the front data: "<<q.front()<<endl;
    cout<<"the back data: "<<q.back()<<endl;
    cout<<"pop the front data of the queue"<<endl;
    q.pop();
    if(!q.empty()){
        cout<<"now the front is: "<<q.front()<<endl;
    }
    return 0;
}

