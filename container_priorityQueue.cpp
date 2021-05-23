//
// Created by lym on 2020-11-08.
// 用于学习优先队列容器的使用
// 优先队列具有队列的所有特性，包括基本操作，
// 只是在这基础上添加了内部的一个排序，它本质是一个堆实现的
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
    /*
     * 定义：priority_queue<Type, Container, Functional>
     * //升序队列
     * priority_queue <int,vector<int>,greater<int> > q;
     * //降序队列
     * priority_queue <int,vector<int>,less<int> >q;
     * //greater和less是std实现的两个仿函数
     * （就是使一个类的使用看上去像一个函数。其实现就是类中实现一个operator()，这个类就有了类似函数的行为，就是一个仿函数类了）
     */
    priority_queue<int> a;//默认为降序队列（大顶堆）
    priority_queue<int, vector<int>, greater<int> > c;  //这样就是小顶堆
    priority_queue<string> b;

    for (int i = 0; i < 5; i++)
    {
        a.push(i);
        c.push(i);
    }
    while (!a.empty())
    {
        cout << a.top() << ' ';
        a.pop();
    }
    cout << endl;

    while (!c.empty())
    {
        cout << c.top() << ' ';
        c.pop();
    }
    cout << endl;

    b.push("abc");
    b.push("abcd");
    b.push("cbd");
    while (!b.empty())
    {
        cout << b.top() << ' ';
        b.pop();
    }
    cout << endl;
    return 0;
}
