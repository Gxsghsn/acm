#include<iostream>
#include<memory.h>
using namespace std;
const int maxn=1000;

struct bign;
istream& operator >> (istream &in, bign& x);
ostream& operator <<(ostream &out, const bign& x);

struct bign
{
    int len,s[maxn];
    bign(){memset(s,0,sizeof(s)); len=1;}

    bign operator = (const char* num)
    {
        len = strlen(num);
        for(int i=0;i<len;i++)
            s[i] = num[len-i-1]-'0';
        return *this;
    }

//    bign operator = (bign& b)
//    {
//        len = b.len;
//        for(int i=0;i<len;i++)
//            s[i]=b.s[i];
//        return *this;
//    }

    bign operator = (const int num)
    {
        char s[maxn];
        sprintf(s,"%d",num);
        *this = s;
        return *this;
    }

    bign(int num){*this = num;}

    bign(const char* num){*this = num;}

    string str() const
    {
        string res = "";
        for(int i=0;i<len;i++) res=(char)(s[i]+'0')+res;
        if(res=="") res="0";
        return res;
    }

    bign operator + (const bign& b) const                //+
    {
        bign c;
        c.len=0;
        for(int i=0,g=0;g||i<max(len,b.len);i++)
        {
//            int x=g;
//            if(i<len) x+=s[i];
//            if(i<b.len) x+=b.s[i];
//            c.s[c.len++] = x%10;
//            g = x/10;
            if(i<len) g+=s[i];
            if(i<b.len) g+=b.s[i];
            c.s[c.len++] = g%10;
            g/=10;
        }
        return c;
    }

    bign operator += (const bign& b)                  //+=
    {
        *this = *this +b;
        return *this;
    }

    bign operator - (const bign& b)  const              //-
    {
        if(*this<b)
        {
            cout<<"error"<<endl;
            return -1;
        }
        bign c = b;
        for(int i=0;i<max(c.len,b.len);i++)
        {
            if(c.s[i]<b.s[i])
            {
                c.s[i]+=10;
                c.s[i+1]--;
            }
            c.s[i]=s[i]-b.s[i];
            c.len++;
        }
        return c;
    }

    bign operator -= (const bign& b)                     //-=
    {
        *this = *this - b;
        return *this;
    }

    bign operator * (const int& b) const                 //*
    {
        bign c;
        int n=0;
        c.len=0;
        for(int i=0;i<len||n>=1;i++)
        {
            n+=s[i]*b;
            c.s[i]=n%10;
            c.len++;
            n/=10;
        }
        return c;
    }

    bign operator *= (const int b)                         //*=
    {
        *this = *this * b;
        return *this;
    }

    bool operator > (const bign b) const                 //>
    {
        if(len!=b.len)  return len>b.len;
        for(int i=len-1;i>=0;i--)
            if(s[i]!=b.s[i])
                return s[i]>b.s[i];
        return false;
    }

    bool operator >= (const bign b) const                //>=
    {
        return !(b>*this);
    }

    bool operator < (const bign b) const                 //<
    {
        return b>*this;
    }

    bool operator <= (const bign b) const               //<=
    {
        return !(*this>b);
    }

    bool operator == (const bign b) const                       //==
    {
        return !(*this>b||b>*this);
    }

    bool operator != (const bign b) const               //!=
    {
        return (*this>b||b>*this);
    }
};

istream& operator >> (istream &in, bign& x)
{
    string s;
    in>>s;
    x = s.c_str();
    return in;
}

ostream& operator <<(ostream &out, const bign& x)
{
    out<<x.str();
    return out;
}

int main()
{
    bign x(50);
    bign y = 40;
    y *= 5;
    cout<<x<<endl;
    cout<<y*5<<endl;
    cout<<y<<endl;
    cout<<(x==y)<<endl;

    return 0;
}





//    int a=0;
//    for(int i=0;i<a.len||i<b.len;i++)
//    {
//        a+=a.s[i]+b.s[i];
//        c.s[i]=a%10;
//        a/=10;
//    }
