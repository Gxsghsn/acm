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

	void ITra(Node *root)  //ÖÐÐò±éÀúÏÔÊ¾
	{

		if (root!=NULL)
		{
			ITra(root->Leftchild);
			cout << root->data << "   ";
			ITra(root->Rightchild);
		}
	};

	//11
	int flag=1;
	int pre=-1,next=-1;
	int pd(Node *root) 
	{
		// if(root!=NULL){
			// int a=root->data;
			// if(root->Leftchild!=NULL && root->Leftchild->data > root->data){ return 0;}
			// if(root->Rightchild!=NULL && root->Rightchild->data < root->data){return 0;}			
			// flag=pd(root->Leftchild);
			// flag=pd(root->Rightchild);

		// }
		// int n[len];
		// int ptr=0;
		// int pre=-1;
		// int next;
		if (root!=NULL)
		{
			pd(root->Leftchild);
			if(pre==-1){
				pre=root->data;
			}else{
				if(root->data < pre) return 0;
				pre=root->data;
			}
			if(root->data<pre) return 0;
			pd(root->Rightchild);
		}
		// for(int i=0;i<len-1;i++) if(n[i]>n[i+1]) return 0;
		return 1;
	};

	//12
	// int search(int x,Node *root){
	// 	if(x>root->data) 
	// }

	//18
	void Insert(Node *root,int *b,int i)
	{
		int s = 1;
		cout<<"b"<<endl;
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
		cout<<"c"<<endl;
	};


	int ITra1(Node *root, int i, int *b)  
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


	Ttree *MTree(Node *root1, Node *root2, int n1, int n2)
	{
		Ttree *shu;
		int *b, i = 0;
		b = new int[n1 + n2];
		i = ITra1(root1, i, b);
		i = ITra1(root2, i, b);
		cout << endl;

		int a[1];
		a[0] = b[0];
		shu = new Ttree(a, 1);
		
		for (int i = 1; i < n1 + n2; i++)
		{
			cout<<"a"<<endl;
			Insert(shu->root,b,i);
		}
		ITra(shu->root);
		return shu;
	};



	//12
	// int flag=1;
	// int pre=-1,next=-1;
	int pre1=-1;
	int pd1(Node *root,int num) 
	{
		if (root!=NULL)
		{
			pd1(root->Leftchild,num);
			if(pre1==-1){
				pre1=root->data;
			}else{
				if(root->data >= num){cout<<pre1<<endl;cout<<root->data<<endl;}
				pre1=root->data;
			}
			if(root->data<pre1) return 0;
			pd1(root->Rightchild,num);
		}
		// for(int i=0;i<len-1;i++) if(n[i]>n[i+1]) return 0;
		return 1;
	};
};

