#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	int a[6][6];
	int x=0,y=5,c=1,num=36;

	while(c<4)
	{
		while(x<=5-c) {a[x][y]=num;x++;num--;}
		while(y>=c) {a[x][y]=num;y--;num--;}
		while(x>=c) {a[x][y]=num;x--;num--;}
		c++;
		while(y<=5-c) {a[x][y]=num;y++;num--;}
		//cout<<"x:"<<x<<" y:"<<y<<" num:"<<num<<endl;
	}
	a[x][y]=num;



	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			cout<<setw(2)<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return	0;
}

