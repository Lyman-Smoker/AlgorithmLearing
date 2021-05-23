//
// Created by lym on 2021-05-19.
//
#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int> v,int k){
    // 默认向量升序排列
    int low=0;
    int high=v.size()-1;
    int mid=(low+high)/2;
    while(low<=high){
        if(v[mid]==k){
            return mid;
        }
        else if(v[mid]>k){
            high=mid;
            mid=(high+low)/2;
        }
        else{
            low=mid+1;
            mid=(high+low)/2;
        }
    }
    return -1;
}

int main(){
    vector<int> v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    for(int i=0;i<10;i++){
        cout<<binarySearch(v,i)<<" ";
    }

    return 0;
}