#include <iostream>
#include <cstring>
using namespace std;

char s[100010];
string a,b;

bool numar(int p1,int p2)
{
    if(p2-p1-1==0) return false;
    if(p2-p1-1>1) if(s[p1+1]=='0') return false;
    for(int i=p1+1;i<p2;++i) if(s[i]<'0' || s[i]>'9') return false;
    return true;
}

int main()
{
    int p1=0,p2=-1,i,j,na=0,nb=0;
    cin>>s;
    strcat(s,",");
    for(i=0;s[i];++i)
        if(s[i]==';' || s[i]==',')
    {
        p1=p2;
        p2=i;

        if(numar(p1,p2))
           {
               if(na) a+=',';
            for(j=p1+1;j<p2;++j) a+=s[j];
            ++na;

           }

        else {
                if(nb) b+=',';
                for(j=p1+1;j<p2;++j) b+=s[j];
                ++nb;
        }
    }
    if(na)cout<<'"'<<a<<'"'<<'\n';
    else cout<<"-\n";
    if(nb)cout<<'"'<<b<<'"';
    else cout<<"-\n";
    return 0;
}
