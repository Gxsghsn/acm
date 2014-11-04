#include "iostream"
#include <cstdio>
#include <iomanip>
using namespace std;
int Board[8][8];
int okey=1;

void ChessBoard(int sa,int sb,int a,int b,int size){
    if(size==1) return;
    // cout<<"a"<<endl;
    int s=size/2;
    // cout<<s<<endl;
    // key++;
    int key=okey++;

    cout<<key<<" "<<okey<<endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            cout<<Board[i][j]<<" ";
        cout<<endl;
        // cout<<endl;
    }
    cout<<endl;


    if(a<sa+s && b<sb+s){
        ChessBoard(sa,sb,a,b,s);
    }else{
        // key++;
        Board[sa+s-1][sb+s-1]=key;
        ChessBoard(sa,sb,sa+s-1,sb+s-1,s);
    }

    if(a>=sa+s && b<sb+b){
        ChessBoard(sa+s,sb,a,b,s);
    }else{
        Board[sa+s][sb+s-1]=key;
        ChessBoard(sa+s,sb,sa+s,sb+s-1,s);
    }

    if(a<sa+s && b>=sb+s){
        ChessBoard(sa,sb+s,a,b,s);
    }else{
        Board[sa+s-1][sb+s]=key;
        ChessBoard(sa,sb+s,sa+s-1,sb+s,s);
    }

    if(a>=sa+s && b>=sb+s){
        ChessBoard(sa+s,sb+s,a,b,s);
    }else{
        Board[sa+s][sb+s]=key;
        ChessBoard(sa+s,sb+s,sa+s,sb+s,s);
    }
}


int main()
{
    // Board={};
    ChessBoard(0,0,1,1,4);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            cout<<setw(4)<<Board[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}