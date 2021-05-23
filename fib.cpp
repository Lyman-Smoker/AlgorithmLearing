// utf-8
// Created by lym on 2020-12-05.
// 斐波那契数列的几种计算方法
// 状态转移方程：f(n) = f(n-1) + f(n-2)
#include <vector>
#include <iostream>
using namespace std;
/*
 * 1、暴力递归
 *     优点：简单易懂
 *     缺点：十分低效，时间复杂度O(2^N)，指数级
 */
int fib_simple_recursion(int N){
    if(N==1 || N==2) return 1;
    return fib_simple_recursion(N-1) + fib_simple_recursion(N-2);
}

/*
 * 2、带备忘录的递归
 *    思路：造一个”备忘录“，每次算出某个子问题的答案后别急着返回，先记录到
 *         “备忘录”里再返回，每次遇到一个子问题先去“备忘录“里查一查，如果
 *         发现已解决过，则直接拿来用，不需要再耗时进行计算。
*/
int helper(vector<int>& memo, int n){
    //base case
    if(n==1 || n==2) return 1;
    //如果已经计算过，则直接返回
    if(memo[n] != 0) return memo[n];
    //如果没有计算过，则递归计算
    memo[n] = helper(memo,n-1) + helper(memo, n-2);
    return memo[n];
}

int fib_recursion_with_helper(int N){
    if(N<1) return 0;
    //备忘录全初始化为0
    vector<int> memo(N+1,0);
    return helper(memo, N);
}

/*
 * 3、dp数组的迭代
 *    有了上一步helper的启发，我们可以把这个helper独立出来称为一张表（dp table）
 *    在这张表上完成推算
 */
int fib_with_dpTable(int N){
    if(N==0) return 0;
    if(N==1) return 1;
    vector<int> dp(N+1, 0);
    dp[1]=dp[2]=1;
    for(int i=3;i<=N;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[N];
}

/*
 * 4、状态压缩
 *    在前面的基础上，我们发现，根据状态转移方程f(n) = f(n - 1) + f(n - 2)
 *    当前状态只与之前两个状态有关。
 *    那么，事实上，我们只需要想办法储存之前的两个状态就行了，因此，做进一步优化
 */
int fib(int n) {
    if (n == 2 || n == 1)
        return 1;
    int prev = 1, curr = 1;
    for (int i = 3; i <= n; i++) {
        int sum = prev + curr;
        prev = curr;
        curr = sum;
    }
    return curr;
}