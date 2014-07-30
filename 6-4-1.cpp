#include<iostream>
using namespace std;
int maze[10][10];
int num=0;
int n;

void changearound(int a,int b)
{
    if(maze[a][b]==1) maze[a][b]=0;
    if(maze[a-1][b-1]==1&&a>0&&b>0) changearound(a-1,b-1);
    if(maze[a-1][b]==1&&a>0) changearound(a-1,b);
    if(maze[a-1][b+1]==1&&a>0&&b+1<10) changearound(a-1,b+1);
    if(maze[a][b-1]==1&&b>0) changearound(a,b-1);
    if(maze[a][b+1]==1&&b+1<10) changearound(a,b+1);
    if(maze[a+1][b-1]==1&&b>0&&a+1<10) changearound(a+1,b-1);
    if(maze[a+1][b]==1&&a+1<10) changearound(a+1,b);
    if(maze[a+1][b+1]==1&&a+1<10&&b+1<10) changearound(a+1,b+1);
}

void bfs()
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<maze[i][j]<<" ";
            if(maze[i][j]==1){
                num++;
                changearound(i,j);
            }
//            else cout<<"no";
        }
        cout<<endl;
    }
}



int main()
{
    freopen("6-4-1.in","r",stdin);
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<maze[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl<<n<<endl;


    bfs();


    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<maze[i][j]<<" ";
        cout<<endl;
    }

    cout<<endl<<num<<endl;
    return 0;
}
