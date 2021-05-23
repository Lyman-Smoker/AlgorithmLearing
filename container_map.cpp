//
// Created by lym on 2020-11-07.
// 用于学习键值对容器的使用
// 参考：https://www.w3cschool.cn/cpp/cpp-fu8l2ppt.html
#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    // 定义格式
    //std::map< key_type, value_type> person;
    map<int, string > mapPerson;
    // 3种添加数据的方式
    mapPerson.insert(pair<int,string> (1,"Jim"));
    mapPerson.insert(std::map < int, std::string > ::value_type (2, "Tom"));
    mapPerson[3] = "Jerry";
    // 遍历_前向迭代器
    cout<<"iterator"<<endl;
    map<int,string >::iterator it;
    map<int,string >::iterator itEnd;
    it=mapPerson.begin();
    itEnd=mapPerson.end();
    while(it!=itEnd){
        //first指key，second指value
        cout<<it->first<<' '<<it->second<<endl;
        it++;
    }
    // 遍历_反向迭代器
    cout<<"reverse_iterator"<<endl;
    map<int,string >::reverse_iterator iter;
    for(iter=mapPerson.rbegin();iter!=mapPerson.rend(); iter++)
        cout<<iter->first<<' '<<iter->second<<endl;
    //查找
    map<int ,string > ::iterator l_it;;
    l_it = mapPerson.find(1);
    if(l_it == mapPerson.end())
        cout<<"we do not find 1"<<endl;
    else cout<<"wo find 1:"<<l_it->second<<endl;
    //也可以这么写： cout<<mapPerson[3];

    //删除
    /*
    iterator erase（iterator it)	;//通过一个条目对象删除
    iterator erase（iterator first，iterator last）；	//删除一个范围
    size_type erase(const Key&key);	//通过关键字删除
    clear()；//就相当于enumMap.erase(enumMap.begin(),enumMap.end());
    */
     return 0;
}
