#include <iostream>
#include"查找相邻值.h"
using namespace std;

int main()
{
	int n, *a,sig=-1,s,*b,x,j=0;
	Ttree *shu;
	cout << "输入节点个数：";
	cin >> s;
	cout << "输入数组表示的数组总数n：";
	cin >> n;
	a = new int[n];
	cout << "请按照数组表示依次输入数据(无数据用0表示)：";
	for (int i = 0; i < n; i++)
		cin >> a[i];

	shu=new Ttree(a, n);
	cout << "中根遍历显示：";
	shu->ITra(shu->root);
	cout << endl;

	b = new int[s];
	int z = 1;

	while (z != 0)
	{
		cout << "请输入数值x：";
		cin >> x;
		shu->Fdata(shu->root, b, x);
		for (int i = 0; i < s; i++)
		if (b[i] == x)
			j = i;
		if (j == 0)
			cout << "无符合要求的小值！符合要求的大值为：" << b[j + 1];
		else if (j == n - 1)
			cout << "无符合要求的大值！符合要求的小值为：" << b[j - 1];
		else
			cout << "符合要求的小值为：" << b[j - 1] << ",符合要求的大值为：" << b[j + 1];
		cout << endl;

		cout << "输入1继续查找，输入0退出：";
		cin >> z;
	}

	system("pause");
	return 0;
}
