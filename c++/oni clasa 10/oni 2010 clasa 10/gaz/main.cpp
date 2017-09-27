#include <iostream>
#include <fstream>

using namespace std;

ifstream f("gaz.in");
ofstream gout("gaz.out");

//#define cout gout
#define nmax 2010

unsigned long long i,n,l,p,d,c,g[nmax],s[nmax],litri,sum,j,sg;
bool ap[nmax];
int main()
{
    f>>l>>p>>d>>c;
    f>>n;
    for(i=1;i<=n;++i) f>>g[i],sg+=g[i];
    for(i=1;i<=n;++i)
    {
        s[i]=s[i-1]+p;
        ap[i]=true;
        litri=g[i];
        sum=0;
        for(j=i-1;j>0;--j)
        {
            if(ap[j])
            { //cout<<"asdf "<<(s[j]+sum+max(0,(litri-l))*c>s[i]<<" asdf";
                if(s[i]>s[j]+sum+max(0ULL,(litri-l))*c)
                                    {
                                        s[i]=s[j]+sum+max(0ULL,(litri-l))*c;
                                        ap[i]=false;
                                    }
            }
            else if (s[i]>s[j]+sum+p+max(0ULL,(litri-l))*c)
                                    {
                                        s[i]=s[j]+sum+max(0ULL,(litri-l))*c+p;
                                        ap[i]=false;
                                    }
            sum+=max(0ULL,(litri-l))*c;
            litri+=g[j];
        }
    }
    /*sg=0;
    for(i=1;i<=n;++i)
    {
        sg+=g[i];
        cout<<s[i]<<" ";
    }
    cout<<'\n';*/
    cout<<s[n]+sg*d;
    return 0;
}
