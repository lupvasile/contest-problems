#include <iostream>

using namespace std;

#define nmax 100010

int i,j,n,x,p;
int l[2][nmax],v[nmax];
long long sol;
int main()
{
    cin>>n;
    cin>>v[1];
    ++sol;
    l[0][0]=1;
    l[0][1]=v[1];
    for(i=2;i<=n;++i)
    {
        p=i&1;
       cin>>x;
       v[i]=x;
       l[p^1][0]=0;
       for(int i=1;i<=l[p][0];++i) if(v[l[p][i]-1]==x)
       {
           ++sol;
           l[p^1][++l[p^1][0]]=l[p][i]-1;
       }

    }
    cout<<sol;
    return 0;
}
