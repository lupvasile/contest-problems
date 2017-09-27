#include <iostream>

using namespace std;

int T,n,a,st=1,i;
long long sum,curr;
int v[1000010];

int main()
{
    cin>>T;
    for(;T;--T)
    {
        cin>>n>>sum;
        curr=0;
        st=0;
        for(i=1;i<=n;++i) cin>>v[i];

        for(i=1;i<=n;++i)
        {
            curr+=v[i];
            while(curr>sum) curr-=v[st++];
            if (curr==sum)
            {
                cout<<"YES\n";
                goto asdf;
            }
        }
        cout<<"NO\n";
        asdf:;

    }
    return 0;
}
