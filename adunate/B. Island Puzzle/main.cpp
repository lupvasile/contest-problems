#include <iostream>

using namespace std;

#define nmax 200010

bool ok=true;

int v[2*nmax];

int main()
{
    int i,j,x,n;
    cin>>n;
    --n;
    for(i=1; i<=n; ++i)
    {
        cin>>x;
        if(x==0)
        {
            --i;
            continue;
        }
        v[n+i]=v[i]=x;
    }


    for(i=1; i<=n; ++i)
    {
        cin>>x;
        if(x==0)
        {
            --i;
            continue;
        }
        if(ok)
        {
            for(j=1; j<=n; ++j)
                if(v[j]==x) break;
            ok=false;
        }

        if(x!=v[j++])
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}
