#include <iostream>
#include"�ϲ����������.h"
using namespace std;

int main()
{
	int n, *a,s1,s2;
	Ttree *shu1,*shu2,*shu;
	cout << "����ڵ������";
	cin >> s1;
	cout << "��������1��ʾ����������n��";
	cin >> n;
	a = new int[n];
	cout << "�밴������1��ʾ������������(��������0��ʾ)��";
	for (int i = 0; i < n; i++)
		cin >> a[i];

	shu1=new Ttree(a, n);
	cout << "������ʾ��";
	shu1->ITra(shu1->root);
	cout << endl;

	cout << "����ڵ������";
	cin >> s2;
	cout << "��������2��ʾ����������n��";
	cin >> n;
	a = new int[n];
	cout << "�밴������2��ʾ������������(��������0��ʾ)��";
	for (int i = 0; i < n; i++)
		cin >> a[i];

	shu2 = new Ttree(a, n);
	cout << "������ʾ��";
	shu2->ITra(shu2->root);
	cout << endl;

	shu = MTree(shu1->root, shu2->root, s1, s2);
	cout << "�ϳɶ������������и����������";
	shu->ITra(shu->root);
	cout << endl;

	//system("pause");
	return 0;
}
