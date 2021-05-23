//
// Created by lym on 2020-11-05.
// 堆栈简单应用
// 简易计算器：读一个只包含+，-，*，/的非负整数计算表达式，并计算该式子的值，精确到小数点后两位
//
#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;
char str[220];  //保存表达式字符串
/*
 * 优先级矩阵
 * 若mat[i][j]==1,则表示i号运算符优先级大于j号运算符
 * 运算符编码规则为+为1，-为2，*为3，/为4
 * 认为添加在表达式首尾的标记运算符0号
 */
int mat[][5]={
        1,0,0,0,0,
        1,0,0,0,0,
        1,0,0,0,0,
        1,1,1,0,0,
        1,1,1,0,0,
};
stack<int> op;//运算符栈，保存运算符编号
stack<double> in;//数字栈，运算结果可能存在浮点数，所以保存元素为double
void getOp(bool &reto, int& retn, int&i){
    /*
     * 获得表达式中下一个元素函数
     * 若函数运行结束时，引用变量reto为true，则表示该元素为一个运算符，其编号保存在引用变量retn中；
     * 否则，表示该元素为一个数字，其值保存在引用变量retn中。
     * 引用变量i表示遍历到的数字串下标
     */
    if(i==0 && op.empty()){
        //若此时遍历字符串第一字符且运算符栈为空，我们认为添加编号为0的标记字符
        reto=true;
        retn=0;
        return;
    }
    if(str[i]==0){
        //若遍历字符为空字符，则表示已遍历完
        reto=true;
        retn=0;
        return;
    }
    if(str[i]>='0'&&str[i]<='9'){
        //若当前字符为数字
        reto=false;
    }
    else{
        reto=true;
        if(str[i]=='+'){
            retn=1;
        }
        else if(str[i]=='-'){
            retn=2;
        }
        else if(str[i]=='*'){
            retn=3;
        }
        else if(str[i]=='/'){
            retn=4;
        }
        i+=2;//跳过概运算字符和该运算字符后的空格
        return;
    }
    //结果为数字时，执行以下代码
    retn=0;
    for(;str[i]!=' '&&str[i]!=0;i++) {
        //若字符串未遍历完且下个字符不是空格，依次遍历后面的数字
        retn *= 10;
        retn += str[i] - '0';
    }
    if (str[i]==' ')
        //若后面为空格，则跳过该空格
        i++;
    return;
}


int main(){
    while(gets(str)){
        if(str[0]=='0'&&str[1]==0)  break;
        bool retop= true;
        int retnum=-1;
        int idx=0;
        while(!op.empty())  op.pop();
        while(!in.empty())  in.pop();
        while(true){
            getOp(retop,retnum,idx);
            if(!retop){
                //若为数字
                in.push((double)retnum);//将数字压进栈中
            }
            else{
                double tmp;
                if (op.empty() || mat[retnum][op.top()]==1)
                    op.push(retnum);
                else{
                    while(mat[retnum][op.top()]==0){
                        //只要当前运算符优先级小于栈顶元素运算符，则重复循环
                        int ret=op.top();
                        op.pop();
                        double b=in.top();
                        in.pop();
                        double a=in.top();
                        in.pop();
                        if (ret==1) tmp=a+b;
                        else if(ret==2) tmp=a-b;
                        else if(ret==3) tmp=a*b;
                        else tmp=a/b;
                        in.push(tmp);    //将结果压回数字栈
                    }
                    op.push(retnum);
                }
            }
            if(op.size()==2&&op.top()==0)
                //如果只有两个元素，且其栈顶元素为标记运算符，则表示表示表达式求值结束
                break;
        }
        printf("%.2f\n",in.top());
    }
    return 0;
}

