#include <iostream>
#include <cstdio>
using namespace std;


struct tree{
    tree *firstchild;
    int data;
    tree *nextsibling;
};

void show(tree father,tree a);
void show_from_root(tree root)
{
//    cout<<"*"<<endl;
    show(root,*root.firstchild);
}

void show(tree father,tree a)
{
//    printf("(%d,%d)",)
//    if(father==NULL){show(a,a.firstchild);break;}
//    cout<<"**"<<endl;
    while(a.nextsibling!=NULL){
        printf("(%d,%d)",father.data,a.data);
        show(father,*a.nextsibling);
    }
    show(a,*a.firstchild);
}


int main()
{
    tree a,b,c,d,e,f;
    a.data=1;
    b.data=2;
    c.data=3;
    d.data=4;
    e.data=5;
    f.data=6;
    a.nextsibling=&b;
    b.nextsibling=&c;
    a.firstchild=&d;
    b.firstchild=&e;
    d.nextsibling=&f;
    tree root;
    root.firstchild=&a;
    show_from_root(root);
    return 0;
}









#include<iostream>
#include "treelib.h"
#include "treeprnt.h"
#include "treeexch.h"
#include "treescan.h"
using namespace std;
#include "stack.h"
#include "treescan.h"
int main()
{
    Stack<TreeNode<char>*> p;
    TreeNode<char> *root;
    TreeNode<char> *root2;
    MakeCharTree(root,1);
    root2 = CopyTree(root);
    cout<<"1:"<<endl;
    printVVtree(root,1,30);
    TreeNode<char> *gofarleft;
    gofarleft = GoFarLeft(root,p);
    cout<<endl<<gofarleft->data;
    cout<<endl<<"preorder:";
    Preorder(root);
    cout<<endl;
    
    cout<<endl<<"2:"<<endl;
    printVVtree(root2,1,30);
    //printVVtree(root,1,30);
    cout<<endl;
    int count=0;
    CountLeaf(root,count);
    cout<<"count:"<<count<<endl;
    cout<<"depth:"<<Depth(root)<<endl;
//  cout<<Depth(root);
//  cout<<"交换后："<<endl;
//  root = exchange(root);
//  printVVtree(root,1,30);
    cout<<endl;
    ClearTree(root);
    cout<<"root:"<<root<<endl;
    int a;
    cin>>a;
}