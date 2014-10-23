#include <iostream>
#include<cmath>
using namespace std;

struct Node
{
	int data;
	Node *Leftchild=NULL, *Rightchild=NULL;
};

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
			cout << root->data << "   ";
			ITra(root->Rightchild);
		}
	};
	friend int ITra1(Node *root, int i, int *b)  //中序遍历显示
	{
		if (root != NULL)
		{
			b[i] = root->data;
			i++;
			if (root == NULL)
				i--;
			i = ITra1(root->Leftchild, i, b);
			i = ITra1(root->Rightchild, i, b);
		}
		return i;
	};
	
};

void Insert(Node *root,int *b,int i)
{
	int s = 1;
	while (s!=0)
	{
		if (b[i] < root->data&&root->Leftchild != NULL)
			root = root->Leftchild;
		if (b[i] < root->data&&root->Leftchild == NULL)
		{
			root->Leftchild = new Node;
			root->Leftchild->data = b[i];
			s = 0;
		}
		if (b[i] >root->data&&root->Rightchild != NULL)
			root = root->Rightchild;
		if (b[i] >root->data&&root->Rightchild == NULL)
		{
			root->Rightchild = new Node;
			root->Rightchild->data = b[i];
			s = 0;
		}
	}
};

Ttree *MTree(Node *root1, Node *root2, int n1, int n2)
{
	Ttree *shu;
	int *b, i = 0;
	b = new int[n1 + n2];
	cout << "合并数组：";
	i = ITra1(root1, i, b);
	for (int j = 0; j < n1; j++)
		cout << b[j] << "  ";
	i = ITra1(root2, i, b);
	for (int j = i - n2; j <i; j++)
		cout << b[j] << "  ";
	cout << endl;

	int a[1];
	a[0] = b[0];
	shu = new Ttree(a, 1);
	
	for (int i = 1; i < n1 + n2; i++)
	{
		Insert(shu->root,b,i);
	}

	return shu;
};