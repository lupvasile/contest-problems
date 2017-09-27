#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

ifstream f("segmente.in");
ofstream g("segmente.out");

#define cout g
#define pb push_back
#define inf 0x3f3f3f3f

int n,x1,x2,y1,y2,i,k,min1,min2,rez(inf),j;
int m[1010][1010];//int m[i][j] cu cat trebuie prelungite ca segmentul orizontal i sa se intersecteze cu segmentul vertical j
struct el1
{
    int x,y1,y2;
} v;
struct el2
{
    int x1,x2,y;
} o;
vector <el1> s_vertical;
vector <el2> s_orizontal;

int main()
{
    f>>n;
    s_vertical.pb( {0,0,0});
    s_orizontal.pb( {0,0,0});
    for(; n; --n)
    {
        f>>x1>>y1>>x2>>y2;
        if(x1==x2)
        {
            if(y1>y2) swap(y1,y2);
            s_vertical.pb( {x1,y1,y2});
            v=s_vertical.back();
            k=s_vertical.size()-1;
            for(i=1; i<s_orizontal.size(); ++i)
            {
                o=s_orizontal[i];
                if(o.x1<=v.x && o.x2>=v.x)
                {
                    if(v.y1<=o.y && v.y2>=o.y) m[i][k]=0;
                    else m[i][k]=min( abs(v.y1-o.y) , abs(v.y2-o.y) );
                }
                else if(v.y1<=o.y && v.y2>=o.y) m[i][k]=min( abs(v.x-o.x1) , abs(v.x-o.x2) );
                else m[i][k]=max(min( abs(v.y1-o.y) , abs(v.y2-o.y)), min(abs(v.x-o.x1) , abs(v.x-o.x2)));
            }
        }
        else
        {
            if(x1>x2) swap(x1,x2);
            s_orizontal.pb( {x1,x2,y1});
            o=s_orizontal.back();
            k=s_orizontal.size()-1;
            for(i=1; i<s_vertical.size(); ++i)
            {
                v=s_vertical[i];
                if(o.x1<=v.x && o.x2>=v.x)
                {
                    if(v.y1<=o.y && v.y2>=o.y) m[k][i]=0;
                    else m[k][i]=min( abs(v.y1-o.y) , abs(v.y2-o.y) );
                }
                else if(v.y1<=o.y && v.y2>=o.y) m[k][i]=min( abs(v.x-o.x1) , abs(v.x-o.x2) );
                else m[k][i]=max(min( abs(v.y1-o.y) , abs(v.y2-o.y)), min(abs(v.x-o.x1) , abs(v.x-o.x2)));
            }
        }
    }
    for(i=1; i<s_orizontal.size(); ++i)
        for(j=i+1; j<s_orizontal.size(); ++j)
        {
            min1=min2=inf;
            for(k=1;k<s_vertical.size();++k)
            {
                n=max(m[i][k],m[j][k]);
                if(n<min1) min2=min1,min1=n;
                else if (n<min2) min2=n;
            }
            rez=min(rez,max(min1,min2));
        }
        cout<<rez;
    return 0;
}
