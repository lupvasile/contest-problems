#include <iostream>

using namespace std;

long long q,i,l;
int m(1);
int main()
    {
    cin>>q;
    for(i=2; i<=3300000 && i<=q; i+=m,m=2) while(q%i==0)
            {
            q/=i;
            if(l) if(q>1)
                    {
                    cout<<"1\n"<<l*i;
                    return 0;
                    }
                else
                    {
                    cout<<2;
                    return 0;
                    }
            l=i;
            }
    if(l && q>1)
        {
        cout<<2;
        return 0;
        }
    cout<<"1\n0";
    return 0;
    }
