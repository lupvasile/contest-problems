#include <iostream>
#include <fstream>
#include <set>
#include <tr1/unordered_map>
#include <sstream>

using namespace std;


ifstream f("minuni.in");
ofstream g("minuni.out");

#define cout g
#define mmax 100010

set<int> s;
tr1::unordered_map<int,int> um;
struct
    {
    int x,y;
    } drum[mmax];
int n,m,i,nr,over;
stringstream ss;
int aint[5*mmax];
#define inclus(a,b) (drum[(a)].x>drum[(b)].x && drum[(a)].y<drum[(b)].y)
/*
inline bool inclus(int a,int b)
    {
    return (drum[a].x>drum[b].x && drum[a].y<drum[b].y);
    }
*/
int query(int nod,int st,int dr,int pos)
    {
    if(st==dr)
        {
        return aint[nod];
        }

    int mid=(st+dr)>>1;
    int q;

    if(pos<=mid) q=query(nod<<1,st,mid,pos);
    else q=query((nod<<1)|1,mid+1,dr,pos);
    if(inclus(aint[nod],q)) return aint[nod];
    else
        return q;
    }

void update(int nod,int st,int dr,int x,int y,int val)
    {
    if(x<=st && dr<=y)
        {
        if(inclus(val,aint[nod])) aint[nod]=val;
        return;
        }

    int mid=(st+dr)>>1;

    if(x<=mid) update(nod<<1,st,mid,x,y,val);
    if(y>mid) update((nod<<1)|1,mid+1,dr,x,y,val);
    }

#define maxb 200000
int pos(maxb);
char buf[maxb];
inline int gi()
    {
    int n(0);
    while(!(buf[pos]>='0' && buf[pos]<='9')) if(++pos>=maxb) f.read(buf,maxb),pos=0;
    while((buf[pos]>='0' && buf[pos]<='9'))
        {
        n=n*10+buf[pos]-'0';
        if(++pos>=maxb) f.read(buf,maxb),pos=0;
        }
    return n;
    }

int main()
    {
    n=gi();
    m=gi();
    for(i=1; i<=m; ++i)
        {
        drum[i].x=gi();
        drum[i].y=gi();
        s.insert(drum[i].x);
        s.insert(drum[i].y);
        }
    for(auto x:s) um[x]=++nr;
    drum[0]= {0,n+1};
    for(i=1; i<=m; ++i)
        {
        over=query(1,1,nr,um[drum[i].x]);
        update(1,1,nr,um[drum[i].x],um[drum[i].y],i);

        ss<<1ll*(drum[over].y-drum[i].y)*drum[i].x+1ll*(drum[i].x-drum[over].x)*(n-drum[over].y+1)<<'\n';
        }
    cout<<ss.str();
    return 0;
    }
