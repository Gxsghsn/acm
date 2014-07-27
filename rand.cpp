//#include<iostream>
//#include<cstdlib>
//#include<ctime>
//using namespace std;
//int n=100,m=100000;
//
//double  random()
//{
//    return (double)rand()/RAND_MAX;
//}
//
//int random(int m)
//{
//    return (int)(random()*(m-1)+0.5);
//}
//
//int main()
//{
//    srand(time(NULL));
//    cout<<n<<m<<endl;
//    for(int i=0;i<m;i++)
//    {
//        if(rand()%2==0) cout<<"A";
//        else cout<<"B";
//        int X,Y;
//        for(;;)
//        {
//            X=random(n)+1;
//            Y=random(n)+1;
//            if(X!=Y) break;
//        }
//        cout<<X<<" "<<Y<<endl;
//    }
//    return 0;
//}


#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    for(int i=0;i<10;i++)
        cout<<rand()%10<<endl;
    return 0;
}
