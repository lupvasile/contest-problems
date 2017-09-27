#include <iostream>

using namespace std;

#define nmax 100001

int a[nmax],next_r[nmax],n_r_c[nmax];//next_r ii capat la secventa descrescatoare si n_r_c ii capat la secventa crescatoare
int n,i;

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i) cin>>a[i];
    next_r[n]=n_r_c[n]=n;
    for(i=n-1; i; --i)
    {
        if(a[i]>a[i+1]) next_r[i]=next_r[i+1];
        else next_r[i]=i;
        if(a[i]<a[i+1]) n_r_c[i]=n_r_c[i+1];
        else n_r_c[i]=i;
    }
    for(i=1; i<n; ++i)
    {
        if(a[i]>a[i+1])
        {
            if(a[next_r[i]]>a[i-1])
                if (next_r[i]==n)
                {
                    cout<<"yes\n"<<i<<' '<<n;
                    return 0;
                }
                else if (a[i]<a[next_r[i]+1] && (n_r_c[next_r[i]+1]==n))
                {
                    cout<<"yes\n"<<i<<' '<<next_r[i];
                    return 0;
                }
            cout<<"no";
            return 0;
        }
    }
    cout<<"yes\n"<<i<<' '<<i;
    return 0;
}
