#include <iostream>
#include"合并排序二叉树.h"
using namespace std;

int main()
{
	int n, *a,s1,s2;
	Ttree *shu1,*shu2,*shu;
	cout << "输入节点个数：";
	cin >> s1;
	cout << "输入数组1表示的数组总数n：";
	cin >> n;
	a = new int[n];
	cout << "请按照数组1表示依次输入数据(无数据用0表示)：";
	for (int i = 0; i < n; i++)
		cin >> a[i];

	shu1=new Ttree(a, n);
	cout << "遍历显示：";
	shu1->ITra(shu1->root);
	cout << endl;

	cout << "输入节点个数：";
	cin >> s2;
	cout << "输入数组2表示的数组总数n：";
	cin >> n;
	a = new int[n];
	cout << "请按照数组2表示依次输入数据(无数据用0表示)：";
	for (int i = 0; i < n; i++)
		cin >> a[i];

	shu2 = new Ttree(a, n);
	cout << "遍历显示：";
	shu2->ITra(shu2->root);
	cout << endl;

	shu = MTree(shu1->root, shu2->root, s1, s2);
	cout << "合成二叉排序树的中根遍历输出：";
	shu->ITra(shu->root);
	cout << endl;

	//system("pause");
	return 0;
}
