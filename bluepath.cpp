#include<iostream>
#include<iomanip>
//#include<windows.h>
using namespace std;

char path[100];
int pathnum=0;

int findpath(char maze[10][10],int a,int b,int num0)
{
    int i=a,j=b;
    int flag=0;
    maze[i][j]=1;
    if(maze[i-1][j]==0&&i<=9&&i-1>=0&&j>=0&&j<=9)
    {
        i-=1;
        num0--;
//        if(num0==0)
//        {
////            path[pathnum]='^';
////            pathnum++;
//            return 1;
//        }
//        flag=findpath(maze,i,j,num0);
        if(num0==0||findpath(maze,i,j,num0))
        {
            maze[i+1][j]='^';
            path[pathnum]='^';
            pathnum++;
            return 1;
        }
        num0++;
        i+=1;
    }
    if(maze[i+1][j]==0&&i+1<=9&&i>=0&&j>=0&&j<=9)
    {
        i+=1;
        num0--;
//        if(num0==0)
//        {
////            path[pathnum]='|';
////            pathnum++;
//            return 1;
//        }
//        flag=findpath(maze,i,j,num0);
        if(num0==0||findpath(maze,i,j,num0))
        {
            maze[i-1][j]='|';
            path[pathnum]='|';
            pathnum++;
            return 1;
        }
        num0++;
        i-=1;
    }
    if(maze[i][j-1]==0&&i<=9&&i>=0&&j-1>=0&&j<=9)
    {
        j-=1;
        num0--;
//        if(num0==0)
//        {
////            path[pathnum]='<';
////            pathnum++;
//            return 1;
//        }
//        flag=findpath(maze,i,j,num0);
        if(num0==0||findpath(maze,i,j,num0))
        {
            maze[i][j+1]='<';
            path[pathnum]='<';
            pathnum++;
            return 1;
        }
        num0++;
        j+=1;
    }
    if(maze[i][j+1]==0&&i<=9&&i>=0&&j>=0&&j+1<=9)
    {
        j+=1;
        num0--;
//        if(num0==0)
//        {
////            path[pathnum]='>';
////            pathnum++;
//            return 1;
//        }
//        flag=findpath(maze,i,j,num0);
        if(num0==0||findpath(maze,i,j,num0))
        {
            maze[i][j-1]='>';
            path[pathnum]='>';
            pathnum++;
            return 1;
        }
        num0++;
        j-=1;

    }
    maze[i][j]=0;
    return 0;
}


int main()
{
    char maze[10][10]={
                    {0,0,0,0,1,0,1,1,1,1},
                    {0,0,0,0,0,0,1,1,1,1},
                    {0,0,0,0,0,0,1,1,1,1},
                    {1,0,0,0,0,1,1,1,1,1},
                    {0,0,0,0,0,0,1,1,1,1},
                    {0,1,1,1,0,0,1,1,1,1},
                    {0,1,0,0,0,0,1,1,1,1},
                    {0,0,0,0,0,0,1,1,1,1},
                    {1,1,1,1,1,1,1,1,1,1},
                    {1,1,1,1,1,1,1,1,1,1}
                    };
    int i1=0,j1=3;
    //the number of 0
    int num0 = 0;
    for(int i=0;i<=9;i++)
    {
        for(int j=0;j<=9;j++)
        {
            if(maze[i][j]==0)
                num0++;
        }
    }
    num0--;
    int flag;
    flag = findpath(maze,i1,j1,num0);
    if(flag==1)
    {
//        for(int i=pathnum-1;i>=0;i--)
//            cout<<path[i]<<" ";
        for(int i=0;i<=9;i++)
        {
            for(int j=0;j<=9;j++)
            {
                if(maze[i][j]==1)
                    cout<<"@ ";
                else if(maze[i][j]==0)
                    cout<<"* ";
                else
                {
//                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
//            FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    cout<<maze[i][j]<<" ";
                }
            }
            cout<<endl;
        }

    }
    else
        cout<<"no path"<<endl;

    return 0;
}
