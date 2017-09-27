#include <bits/stdc++.h>
using namespace std;
#define INFOARENA 1
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("dragonball.in");
ofstream fout("dragonball.out");
/// ////////////////////////////////

void read();

#define nmax 1010
#define lenmax 50010
#define BASE 1000000
#define nbs 100000

string s[nmax];
int v[nmax][lenmax],cat[nmax][lenmax],T,n,sc[nmax];
double frac[nmax];




int compare(const int a[],const int b[])
{
    if(a[0]!=b[0]) return a[0]<b[0] ? -1:1;

    for(int i=a[0]; i>=1; --i)
        if(a[i]>b[i]) return 1;
        else if(a[i]<b[i]) return -1;

    return 0;
}

void egaleaza(int a[],const int b[])
{
    for(int i=0;i<=b[0];++i) a[i]=b[i];
}

void set_value_for(int v[],string &s)
{
    int n=s.size();
    int t=6,i;

    int rest=n%6;
    if(rest==0) rest=6;

    v[0]=1;
    for(i=0;i<rest;++i)
    {
        v[v[0]]=v[v[0]]*10+s[i]-'0';
    }

    for(;i<n;++i)
    {
        ++t;
        if(t==7) t=1,++v[0];

        v[v[0]]=v[v[0]]*10+s[i]-'0';
    }

    reverse(v+1,v+v[0]+1);
}

void make_diff(int a[],const int b[])
{
    int i,t=0;
    for(i=1;i<=a[0];++i)
    {
        a[i]=a[i]-b[i]-t;
        if(a[i]<0) a[i]+=BASE,t=1;
        else t=0;
    }

    while(a[a[0]]==0 && a[0]) --a[0];
}

void make_impartire(const int a[],int b,int res[],double &rst)
{
    int rest=0,i;

    for(i=a[0];i;--i)
    {
        rest=rest*BASE + a[i];
        res[i]=rest/b;
        rest%=b;
    }

    while(res[res[0]]==0 && res[0]) --res[0];
    rst=rest/(double)b;
}

struct cmp
{
    bool operator() (int a,int b)
    {
        int x=compare(cat[a],cat[b]);
        if(x==0) return frac[a]<frac[b];
        return x==-1;
    }
};
priority_queue<int,vector<int>,cmp> heap;

void af(int a[])
{
    cout<<a[a[0]--];
    for(int i=a[0];i;--i)
        cout<<setw(6)<<setfill('0')<<a[i];
}

int main()
{

    read();

    int ind;
    for(; T; --T)
    {
        ind=heap.top();
        heap.pop();
        ++sc[ind];

        make_impartire(v[ind],sc[ind],cat[ind],frac[ind]);

        heap.push(ind);
    }

    if(frac[heap.top()]>0) ++cat[heap.top()][1];
    af(cat[heap.top()]);
    //fout.close();
    return 0;
}

void read()
{
    int i;
    fin>>n>>T;
    fin>>s[++n];

    set_value_for(v[n],s[n]);

    for(i=1; i<n; ++i)
    {
        fin>>s[i];
        set_value_for(v[i],s[i]);
    }


    s[0][0]=1;
    for(i=n; i; --i)
    {
        make_diff(v[i],v[i-1]);
        egaleaza(cat[i],v[i]);
        sc[i]=1;
    }

    for(i=1;i<=n;++i)
        heap.push(i);
}
