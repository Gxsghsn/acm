#include <iostream>
#include<cmath>
using namespace std;

struct Node
{
	int data,lsize;
	Node *Leftchild,*Rightchild,*Befor;
};
int data=1,lsize=1;
Node *Leftchild=NULL;
Node *Rightchild=NULL;
Node *Befor=NULL;
class Ttree
{
private:
	
public:
	Node *root;
	Ttree(int *a,int n)
	{
		Node **p;
		p = new Node*[n];
		root=p[0] = new Node;
		root->data = a[0];
		for (int i = 1; i < n;i++)
		{
			if (a[i]!=0&&i%2==1)
			{
				p[(i-1)/2]->Leftchild = p[i] = new Node;
				p[i]->data = a[i];
			}
			if (a[i] != 0 && i % 2 == 0)
			{
				p[(i - 2)/2]->Rightchild = p[i] = new Node;
				p[i]->data = a[i];
			}
		}
	};

	void ITra(Node *root)  //中序遍历显示
	{
		if (root!=NULL)
		{
			ITra(root->Leftchild);
			cout << "数据：" << root->data << " " << "子树：" << root->lsize << ";" << "   ";
			ITra(root->Rightchild);
		}
	};

	void Find(Node *root,int k)
	{
		if (root != NULL)
		{

			Find(root->Leftchild, k);
			if (root == root->Befor->Leftchild&&root->lsize == k)
				cout << "查找的第" << k << "大的数据是：" << root->data << endl;
			else if (root==root->Befor->Rightchild&&root->lsize+root->Befor->lsize==k)
				cout << "查找的第" << k << "大的数据是：" << root->data << endl;
			Find(root->Rightchild, k);
		}
	};
};

void Insert(Node *root,int *b,int i)
{
	int s = 1;
	while (s!=0)
	{
		if (b[i] < root->data&&root->Leftchild != NULL)
		{
			root->lsize = root->lsize++;
			root = root->Leftchild;
		}
		if (b[i] < root->data&&root->Leftchild == NULL)
		{
			root->lsize = root->lsize++;
			root->Leftchild = new Node;
			root->Leftchild->Befor = root;
			root->Leftchild->data = b[i];
			s = 0;
		}
		if (b[i] >root->data&&root->Rightchild != NULL)
			root = root->Rightchild;
		if (b[i] >root->data&&root->Rightchild == NULL)
		{
			root->Rightchild = new Node;
			root->Rightchild->Befor = root;
			root->Rightchild->data = b[i];
			s = 0;
		}
	}
};

Ttree *MTree(int *b, int n)
{
	Ttree *shu;
	Node *zero;
	int i = 0;
	int a[1];
	a[0] = b[0];
	
	zero = new Node;
	shu = new Ttree(a, 1);
	shu->root->Befor=zero;
	zero->Leftchild = shu->root;
	for (i = 1; i < n; i++)
	{
		Insert(shu->root,b,i);
	}

	return shu;
};