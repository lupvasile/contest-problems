#include <bits/stdc++.h>

using namespace std;

char s[200010];
int frq[30];

int main()
{
    int i,j,n;
    cin>>s+1;
    n=strlen(s+1);

    for(i=1;i<=n;++i)
        ++frq[s[i]-'a'];

    for(i=0;i<26;++i)
        if(frq[i]%2==1)
            for(j=25;j>i;--j)
                if(frq[j]%2==1)
    {
        ++frq[i];
        --frq[j];
        break;
    }

    for(i=0;i<26;++i)
        for(j=1;j<=(frq[i]/2);++j) cout<<(char)('a'+i);

    for(i=0;i<26;++i) if(frq[i]%2==1) cout<<(char)('a'+i);

    for(i=25;i>=0;--i)
        for(j=1;j<=(frq[i]/2);++j) cout<<(char)('a'+i);

    return 0;
}
