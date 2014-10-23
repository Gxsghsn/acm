#include <iostream>
#include"查找第k大的值.h"
using namespace std;

int main()
{
	int n, *a,s,k=1;
	Ttree *shu;
	cout << "输入节点个数：";
	cin >> s;
	cout << "输入数组表示的数组总数n：";
	cin >> n;
	a = new int[n];
	cout << "请按照数组表示依次输入数据：";
	for (int i = 0; i < n; i++)
		cin >> a[i];


	shu = MTree(a, n);
	cout << "中序遍历显示：";
	shu->ITra(shu->root);
	cout << endl;

	cout << "需要查找第几大的数:";
	cin >> k;
	while (k != 0)
	{
		shu->Find(shu->root, n - k + 1);
		cout << "输入0退出，或输入需要继续查找的编号k：";
		cin >> k;
	}

	system("pause");
	return 0;
}
