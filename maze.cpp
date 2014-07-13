#include<iostream>
using namespace std;

int path[100];
int pathnum=0;

int findpath(int maze[10][10],int a,int b)
{
    int i=a,j=b;
    int flag=0;
    maze[i][j]=1;
    if(maze[i-1][j]==0&&i<=9&&i-1>=0&&j>=0&&j<=9)
    {
        i-=1;
        if(i==0&&j==9)
        {
            path[pathnum]=i;
            path[pathnum+1]=j;
            pathnum+=2;
            return 1;
        }
        flag=findpath(maze,i,j);
        if(flag==1)
        {
            path[pathnum]=i;
            path[pathnum+1]=j;
            pathnum+=2;
            return 1;
        }
        i+=1;

    }
    if(maze[i+1][j]==0&&i+1<=9&&i>=0&&j>=0&&j<=9)
    {
        i+=1;
        if(i==0&&j==9)
        {
            path[pathnum]=i;
            path[pathnum+1]=j;
            pathnum+=2;
            return 1;
        }
        flag=findpath(maze,i,j);
        if(flag==1)
        {
            path[pathnum]=i;
            path[pathnum+1]=j;
            pathnum+=2;
            return 1;
        }
        i-=1;
    }
    if(maze[i][j-1]==0&&i<=9&&i>=0&&j-1>=0&&j<=9)
    {
        j-=1;
        if(i==0&&j==9)
        {
            path[pathnum]=i;
            path[pathnum+1]=j;
            pathnum+=2;
            return 1;
        }
        flag=findpath(maze,i,j);
        if(flag==1)
        {
            path[pathnum]=i;
            path[pathnum+1]=j;
            pathnum+=2;
            return 1;
        }
        j+=1;
    }
    if(maze[i][j+1]==0&&i<=9&&i>=0&&j>=0&&j+1<=9)
    {
        j+=1;
        if(i==0&&j==9)
        {
            path[pathnum]=i;
            path[pathnum+1]=j;
            pathnum+=2;
            return 1;
        }
        flag=findpath(maze,i,j);
        if(flag==1)
        {
            path[pathnum]=i;
            path[pathnum+1]=j;
            pathnum+=2;
            return 1;
        }
        j-=1;

    }
    return 0;
}



int main()
{
    int maze[10][10]={
                    {1,0,1,1,1,1,1,1,1,0},
                    {1,0,0,0,0,0,0,0,0,0},
                    {1,0,1,1,1,1,1,1,1,0},
                    {1,0,1,1,1,0,1,1,1,0},
                    {1,0,1,1,0,0,0,0,0,0},
                    {0,0,1,1,0,1,0,1,1,1},
                    {0,1,1,1,1,0,0,0,1,1},
                    {0,0,0,0,1,0,1,0,0,0},
                    {1,1,1,1,1,1,1,1,1,0},
                    {0,0,0,0,0,0,0,0,0,0}
                 };
//    for(int i=0;i<=9;i++)
//    {
//        for(int j=0;j<=9;j++)
//        {
//            if(maze[i][j]!=0)
//                cout<<'X';
//            else
//                cout<<'0';
//        }
//        cout<<endl;
//    }
    int flag;
    int i=9,j=0;
    path[pathnum]=0;
    path[pathnum+1]=9;
    pathnum+=2;
    flag = findpath(maze,i,j);
    path[pathnum]=i;
    path[pathnum+1]=j;
    if(flag==1)
    {
        for(int i=pathnum;i>=0;i-=2)
            cout<<path[i]<<" "<<path[i+1]<<endl;
    }
    else
        cout<<"no path"<<endl;
    return 0;
}

