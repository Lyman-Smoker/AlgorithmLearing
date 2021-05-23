//
// Created by lym on 2020-12-05.
//
/*
 * 凑零钱问题
 * 这是一道经典的动态规划问题
 * 题目：给你 k 种面值的硬币，面值分别为 c1, c2 ... ck，每种硬币的数量无限，
 *      再给一个总金额 amount，问你最少需要几枚硬币凑出这个金额，如果不可能凑出，
 *      算法返回 -1
 * 例子：比如说 k = 3，面值分别为 1，2，5，总金额 amount = 11。
 *      那么最少需要 3 枚硬币凑出，即 11 = 5 + 5 + 1。
 */
#include<iostream>
#include <vector>
#include <string>

using namespace std;

//暴力递归
int dp1(vector<int> coins, int n){
    if(n==0)
        return 0;
    if(n<0)
        return -1;
    int res=INT_MAX;
    for(int i=0;i<coins.size();i++){
        int coin=coins[i];
        int subproblem = dp1(coins,n-coin);
        if(subproblem==-1) continue;
        res = min(res, 1 + subproblem);
    }
    return (res!=INT_MAX) ? res : -1;
}
int coinChange_violent_recurrent(vector<int> coins, int amount ){
    return dp1(coins, amount);
}

//带备忘录的迭代
int dp2(vector<int>& coins, int rem, vector<int> &count)
{
    if (rem < 0)
        return -1;
    if (rem == 0)
        return 0;
    // ！= 0 代表count[rem - 1]已经计算过且保存在count中，直接返回，不用重复计算
    if (count[rem - 1] != 0)
        return count[rem - 1];
    int min = INT_MAX;
    for (int coin : coins){
        int res = dp2(coins, rem - coin, count);
        if (res >= 0 && res < min)
            min = 1 + res;
    }
    //保存结果，为下一次的计算减轻负担
    count[rem - 1] = (min == INT_MAX) ? -1 : min;
    return count[rem - 1];
}
int coinChange_helper_recurrent(vector<int>& coins, int amount) {
    if (amount < 1)
        return 0;
    vector<int> count(amount);//传递一个数组用来记录计算过到值，避免重复计算
    return dp2(coins, amount, count);
}


//数组迭代
int coinChange_array_recurrent(vector<int>& coins, int amount) {
    // 数组大小为 amount + 1，初始值也为 amount + 1
    vector<int> dp(amount + 1, amount + 1);
    // base case
    dp[0] = 0;
    // 外层 for 循环在遍历所有状态的所有取值
    for (int i = 0; i < dp.size(); i++) {
        // 内层 for 循环在求所有选择的最小值
        for(int i=0;i<coins.size();i++){
            int coin=coins[i];
            // 子问题无解，跳过
            if (i - coin < 0) continue;
            dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
    }
    return (dp[amount] == amount + 1) ? -1 : dp[amount];
}

int main(){
    vector<int> v;
    for(int i=1;i<5;i++)
        v.push_back(i);
    cout<<coinChange_array_recurrent(v,10)<<endl;
    return 0;
}