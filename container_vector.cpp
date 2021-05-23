//
// Created by lym on 2020-11-03.
// 用于学习向量容器的使用
//
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    // 创建向量容器
    vector<int>obj;
    //使用push_back()在数组最后添加数据
    for(int i=0;i<10;i++)
    {
        obj.push_back(i);
        cout<<obj[i]<<",";
    }
    //使用pop_back()去掉数组最后一个元素
    for(int i=0;i<5;i++)
    {
        obj.pop_back();
    }
    cout<<"\n"<<endl;
    //可用size()函数获取数组长度，相当于python的len()
    for(int i =0;i<obj.size();i++){
        cout<<obj[i]<<",";
    }

    for(int i=0;i<5;i++)
    {
        obj.push_back(i);
        cout<<obj[i]<<",";
    }
    // 两者连用实现降序排列，也可以重写sort函数实现
    sort(obj.begin(),obj.end());//sort函数用于将函数升序排列
    reverse(obj.begin(),obj.end());
    /*也可以用如下方法重写sort实现降序功能
     bool compare(int a, int b){
        return a>b;
     }
     sort(obj.begin(), obj.end(), compare);
     *
     */
    cout<<"\n"<<endl;
    for(int i =0;i<obj.size();i++){
        cout<<obj[i]<<",";
    }
    //使用clear()清楚数组
    obj.clear();
    cout<<"\n\n"<<obj.size()<<endl;

    //迭代器的使用
    for(int i=0;i<10;i++)
    {
        obj.push_back(i);
    }
    vector<int>::iterator it;
    cout<<endl;
    for(it=obj.begin();it!=obj.end();it++)
    {
        //注意要加*
        cout<<*it<<",";
    }
    cout<<"\n"<<endl;

    //二维数组
    //定义方法1：
    int N=5, M=6;
    vector<vector<int> >obj2_1(N);//定义二维动态数组大小5行,注意两个<之间需要加空格
    for(int i=0; i<obj2_1.size(); i++)//动态二维数组为5行6列，值全为0
    {
        obj2_1[i].resize(M);
    }
    //定义方法2
    /*int N=5, M=6;
    vector<vector<int> >obj2_1(N, vector<int>(M));//定义二维动态数组5行6列
    */
    for(int i=0; i<obj2_1.size(); i++)
    {
        for(int j=0;j<obj2_1[i].size();j++)
        {
            cout<<obj2_1[i][j]<<" ";
        }
        cout<<endl;
    }

    //删除某元素(使用迭代器)
    obj.erase(it);

    return 0;
}
