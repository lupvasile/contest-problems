#include <iostream>

using namespace std;
int n,m;
int A[101][101];
int i,j,k;
int main()
{
    cin>>n>>m;
    for(i=1;i<=100;i++) A[i][j]=1;
    for(i=1;i<=99;i++)
        for(j=i+1;j<=100;j++)
        {
            A[i][j]=10000000;
            //taieturi orizontale
            for(k=1;k<=i-1;k++)
                if (A[k][j]+A[i-k][j]<A[i][j])
                    A[i][j]=A[k][j]+A[i-k][j];
            //taieturi verticale
            for(k=1;k<=j-1;k++)
                if(A[i][k]+A[i][j-k]<A[i][j])
                    A[i][j]=A[i][k]+A[i][j-k];
            A[j][i]=A[i][j];
        }
    return 0;
}
