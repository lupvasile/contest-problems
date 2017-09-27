#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

ifstream f("bilute.in");
ofstream g("bilute.out");

#define nmax 100001
#define cout g
int n,m,i,start,tp,nr_qu;
int t[nmax],qu[nmax],down[nmax],up[nmax<<1],ras[nmax],aib[nmax];
bool on[nmax];
struct eee
    {
    int timp,tip,val;
    bool operator <(eee a) const
        {
        if(timp!=a.timp) return timp>a.timp;
        if(tip!=a.tip) return tip>a.tip;
        return val<a.val;

        }
    };
///0 pentru coborare, 1 pentru query \
la 0 val ii bila, la 1 val ii nr query

priority_queue<eee> heap;

void add(int pos,int val)
    {
    for(; pos<=n; pos+=(pos&(-pos))) aib[pos]+=val;
    }

int query(int pos)
    {
    int res(0);
    for(; pos>0; pos-=(pos&(-pos))) res+=aib[pos];
    return res;
    }
int gi();
int caut_bin(int val)
    {
    int step;
    for(step=1; step<=n; step<<=1);
    step>>=1;
    int x=n;
    for(; step; step>>=1)
        {
        if(x-step>0) if(query(x-step)>=val) x-=step;
        }
    return x;
    }

int main()
    {
    n=gi();
    m=gi();
    start=gi();
    for(i=1; i<=n; ++i)
        {
        t[i]=gi();
        on[i]=true;
        add(i,1);
        }
    for(i=1; i<=m; ++i)
        {
        qu[i]=gi();
        tp=gi();
        heap.push({tp,1,i});
        }
    heap.push({0,0,start});
    on[start]=false;
    add(start,-1);
    nr_qu=m;
    while(nr_qu)
        {
        down[0]=up[0]=0;
        tp=heap.top().timp;

        while(heap.top().tip==0 && heap.top().timp==tp &&heap.size()>0)
            {
            down[++down[0]]=heap.top().val;
            heap.pop();
            }

        for(i=1; i<=down[0]; ++i)
            {
            up[++up[0]]=caut_bin(query(down[i]));
            up[++up[0]]=caut_bin(query(down[i])+1);
             for(int i=1; i<=up[0]; ++i)
            {
            if(!on[up[i]]) continue;
            on[up[i]]=false;
            add(up[i],-1);
            heap.push({tp+t[up[i]],0,up[i]});
            }
            up[0]=0;
            }

        for(i=1; i<=down[0]; ++i)
            {
            on[down[i]]=1;
            add(down[i],1);
            }

        while(heap.top().tip==1 && heap.size()>0)
            {
            eee asdf=heap.top();
            --nr_qu;
            ras[heap.top().val]=on[qu[heap.top().val]];
            heap.pop();
            }
    /*   cout<<tp<<'\n';
        for(i=1;i<=n;++i) cout<<fixed<<setw(4)<<on[i]<<' ';
        cout<<'\n';
        for(i=1;i<=n;++i) cout<<fixed<<setw(4)<<t[i]<<' ';
        cout<<'\n';*/
        }
    for(i=1; i<=m; ++i)cout<<ras[i]<<'\n';
    return 0;
    }
#define maxb 100000
int pos(maxb);
char buf[maxb];
int gi()
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
