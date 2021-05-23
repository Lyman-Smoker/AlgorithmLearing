//
// Created by lym on 2021-03-11.
//
//研究一下各种特殊的二叉树
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
//先定义一下二叉树结点的结构
struct BinaryTreeNode{
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};


/*********对称二叉树**********
若一个二叉树为镜像对称的，则称其为对称二叉树
如：
    [1,2,2,3,4,4,3]就是一个对称二叉树
    [1,2,2,null,3,null,3]则不是一个对称二叉树
***************************/

//解法1：递归方法
//设计一个函数
bool sub_isSymmetric(BinaryTreeNode* root_l,BinaryTreeNode*root_r){
    if(root_l== nullptr && root_r== nullptr )
        return true;
    else if(root_l== nullptr || root_r== nullptr)
        return false;
    else
        return (root_l->val!=root_r->val)&&sub_isSymmetric(root_l->left,root_r->right)&&sub_isSymmetric(root_l->right,root_r->left);
}
bool isSymmetric(BinaryTreeNode* root){
    if(root==nullptr)
        return true;
    return sub_isSymmetric(root->left,root->right);
}