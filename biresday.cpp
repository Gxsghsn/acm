
#include <iostream>
#include <windows.h>
using namespace std;
string s;


DWORD WINAPI Fun(LPVOID lpParamter)
{

    cin>>s;
}


int main()
{
    cout<<"请在十秒内输入gaoxinwoaini五次"<<endl;
    string correctans="gaoxinwoainigaoxinwoainigaoxinwoainigaoxinwoainigaoxinwoaini";
    string correctans2="gaoxinailinqi";
    HANDLE hThread = CreateThread(NULL, 0, Fun, NULL, 0, NULL);
    int n=12;
    while(n>0)
    {
        Sleep(1000);
        n--;
        if(s==correctans)
            break;
    }
    if(s==correctans||s==correctans2)
    {
        cout<<"Congratulations"<<endl;
    }
    else
        cout<<"\nGameOver"<<endl;
    CloseHandle(hThread);
    return 0;
}
