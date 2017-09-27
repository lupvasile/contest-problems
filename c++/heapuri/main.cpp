#include <iostream>
#include <fstream>

using namespace std;

ifstream f("heapuri.in");
ofstream g("heapuri.out");
#define nmax  200010
#define father(x) (x/2)
#define cout g
int v[nmax],h[nmax],n,tip,val,l,lv,p,pos[nmax];
void percolate(int k)
{
    int key=h[k];
    while (father(k)>=1 && v[h[father(k)]]>v[key])
    {
        h[k]=h[father(k)];
        pos[h[father(k)]]=k;
        k=father(k);
    }
    h[k]=key;
    pos[key]=k;
}
void sift(int k)
{
    int son;
    do
    {
        son=k*2;
        if (son>n) break;
        if(son+1<=n) if (v[h[son]]>v[h[son+1]]) ++son;
        if (v[h[k]]<v[h[son]]) son=0;
        if(son) swap(h[k],h[son]),swap(pos[h[k]],pos[h[son]]);
        k=son;
    } while (son);
}
int main()
{
f>>n;
for(;n;--n)
{
    f>>tip;
    switch(tip)
    {
        case 1:{
        f>>val;
        v[++lv]=val;
        h[++l]=lv;
        pos[lv]=l;
        percolate(l);
        break;
        }
        case 2:
        {
            f>>val;
            p=pos[val];
            h[p]=h[l--];
            pos[h[p]]=p;
            if (father(p)>=1 && v[h[father(p)]]>v[h[p]]) percolate(p);
            else sift(p);
            break;
        }
        case 3:{
            cout<<v[h[1]]<<'\n';
            break;
        }
    }
}
    return 0;
}
