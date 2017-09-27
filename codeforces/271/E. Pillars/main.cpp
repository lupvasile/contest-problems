#include <iostream>
#include <set>
#include <tr1/unordered_map>
#include <cmath>
#include <cstdio>
#include <fstream>
using namespace std::tr1;
using namespace std;

//ifstream f("date.in");
//#define cin f

#define nmax 100010
#define foor(it,a) for(__typeof(a.begin()) it=a.begin();it!=a.end();++it)
#define debug 0
set <long long> s;
unordered_map <long long,int> m;
int i,n,d,pos,q1,q2,maxx,maint,l_nm;
int aint[nmax<<2],best[nmax],P[nmax];
long long v[nmax],mm[nmax];

int query(int a,int b,int st,int dr,int nod)
{
    if(a==0 || b==0) return 0;
    int q1(0),q2(0),mij;
    if(b<st || a>dr) return 0;
    if(a<=st && b>=dr) return aint[nod];
    mij=(st+dr)>>1;
    if(a<=mij) q1=query(a,b,st,(st+dr)/2,nod<<1);
    if(b>mij) q2=query(a,b,(st+dr)/2+1,dr,(nod<<1)+1);
    return best[q1]>best[q2] ? q1:q2;
}
void update(int pos,int val)
{
    int m,st(1),dr(n),nod=1;
    while(st!=dr)
    {
        m=(st+dr)>>1;
        if(pos<=m) dr=m,nod<<=1;
        else st=m+1,nod=(nod<<1)+1;
    }
    pos=nod;
    //pos=maint-1+pos;
    aint[pos]=val;
    pos>>=1;
    for(;pos;pos>>=1) aint[pos]=best[aint[pos<<1]]>best[aint[(pos<<1)+1]] ? aint[pos<<1]:aint[(pos<<1)+1];
}
void afis(int x)
{
    if(P[x]!=0)afis(P[x]);
    cout<<x<<' ';
}
int caut_bin(long long val,int p)
{
    int st(1),dr(l_nm),m;
    if(val<=0 || val>mm[dr]) return 0;
    while(st<=dr)
    {
        m=(st+dr)>>1;
        if(val==mm[m]) return m;
        if(val<mm[m]) dr=m-1;
        else st=m+1;
    }
    if(p) return st;
    else return dr;
}
int main()
    {
    cin.sync_with_stdio(false);
    cin>>n>>d;
    for(i=1; i<=n; ++i)
        {
        cin>>v[i];
        s.insert(v[i]);
        }
    i=0;
    foor(it,s)
        {
        m[*it]=++i;
        mm[i]=*it;
        }
    l_nm=i;
    for(i=1; i<=n; ++i)
        {
        pos=caut_bin(v[i]-d,0);
        //while(abs(v[i]-mm[pos])<d && pos) --pos;
     q1=query(1,pos,1,n,1);
        best[i]=1+best[q1];
        P[i]=q1;

        pos=caut_bin(v[i]+d,1);
        //while(abs(v[i]-mm[pos])<d && pos<=n) ++pos;
       q2=query(pos,n,1,n,1);
        if(best[i]<best[q2]+1)
            {
            best[i]=1+best[q2];
            P[i]=q2;
            }

       update(m[v[i]],i);
        if(best[i]>best[maxx]) maxx=i;
        }
    cout<<best[maxx]<<'\n';
  afis(maxx);
    return 0;
    }
