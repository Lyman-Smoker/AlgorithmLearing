//
// Created by lym on 2020-12-10.
// 最优子结构详解

#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

/* 例题：最长上升子序列
 *      给定一个无需的整数数组，找到其中最长上升子序列的长度
 *      input：[10,9,2,5,3,7,101,18]
 *      output: 4
 *      explanation: 最长的上升字序列是[2,3,7,101],它的长度为4
 * 解题思路：
 *   1）定义一个dp数组，dp[i]表示以nums[i]这个数结尾的最长递增子序列的长度。
 *      如：对[1,4,3,4,2],dp[3]=3,dp[4]=2
 *   2) 思考如何设计算法逻辑进行状态转换
 *      如：对[1,4,3,4,2,3]，已知dp[0..4]，如何得到dp[5]?
 *      nums[5]=3，既然是递增子序列，我们只要找到前面那些结尾比3小的子序列，
 *      然后把 3 接到最后，就可以形成一个新的递增子序列，而且这个新的子序列长度加一
 */
int lengthOfLIS(vector<int> nums){
    //定义dp向量，长度与nums相同,初值都设置为1
    vector<int> dp(nums.size(),1);
    //当前指针
    for(int i=0;i<nums.size();i++){
        //当前指针前的值
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j])
                //如果当前值比前面的值大，则可以增长子序列
                dp[i]=max(dp[i],dp[j]+1);
        }
    }
    int res = 0;
    for(int i=0;i<dp.size();i++){
        res=max(res,dp[i]);
    }
    return res;
}



/*
 * 例题：最长回文子串
 *      给定一个字符串s ，找到s中最长的回文子串
 */
string longestPalindrome(string s) {
    int best_i=0,best_j=0;
    int best_len=1;
    int j;
    for(int i=0;i<s.size();i++){
        for(int n=1;n<s.size()/2+1;n++){
            if(i-n<0 || i+n>=s.size())
                break;
            if(s[i-n]==s[i+n]){
                //拓展
                if(2*n+1>best_len){
                    best_i=i-n;
                    best_j=i+n;
                    best_len=2*n+1;

                }
            }
            else
                break;
        }
        if(s[i]==s[i+1]){
            j=i+1;
            for(int n=0;n<s.size()/2+1;n++){
                if(i-n<0 || j+n==s.size())
                    break;
                if(s[i-n]==s[j+n]){
                    //拓展
                    if(2*n+2>best_len){
                        best_i=i-n;
                        best_j=j+n;
                        best_len=2*n+2;
                    }
                }
                else
                    break;
            }
        }
    }
    return s.substr(best_i,best_j-best_i+1);
}

int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(3);
    cout<<lengthOfLIS(nums)<<endl;
    return 0;
}

