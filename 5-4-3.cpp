#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

struct coordiantes
{
  float x;
  float y;
  coordiantes(float a=0,float b=0)
  {
    this->x=a;
    this->y=b;
  }
};

istream& operator >> (istream &in,coordiantes& a)
{
    in>>a.x>>a.y;
}

ostream& operator << (ostream &out,coordiantes a)
{
    out<<"("<<a.x<<","<<a.y<<")";
}

double area(coordiantes a,coordiantes b,coordiantes c)
{
    return ((a.x*b.y+b.x*c.y+c.x*a.y-a.y*b.x-b.y*c.x-c.y*a.x)*10);
}

bool in_area(coordiantes n,coordiantes a,coordiantes b,coordiantes c)
{
//    cout<<(int)(fabs(area(n,a,b))+fabs(area(n,b,c))+fabs(area(n,c,a))*100)-(int)(fabs(area(a,b,c))*100)<<endl;
    return (int)((fabs(area(n,a,b))+fabs(area(n,b,c))+fabs(area(n,c,a)))+0.5)==(int)(fabs(area(a,b,c))+0.5);
}

int main()
{
    int count=0;
    coordiantes a(10.7,6.9),b(8.5,1.5),c(14.5,1.5);
//    cin>>a>>b>>c;
//    coordiantes n(2,4);



//
//    float x=fabs(area(n,a,b))+fabs(area(n,b,c))+fabs(area(n,c,a));
//    float y=fabs(area(a,b,c));
//    cout<<setprecision(9)<<x<<"\n"<<setprecision(9)<<y<<endl;
//    x==y?cout<<1<<endl:cout<<0<<endl;
//    if(x==y)
//        cout<<"yes"<<endl;
//    else
//        cout<<"no"<<endl;




//    cout<<(int)in_area(n,a,b,c);

    for(double i=1;i<100;i++)
        for(double j=1;j<100;j++)
        {
            if(in_area(coordiantes(i,j),a,b,c))
            {
//                cout<<coordiantes(i,j)<<" ";
                count++;
            }
        }
    cout<<count<<endl;


    return 0;

}
