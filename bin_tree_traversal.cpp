//
// Created by lym on 2021-03-10.
//
//来研究一下二叉树的遍历
/************
 先说最常见的三种遍历：
    ①先序遍历：顺序为【根左右】
    ②中序遍历：顺序为【左根右】
    ③后序遍历：顺序为【左右根】
    ④层序遍历: 一层一层从左往右
*/

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

//前序遍历代码
void traversal_pre(BinaryTreeNode* root){
    if(root== nullptr)
        return;
    //根左右
    cout<<root->val;
    traversal_pre(root->left);
    traversal_pre(root->right);
}
//中序遍历代码
void traversal_in(BinaryTreeNode* root){
    if(root== nullptr)
        return;
    //左根右
    traversal_in(root->left);
    cout<<root->val;
    traversal_in(root->right);
}
//后序遍历代码
void traversal_post(BinaryTreeNode* root){
    if(root== nullptr)
        return;
    //左右根
    traversal_post(root->left);
    traversal_post(root->right);
    cout<<root->val;
}

//层序遍历
void traversal_queue(BinaryTreeNode* root){
    queue<BinaryTreeNode*> q;
    if(root!= nullptr){
        q.push(root);
    }
    while(!q.empty()){
        //取出队头
        cout<<q.front()->val<<" ";
        //如果有孩子，把孩子按照左->右的顺序放入队列
        if(root->left!= nullptr){
            q.push(root->left);
        }
        if(root->right!= nullptr){
            q.push(root->right);
        }
        q.pop();
    }
}

//定义一个寻找向量中对应元素索引的函数
int find_index(vector<int> a,int d){
    vector<int>::iterator it=find(a.begin(),a.end(),d);
    return distance(begin(a),it);
}

//定义一个可以对vector片段进行截取的函数
vector<int> cut_vector(vector<int> op,int idx_h,int idx_t){
    vector<int>::const_iterator head=op.begin()+idx_h;
    vector<int>::const_iterator tail;
    if(idx_t==-1){
        tail=op.end();
    }
    else
        tail=op.begin()+idx_t;
    vector<int> new_vector(head,tail);
    return new_vector;
}

//根据前序和中序遍历重新构造二叉树
BinaryTreeNode* reConstructBinaryTree_with_PreAndVin(vector<int> pre, vector<int> vin){
    if(pre.size()==0 || vin.size()==0){
        return nullptr;
    }
    //找根
    int index=find_index(vin,pre[0]);
    //找左右子树
    vector<int> leftTree=cut_vector(vin,0,index);
    vector<int> rightTree=cut_vector(vin,index+1,-1);
    //建立新的二叉树
    BinaryTreeNode* node=(BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    node->val=vin[index];
    node->left=reConstructBinaryTree_with_PreAndVin(cut_vector(pre,1,index+1), leftTree);
    node->right=reConstructBinaryTree_with_PreAndVin(cut_vector(pre,index+1,-1),rightTree);
    return node;
}