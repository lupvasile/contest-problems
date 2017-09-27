#include <iostream>
#include <cstring>

using namespace std;

char s[10000];

int get_num(int pos)
{
    int res=0;
    for(;s[pos]=='0';--pos) ++res;
    return res;
}

int main()
{
    bool ok = true,loc=false;
    cin>>s;
    int n=strlen(s),nr=0;

    for(int i=0;i<n && ok;i+=8)
    {
        if(s[i] == '0' && loc)  --nr;
        if(nr<0) ok=false;
        if(s[i] == '1'){
            loc=true;
                if(nr>0) ok=false;
        else nr=get_num(i+8-1);
        }
    }
    if(nr) ok=false;

    if(ok) cout<<"Yes";
    else cout<<"No";

    return 0;
}
