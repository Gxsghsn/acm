#include <iostream>
#include"��������ֵ.h"
using namespace std;

int main()
{
	int n, *a,sig=-1,s,*b,x,j=0;
	Ttree *shu;
	cout << "����ڵ������";
	cin >> s;
	cout << "���������ʾ����������n��";
	cin >> n;
	a = new int[n];
	cout << "�밴�������ʾ������������(��������0��ʾ)��";
	for (int i = 0; i < n; i++)
		cin >> a[i];

	shu=new Ttree(a, n);
	cout << "�и�������ʾ��";
	shu->ITra(shu->root);
	cout << endl;

	b = new int[s];
	int z = 1;

	while (z != 0)
	{
		cout << "��������ֵx��";
		cin >> x;
		shu->Fdata(shu->root, b, x);
		for (int i = 0; i < s; i++)
		if (b[i] == x)
			j = i;
		if (j == 0)
			cout << "�޷���Ҫ���Сֵ������Ҫ��Ĵ�ֵΪ��" << b[j + 1];
		else if (j == n - 1)
			cout << "�޷���Ҫ��Ĵ�ֵ������Ҫ���СֵΪ��" << b[j - 1];
		else
			cout << "����Ҫ���СֵΪ��" << b[j - 1] << ",����Ҫ��Ĵ�ֵΪ��" << b[j + 1];
		cout << endl;

		cout << "����1�������ң�����0�˳���";
		cin >> z;
	}

	system("pause");
	return 0;
}
