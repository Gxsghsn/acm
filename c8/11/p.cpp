#include <iostream>
#include "p.h"
using namespace std;

int main()
{
	int n1, *a,sig=-1;
	Ttree *shu;
	cin >> n1;
	a = new int[n1];
	for (int i = 0; i < n1; i++)
		cin >> a[i];

	shu=new Ttree(a, n1);
	shu->ITra(shu->root);
	cout << endl;
	

	//11
	// sig = shu->pd(shu->root);
	// if (sig == 1)
	// 	cout<<"yes"<<endl;
	// if (sig == 0)
	// 	cout<<"no"<<endl;
	//12
	// int searnum=5;
	// shu->pd1(shu->root,searnum);



	//18
	int n2, *b;
	Ttree *shu2;
	cin >> n2;
	b = new int[n2];
	for (int i = 0; i < n2; i++)
		cin >> b[i];

	shu2=new Ttree(b, n2);
	// shu2->ITra(shu2->root);
	// cout << endl;

	Ttree *shu3;
	// shu3=new Ttree(a, n1+n2);
	shu3=shu2->MTree(shu->root,shu2->root,n1,n2);
	// shu3->ITra(shu3->root);



	return 0;
}
