#include<iostream>
#include<iomanip>
#include<windows.h>
using namespace std;

char path[100];
int pathnum=0;

int findpath(unsigned char maze[10][10],int a,int b,int num0)
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
//            path[pathnum]='|';
//            pathnum++;
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
    unsigned char maze[10][10]={
                    {0,0,0,0,0,0,1,1,1,1},
                    {0,1,0,0,0,0,1,1,1,1},
                    {0,1,0,0,0,0,1,1,1,1},
                    {0,0,0,0,0,1,1,1,1,1},
                    {0,0,0,0,0,1,1,1,1,1},
                    {0,0,0,1,0,0,1,1,1,1},
                    {0,0,0,0,0,0,1,1,1,1},
                    {1,0,0,0,1,0,1,1,1,1},
                    {1,1,1,1,1,1,1,1,1,1},
                    {1,1,1,1,1,1,1,1,1,1}
                    };
    int i1=6,j1=0;
    int width=8,height=6;
    /*cout<<"please input height and width"<<endl;
    cin>>width>>height;
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            if(i>=width||j>=height)
                maze[i][j]=1;
            else 
                maze[i][j]=0;
        }
    cout<<"please input starting location"<<endl;
    cin>>i1>>j1;
    i1--;j1--;
    cout<<"please input location of red blocks,ctrl+z to finish"<<endl;
    int x,y;
    while(cin>>x>>y)
    {
        maze[x-1][y-1]=1;
    }*/
    
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
       for(int i=pathnum-1;i>(pathnum-1)/2;i--)
       {
            // cout<<path[i]<<" ";    
            char a = path[i];
            path[i] = path[pathnum-1-i];
            path[pathnum-1-i] = a;
       }

       /*for(int i=0;i<=pathnum-1;i++)
            cout<<path[i]<<" ";*/
        unsigned char maze1[10][10];
        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
                maze1[i][j]=maze[i][j];

        for(int a=num0,i=i1,j=j1;num0>=0;num0--)
        {   
            if(maze[i][j]=='^'&&maze[i-1][j]=='^')    //^^
            {
                maze1[i-1][j]=(unsigned char)179;
                i-=1;
            }
            if(maze[i][j]=='^'&&maze[i-1][j]=='<')     //^<
            {
                maze1[i-1][j]=(unsigned char)191;
                i-=1;
            }
            if(maze[i][j]=='^'&&maze[i-1][j]=='>')      //^>
            {
                maze1[i-1][j]=(unsigned char)218;
                i-=1;
            }
            if(maze[i][j]=='|'&&maze[i+1][j]=='|')      //||
            {
                maze1[i+1][j]=(unsigned char)179;
                i+=1;
            }
            if(maze[i][j]=='|'&&maze[i+1][j]=='<')         //|<
            {
                maze1[i+1][j]=(unsigned char)217;
                i+=1;
            }
            if(maze[i][j]=='|'&&maze[i+1][j]=='>')          //|>
            {
                maze1[i+1][j]=(unsigned char)192;
                i+=1;
            }
            if(maze[i][j]=='<'&&maze[i][j-1]=='^')          //<^
            {
                maze1[i][j-1]=(unsigned char)192;
                j-=1;
            }
            if(maze[i][j]=='<'&&maze[i][j-1]=='|')          //<|
            {
                maze1[i][j-1]=(unsigned char)218;
                j-=1;
            }
            if(maze[i][j]=='<'&&maze[i][j-1]=='<')          //<<
            {
                maze1[i][j-1]=(unsigned char)196;
                j-=1;
            }
            if(maze[i][j]=='>'&&maze[i][j+1]=='^')          //>^
            {
                maze1[i][j+1]=(unsigned char)217;
                j+=1;
            }
            if(maze[i][j]=='>'&&maze[i][j+1]=='|')          //>|
            {
                maze1[i][j+1]=(unsigned char)191;
                j+=1;
            }
            if(maze[i][j]=='>'&&maze[i][j+1]=='>')          //>>
            {
                maze1[i][j+1]=(unsigned char)196;
                j+=1;
            }
        }

        for(int i=0;i<width;i++)
        {
            for(int j=0;j<height;j++)
            {
                if(maze1[i][j]==1)
                {
                    cout<<"@";
                }
                else if(maze1[i][j]==0)
                    cout<<"*";
                else
                {
                    cout<<maze1[i][j]<<"";
                }
            }
            cout<<endl;
        }

    }
    else
        cout<<"no path"<<endl;
    // system("pause");
    return 0;
}
