#include <iostream>
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

	int ITra1(Node *root,int i,int *b)  //中序遍历显示
	{
		if (root != NULL)
		{
			i=ITra1(root->Leftchild,i,b);
			b[i] = root->data;
			i++;
			if (root == NULL)
				i--;
			i=ITra1(root->Rightchild,i,b);
		}
		return i;
	};
	void Fdata(Node *root,int *b,int n)
	{
		ITra1(root,0,b);
	}

};