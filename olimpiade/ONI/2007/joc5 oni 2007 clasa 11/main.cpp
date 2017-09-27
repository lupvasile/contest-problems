#include <bits/stdc++.h>

using namespace std;
#define cout g
ifstream f("joc5.in");
ofstream g("joc5.out");

int n,i,j,x,m,xor_sum;

int main()
{
    while(1)
    {
        f>>n;
        if(n==0) break;
        xor_sum=0;
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
        {
            f>>x;
            if(i==j) xor_sum=xor_sum xor x;
        }
            if(xor_sum) cout<<"1\n";
            else cout<<"2\n";
    }
    return 0;
}
