#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
using namespace std;

ifstream f("pikachu.in");
ofstream g("pikachu.out");

#define cout g
int gi();
#define nmax 100010

int n,k,i,median,sum,best,oldmedian,before,after;
set <int> s;
set <int> ::iterator it;
int a[nmax],aux[nmax];

int main()
{
    n=gi();k=gi();
    for(i=1;i<=n;++i)
    {
        a[i]=gi();
        aux[i]=a[i];
        if(i<=k)s.insert(a[i]);
    }
    nth_element(aux+1,aux+(k+1)/2,aux+k+1);
    median=aux[(k+1)/2];
    for(i=1;i<=k;++i) sum+=abs(median-a[i]);
    best=sum;
    for(;i<=n;++i)
    {
        oldmedian=median;
        it=s.find(median);
        --it;
        before=*it;
        ++it;
        ++it;
        after=*it;
        s.erase(a[i-k]);
        s.insert(a[i]);

        if(a[i-k]==median)
            if(a[i]<=after && a[i]>=before) median=a[i];
            else if(a[i]>after) median=after;
            else median=before;
        if(a[i-k]<median && a[i]>median) median=min(a[i],after);
        if(a[i-k]>median && a[i]<median) median=max(a[i],before);
        sum-=abs(oldmedian-a[i-k]);
        sum+=abs(median-a[i]);
        if(!(k&1)) sum+=oldmedian-median;
        best=min(sum,best);
        //cout<<median<<'\n';
    }
    cout<<best;
    return 0;
}


#define maxb 10000
char buf[maxb];
int pos(maxb);
int gi()
{
    int n=0;
    while (buf[pos]<'0' || buf[pos]>'9') if(++pos>=maxb) f.read(buf,maxb),pos=0;
    while (buf[pos]>='0' && buf[pos]<='9')
    {
        n=n*10+buf[pos]-'0';
        if(++pos>=maxb) f.read(buf,maxb),pos=0;
    }
    return n;
}
