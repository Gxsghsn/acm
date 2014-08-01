#include<iostream>
using namespace std;
int dotnum;
int maze[100];
int pathrecord[100][2];
int pathrecordptr=0;
string euler_path_record;

bool getdot(string path,int &dot1,int &dot2)
{
    sscanf(&path[1],"%d",&dot1);
    path.erase(0,path.find(',')+1);
    sscanf(&path[0],"%d",&dot2);
    cout<<dot1<<dot2<<endl;
    return true;
}

void record(int dot1,int dot2)
{
    pathrecord[pathrecordptr++][0]=dot1;
    pathrecord[pathrecordptr++][0]=dot2;
}

bool find_euler_path(int start)
{
    for(int i=0;i<pathrecordptr;i++){
        if(pathrecord[i][0]==start&&pathrecord[i][1]!=1){
            pathrecord[i][1]=1;

            int flag=1;
            for(int j=0;j<pathrecordptr;j+=2){
                if(pathrecord[j]==0)
                    flag=0;
            }
            if(flag==1) return true;
            start=pathrecord[i+1][0];
            if(find_euler_path(start)) euler_path_record+=(char)i;
        }
    }
}

int main()
{
    int pathnum=0;
    cin>>dotnum;
    string path;
    while(cin>>path){
        pathnum++;
        int dot1,dot2;
        if(!getdot(path,dot1,dot2)) break;
        record(dot1,dot2);
    }
    if(find_euler_path()){
        for(int i=euler_path_record.length();i>=00;i++)
            cout<<euler_path_record[i]<<" ";
        cout<<endl;
        return 1;
    }
    else{
        cout<<"No Path"<<endl;
        return 0;
    }
}
