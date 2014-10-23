#include<iostream>
using namespace std;

struct TDir
{
	int key;
	TDir *befer=NULL,*next=NULL;
};

int main()
{
	int n = 0,k,sig=1;
	TDir *root,*p,*q,*sp;

	//构建双向链表
	cout << "输入元素的个数：";
	cin >> n;
	cout << "请依次输入关键字数据：" << endl;
	root = p = new TDir;
	cin >> root->key;
	for (int i = 0; i < n-1; i++)
	{
		q = new TDir;
		cin >> q->key;
		p->next = q;
		q->befer = p;
		p = q;
	}
	p->next = root;
	root->befer = p;

	//查找算法
	sp = root;
	while (sig!=0)
	{
		cout << "输入需要查找的k值：";
		cin >> k;
		if (k == sp->key)
			cout << "查找成功！     " << "定位查找步数：" << 0 << endl;
			else if (k>sp->key)
			for (int i = 0; i < n; i++)
			{
				if (k == sp->key)
				{
					cout << "查找成功！     " << "正向查找步数：" << i << endl;
					break;
				}
				if (i==n-1)
					cout << "查无此值！" << endl;
				sp = sp->next;
			}
			else
			for (int i = 0; i < n; i++)
			{
				if (k == sp->key)
				{
					cout << "查找成功！     " <<"反向查找步数："<<i<<endl;
					break;
				}
				if (i == n-1)
					cout << "查无此值！"<< endl;
				sp = sp->befer;
			}

		cout << "请选择是否继续查找(继续：1；退出：0)：";
		cin >> sig;
	}

	system("pause");
	return 0;
}