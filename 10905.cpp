#include<iostream>
#include<cmath>
using namespace std;
int num[50];
int non;

//int compare(int maxindex,int weishu)
//{
////	int max=
//	for(int i=0;i<non;i++){
//		int a=num[i];
//		int noequal=1;
//		while(a>=sqrt(10,weishu)) a/=10;
//		if(a>max){
//			max=a;
//			return i;
//		}
//		if(a=max){
//			noequal=0;
//			compare(max,weishu+1);
//		}
//	}
//}

int main()
{
	// freopen("10905.txt","r",stdin);
	// cin>>non;
	// while(non>0){
	// 	for(int i=0;i<n;i++) cin>>num[i];
	// 	int max=0;
	// }

	int n=1234;
	int a=pow(10.0,3.0);
	while(n>a) a/=10;
    while(a>10) a%=10;
	cout<<a<<endl;
	return 0;
}
