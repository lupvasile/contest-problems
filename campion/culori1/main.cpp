#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("culori1.in");
ofstream fout("culori1.out");

unsigned long long a[5][5]={ {0,1,0,0,0},{1,0,1,0,0},{0,1,0,1,0},{0,0,1,0,1},{0,0,0,1,0} };
unsigned long long res[5][5];
unsigned long long aux[5][5];

int p;
unsigned long long rasp;

void mult(unsigned long long a[][5],unsigned long long b[][5])
{
    int i,j,k;

    for(i=0;i<5;++i)
        for(j=0;j<5;++j)
            aux[i][j]=0;

    for(i=0;i<5;++i)
        for(j=0;j<5;++j)
            for(k=0;k<5;++k)
                aux[i][j]+=a[i][k]*b[k][j];

    for(i=0;i<5;++i)
        for(j=0;j<5;++j)
            a[i][j]=aux[i][j];

}

int main()
{
    int i,j;

    fin>>p;
    --p;

    for(i=0;i<5;++i) res[i][i]=1;

    for(;p;p>>=1)
    {
        if(p&1) mult(res,a);
        mult(a,a);
    }

    for(i=0;i<5;++i)
        for(j=0;j<5;++j)
            rasp+=res[i][j];

    cout<<rasp;
    return 0;
}
