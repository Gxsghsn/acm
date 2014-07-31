#include<iostream>
//#include<memory>
//#include<memory.h>
using namespace std;
int maze[10][10];

struct point
{
    int x;
    int y;
//    int have_
    point(int a=0,int b=0){this->x=a; this->y=b;}

    point operator = (point a)
    {
        this->x = a.x;
        this->y = a.y;
        return *this;
    }
    bool operator == (point a)
    {
        if(this->x==a.x&&this->y==a.y)
            return true;
        return false;
    }
    bool operator != (point a)
    {
        return !(*this==a);
    }
};

point a[100],test;
int pointptr=0;

ostream& operator << (ostream &out,point x)
{
    out<<x.x<<" "<<x.y;
    return out;
}

int find_around_end(point start,point end)
{

    if(start.x-1==end.x&&start.y==end.y) {cout<<"find"<<endl;maze[start.x][start.y]=2;test.x=start.x;test.y=start.y;return 1;}
    if(start.x+1==end.x&&start.y==end.y) {cout<<"find"<<endl;maze[start.x][start.y]=2;test.x=start.x;test.y=start.y;return 1;}
    if(start.x==end.x&&start.y-1==end.y) {cout<<"find"<<endl;maze[start.x][start.y]=2;test.x=start.x;test.y=start.y;return 1;}
    if(start.x==end.x&&start.y+1==end.y) {cout<<"find"<<endl;maze[start.x][start.y]=2;test.x=start.x;test.y=start.y;return 1;}
    maze[start.x][start.y]=3;
//    for(int i=0;i<10;i++){
//        for(int j=0;j<10;j++){
//            cout<<maze[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    cout<<"now start"<<start<<endl;
    if(maze[start.x-1][start.y]==0) {point x(start.x-1,start.y);a[pointptr]=x;pointptr++;}
    if(maze[start.x+1][start.y]==0) {point x(start.x+1,start.y);a[pointptr]=x;pointptr++;}
    if(maze[start.x][start.y-1]==0) {point x(start.x,start.y-1);a[pointptr]=x;pointptr++;}
    if(maze[start.x][start.y+1]==0) {point x(start.x,start.y+1);a[pointptr]=x;pointptr++;}
    return 0;
}

//int find_around()

int findpath(point ostart,point end)
{
//    cout<<"start"<<start<<endl;
//    for(int i=0;i<pointptr;i++)
//            cout<<"---------a[]  "<<a[i].x<<" "<<a[i].y<<"    ";
    while(ostart!=end){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(maze[i][j]==3)
                    maze[i][j]=0;
            }
        }
//        cout<<endl;
//        for(int i=0;i<10;i++){
//            for(int j=0;j<10;j++){
//                cout<<maze[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        point start=ostart;
        memset(a,0,sizeof(a));
        int afront=0;
        pointptr=0;
        while(find_around_end(start,end)!=1){
    //        for(int i=0;i<pointptr;i++)
    //            cout<<afront<<"a[]  "<<a[i]<<"    ";
            start = a[afront];
    //        cout<<"start "<<start<<endl;
            afront++;
        }
        cout<<"here"<<endl;
        end=test;
        cout<<end<<endl;
    }

}

int main()
{
    freopen("6-4-2.txt","r",stdin);
//    memset(maze,1,sizeof(maze));
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            maze[i][j]=1;

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>maze[i+1][j+1];

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }

    point start;
    point end;
    cin>> start.x >> start.y >> end.x >> end.y;
    start.x++;start.y++;end.x++;end.y++;
//    cout<<end.x<<end.y<<endl;
    maze[end.x][end.y]=8;
//    point test(7,7);
//    cout<<(point)(7,7)<<" "<<test<<endl;
    findpath(start,end);

    cout<<endl;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
