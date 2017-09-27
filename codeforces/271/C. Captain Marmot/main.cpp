#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

//ifstream f("date.in");
//#define cin f

struct ppunct
    {
    int x,y;
    };
ppunct c[4][4],h[4];
int i,j,n,k,l,minn;

ppunct move_ct(ppunct a, ppunct o)
{
    ppunct n_a;
    a.x=a.x-o.x;
    a.y=a.y-o.y;
    n_a.x=-a.y+o.x;
    n_a.y=a.x+o.y;
    return n_a;
}
long long dist(ppunct a,ppunct b)//distanta la patrat
{
    return 1LL*(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
bool patrat(ppunct a,ppunct b,ppunct c,ppunct d)
{
    vector<long long> v;
    v.push_back(dist(a,b));
    v.push_back(dist(a,c));
    v.push_back(dist(a,d));
    v.push_back(dist(b,c));
    v.push_back(dist(b,d));
    v.push_back(dist(c,d));
    sort(v.begin(),v.end());
    if(v[0]==0) return false;
    for(int i=0;i<=2;++i) if(v[i]!=v[i+1]) return false;
    if(v[4]!=v[5]) return false;
    return true;
}
int main()
    {
    cin>>n;
    for(; n; --n)
        {
        for(i=0; i<=3; ++i)
            {
            cin>>c[i][0].x>>c[i][0].y>>h[i].x>>h[i].y;
            for(j=1; j<=3; ++j) c[i][j]=move_ct(c[i][j-1],h[i]);
            }
        minn=20;
        for(i=0; i<=3; ++i)
            for(j=0; j<=3; ++j)
                for(k=0; k<=3; ++k)
                    for(l=0; l<=3; ++l)
                    {
                        if(i+j+k+l>=minn) break;
                        if(patrat(c[0][i],c[1][j],c[2][k],c[3][l])) minn=i+j+k+l;
                    }
        if(minn==20) cout<<"-1\n";
        else cout<<minn<<"\n";
        }
    return 0;
    }
