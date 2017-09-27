#include <iostream>
#include <fstream>

using namespace std;

char s[200003],sm[400001];
int i,lung[400001],center,r,l,n,isim;

int main()
{
    ifstream fin("palindrom.in");
    ofstream fout("palindrom.out");
    fin>>s;
    sm[0]='%';
    for(i=0;s[i];++i) sm[2*(i+1)]=s[i],sm[2*i+1]='#';
    sm[2*i+1]='#';
    sm[2*i+2]='^';
    n=2*i+1;
    center=1;
    r=1;
    for(i=2;i<=n;++i)
    {
        isim=2*center-i;
        l=r>i ? min(lung[isim],r-i):0;
        int li=l;
        while(sm[i+l+1]==sm[i-l-1]) ++l;
        lung[i]=l;
        if(i+l>r)
        {
            r=i+l;
            center=i;
        }
        if(r==n) break;
    }
    fout<<s;
    for(i=center-l;i>0;--i) if(sm[i]!='#') fout<<sm[i];
    return 0;
}
