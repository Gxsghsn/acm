#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
	/* code */
	// cout<<"abc"<<endl;
	int maxsum=0;
	int s[100];
	s[0]=0;
	for(int i=1;i<100;i++){
		s[i]=s[i-1]+i;
	}
	for(int i=1;i<100;i++)
		for(int j=0;j<i;j++)
			if(s[i]-s[j]>maxsum) maxsum=s[i]-s[j];
	cout<<maxsum<<endl;
	int a=1;
	// cout<<a<<endl;
	cin>>a;
	// cout<<a<<endl;
	return 0;
}




// c:/program files (x86)/codeblocks/mingw/bin/../lib/gcc/mingw32/4.7.1/../../../../mingw32/bin/ld.exe: cannot open output file C:\Users\gaoxin\Desktop\acm/8-1-1.exe: Permission denied
// collect2.exe: error: ld returned 1 exit status
// [Finished in 0.3s with exit code 1]