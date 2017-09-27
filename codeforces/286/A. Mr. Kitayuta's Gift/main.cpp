#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

#ifndef ONLINE_JUDGE
ifstream f("date.in");
#define cin f
#endif // ONLINE_JUDGE

char s[20],i,j,r[20],k,l;

bool palind(char s[])
    {
    int a,b;
    for(a=1,b=j+1; a<b;)
        {
        if(s[a]==s[b])
            {
            ++a,--b;
            continue;
            }
        if(s[a]==' ')
            {
            s[a]=s[b];
            ++a,--b;
            continue;
            }
        if(s[b]==' ')
            {
            s[b]=s[a];
            ++a,--b;
            continue;
            }
        break;
        }
    if(a>=b) return true;
    return false;
    }

int main()
    {
    cin>>(s+1);
    j=strlen(s+1);
    for(i=1; i<=j+1; ++i)
        {
        k=0;
        for(l=1; l<=j+1; ++l) if(l==i)
                {
                r[l]=' ';
                }
            else r[l]=s[++k];
        if(palind(r))
            {
            cout<<(r+1);
            return 0;
            }
        }
    cout<<"NA";
    return 0;
    }
