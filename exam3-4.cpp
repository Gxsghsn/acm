#include<iostream>
#include<fstream>
#include<ctype.h>
using namespace std;


int main()
{
    ifstream fin("exam3-4.in");
    string buf,s;
    int max=0,locat=0,i=0,j=0;
    getline(fin,buf);
    int len = buf.length();

    //put upper alpha in s
    for(int i=0;i<len;i++)
        if(isalpha(buf[i]))
            s+=toupper(buf[i]);
    int lens = s.length();

    //get the longest moslem in s
    for(i=0;i<lens;i++)
    {
        if(s[i]==s[i+1])
        {
            for(j=0;(i-j)>=0 && (i+2+j)<lens && s[i-j]==s[i+1+j];j++){}   j-=1;
            if(j*2+2>max)
            {
//                cout<<"i:"<<i<<" j:"<<j<<" lens:"<<lens<<" max:"<<max<<endl;
                max=j*2+2;
                locat = i-j;
            }
        }

        if(s[i]==s[i+2])
        {
            for(j=0;(i-j)>=0 && (i+j+3)<lens && s[i-j]==s[i+2+j];j++){}   j-=1;
            if(j*2+3>max)
            {
//                cout<<"i:"<<i<<" j:"<<j<<" lens:"<<lens<<" max:"<<max<<endl;
                max=j*2+3;
                locat = i-j;
            }
        }
    }

    //print the longest moslem in buf
    cout<<max<<endl;
    for(int i=0;i<max;i++)
        cout<<s[locat+i];
    fin.close();
    return 0;
}
