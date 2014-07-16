#include <iostream>
#include <string>
using namespace std;

int is_digit(string s,int i)
{
	int n=0;
	if(s[i]>='0'&&s[i]<='9')
	{
		n=(int)s[i]-48;
	}
	return n;
}



int main(int argc, char const *argv[])
{
	string s;
	s="ba2b3b1a4b5a";
	string a;
	string k[10];
	int kn=0;
	string s1;
	int n=0;
	for(int i=0;i<s.length();i++)
	{
		if(is_digit(s,i))      //is digit
		{
			// cout<<s1<<endl;
			n*=10;n+=is_digit(s,i);
		}
		else                   //is letter
		{
			if(n!=0)
			{
				k[kn]=k[n-1]+s[i];
				// cout<<"n "<<n-1<<" k[n]: "<<k[n]<<" i: "<<i<<" s[i]: "<<s[i]<<" k[kn]: "<<k[kn]<<endl;
				a+=k[kn];
				n=0;
				kn++;
			}
			else 
			{
				k[kn]=s[i];
				kn++;
				a+=s[i];
			}
		}
	}

	cout<<s<<endl;
	cout<<a<<endl;
	return 0;
}