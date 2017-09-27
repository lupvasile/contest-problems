
#include <iostream>

using namespace std;
int v[20],i;
int binsrc(int val)
{
    int s(1),d(8),m,k(0);
    while(s<=d)
    {
        m=(s+d)/2;

        k++;
        if(v[m]==val) return k;
        else if(v[m]<val) s=m+1;
        else d=m-1;
    }
}
int main()
{int r=0;
    for(i=1;i<=8;i++) v[i]=i;
    for(i=1;i<=8;i++)
    if (binsrc(i)==3) cout<<i<<' ';

    return 0;
}
