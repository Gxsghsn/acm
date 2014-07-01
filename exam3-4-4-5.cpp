#include<stdio.h>
using namespace std;

int main()
{
    char a;
    a = getchar();
    if((a>='a'&&a<='z')||(a>'A'&&a<='Z'))
        printf("isalpha");
    else if(a>='1'&&a<='9')
        printf("isdigit");
    return 0;
}
