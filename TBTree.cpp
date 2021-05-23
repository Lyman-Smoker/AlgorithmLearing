//
// Created by lym on 2021-03-15.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
/**************
 * 线索二叉树
 * 创建线索二叉树的目的是提高遍历过程的效率。但代价是存储性能会被牺牲
 * 每个二叉树对应三个线索树——先序、中序、后序
 */

// 首先定义一个线索二叉树的节点
typedef struct node{
    int data;   // 节点数据域
    int ltag,rtag;  //增加的线索标记
    struct node * lchild;//左孩子
    struct node * rchild;//右孩子
}TBTNode;

// 这里以中序为例子，构建中序线索二叉树
TBTNode * pre;//全局变量
void Thread(TBTNode*&p){
    if (p!=NULL){
        Thread(p->lchild);//左
        //根
        if(p->lchild==NULL){
            p->lchild=pre;
            p->ltag=1;
        }
        else
            p->ltag=0;
        if(pre->rchild==NULL){
            pre->rchild=p;
            pre->rtag=1;
        }
        else
            pre->rtag=0;
        pre=p;
        Thread(p->rchild);//右
    }
}

TBTNode * CreateThread(TBTNode* b){
    TBTNode * root;
    root=(TBTNode *)malloc(sizeof(TBTNode));
    root->ltag=0;root->rtag=1;
    root->rchild=b;
    if(b==NULL)
        root->lchild=root;
    else{
        root->lchild=b;
        pre=root;
        Thread(b);
        pre->rchild=root;
        pre->rtag=1;
        root->rchild=pre;
    }
    return root;
}