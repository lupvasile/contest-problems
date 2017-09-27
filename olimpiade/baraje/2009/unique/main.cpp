#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("unique.in");
ofstream fout("unique.out");
/// ////////////////////////////////

#define nmax 100010

int n,v[nmax],dad[nmax],last[nmax],nr_elem[nmax],res,st[nmax],lst;

int get_dad(int nod)
{
    if(nod!=dad[nod]) dad[nod]=get_dad(dad[nod]);
    return dad[nod];
}

void unite(int x,int y)
{
    x=get_dad(x);
    y=get_dad(y);

    if(nr_elem[x]<nr_elem[y]) swap(x,y);

    dad[x]=y;
    nr_elem[y]+=nr_elem[x];
}

int main()
{
    int T,i,nr_elem_cur;

    fin>>T;
    for(;T;--T)
    {
        res=0;
        fin>>n;
        ++n;
        for(i=1;i<=n;++i) dad[i]=i,last[i]=0,nr_elem[i]=1;
        for(i=1;i<n;++i) fin>>v[i];

        v[n]=n;
        lst=0;
        for(i=1;i<=n;++i)
        {
            nr_elem_cur=0;

            while(lst && v[st[lst]] <= v[i])
            {
                nr_elem_cur += nr_elem[get_dad(st[lst])];
                if(nr_elem_cur==v[st[lst]])
                    if(i-st[lst-1]-1>res) res=i-st[lst-1]-1;

                unite(st[lst],i);
                --lst;
            }

            st[++lst]=i;

            if(last[v[i]]) --nr_elem[get_dad(last[v[i]])];

            last[v[i]]=i;
        }
    cout<<res<<'\n';
    }

}
