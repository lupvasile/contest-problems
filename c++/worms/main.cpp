#include <iostream>
#include <fstream>
using namespace std;

int n,m;
int x,y,c;
#define nmax 50010
//#define cin f
//ifstream f("date.in");
int v[nmax],st[nmax],dr[nmax],s,d,i,caz;
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;++i) st[i]=1,dr[i]=n;
    v[0]=v[n+1]=-1;
    for(;m;--m)
    {
        cin>>caz;
        if(caz==1)
        {
           cin>>x>>y>>c;
           if(v[x-1]==c) s=st[x-1],x=st[x-1];
           else s=x,dr[x-1]=x-1;
           if(v[y+1]==c) d=dr[y+1],y=dr[y+1];
           else d=y,st[y+1]=y+1;

           for(i=x;i<=y;++i){
               v[i]=c;
               dr[i]=d;
               st[i]=s;
           }
        }
        else
        {
            cin>>x;
            cout<<v[x]<<' '<<st[x]<<' '<<dr[x]<<'\n';
        }
    }
    return 0;
}
