#include <stdio.h>
#include <memory.h>
void matrix_chain(int * p, int n, int[][100], int[][100]);
void trace_back(int i, int j, int [][100]);

int main()
{
    int size[100], total, i=0, m[100][100], s[100][100],j;
    memset(m,0,sizeof(m));
    memset(s,0,sizeof(s));
    memset(size,0,sizeof(size));
    printf("Please enter the number of matrix:\n");
    scanf("%d", &total);
    printf("Please enter a series of number.\nThe first number is the row of the first matrix, others are column of each matrix respectively:\n");
    while(i<=total)
        scanf("%d", &size[i++]);
    matrix_chain(size, total, m, s);
    printf("The result is:\n");
    trace_back(1, total, s);
    printf("           %d\n", m[1][total]);
    printf("\n");
    return 0;
}

// *((int *)a+i);
void matrix_chain(int * p, int n, int m[][100], int s[][100])
{
    int i,j,k,r,t;
    for(i=1; i<=n; i++) m[i][i]=0;                   //对角线的元素都为0
    for(r=2; r<=n; r++)
        for(i=1; i<=n-r+1; i++)
        {
            j=i+r-1; //m[1][2]=m[2][2]+p[0]*p[1]*p[2];
            m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];      //先计假设第一个点是最佳断开位置，算出其所需的数乘次数
            s[i][j]=i;                               //记录下断开的位置
            for(k=i+1; k<j; k++)
            {
                t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];//如果从其他断开点断开矩阵链，所需的数乘次数比原来的小，就替换
                if(t<m[i][j])
                    {m[i][j]=t; s[i][j]=k;}
            }
        }
}

void trace_back(int i, int j, int s[][100])
{
    if(i==j) {printf("A%d",i);return;}
    printf("(");
    trace_back(i,s[i][j],s);
    printf(",");
    trace_back(s[i][j]+1, j, s);
    printf(")");

}