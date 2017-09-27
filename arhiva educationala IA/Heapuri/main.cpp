#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("heapuri.in");
ofstream fout("heapuri.out");
/// ////////////////////////////////

vector<int> v;
int pos[200010];

class C_HEAP
{
private:
    vector<int> h;

    void go_up(int p)
    {
        int val=h[p];

        while(p>1 && v[val] < v[h[p>>1]])
        {
            h[p]=h[p>>1];
            pos[h[p]]=p;
            p>>=1;

        }

        h[p]=val;
        pos[val]=p;
    }

    void go_down(int p)
    {
        int n=h.size()-1,lleft,rright,val=h[p],son;

        while(1)
        {
            lleft=p<<1;
            rright=p<<1|1;

            if(lleft>n && rright>n) break;
            if(rright>n) son=lleft;
            else son=(v[h[lleft]]<v[h[rright]] ? lleft:rright);

            if(v[h[son]]>v[val]) break;

            h[p]=h[son];
            pos[h[p]]=p;
            p=son;
        }

        h[p]=val;
        pos[val]=p;
    }

public:
    C_HEAP()
    {
        h.push_back(0);
    }
    int top()
    {
        return h[1];
    }

    void pop(int p)
    {
        h[p]=h.back();
        pos[h[p]]=p;
        h.pop_back();

        if(p>1 && v[h[p]] < v[h[p>>1]]) go_up(p);
        else go_down(p);
        /// ////////////////
    }

    void push(int val)
    {
        h.push_back(val);
        go_up(h.size()-1);
    }
} heap;

int main()
{
    int i,tip,n,x;
    fin>>n;
    for(i=1;i<=n;++i)
    {
        fin>>tip;
        if(tip==1)
        {
            fin>>x;
            v.push_back(x);
            heap.push(v.size()-1);
        }
        if(tip==2)
        {
            fin>>x;
            heap.pop(pos[x-1]);
        }
        if(tip==3)
        {
            cout<<v[heap.top()]<<'\n';
        }
    }
    return 0;
}
