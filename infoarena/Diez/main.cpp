#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("diez.in");
ofstream fout("diez.out");
/// ////////////////////////////////

#define mod1 666013
#define mod2 700001
#define nmax 250001
#define BASE 27

pair<int,int> hpow[2*nmax];

struct N_T
{
    int nr,pr,ch;
    pair<int,int> h;
    N_T *left,*right;
};
N_T *nil=new N_T{0,0,0,{0,0},NULL,NULL};
N_T *root=nil;

pair<int,int> operator + (const pair<int,int> &a, const pair<int,int> &b)
{
    pair<int,int> res;

    res.first = a.first + b.first;
    if(res.first>=mod1) res.first-=mod1;

    res.second = a.second + b.second;
    if(res.second>=mod2) res.second-=mod2;

    return res;
}

pair<int,int> operator * (const pair<int,int> &a, const pair<int,int> &b)
{
    return make_pair(1ll * a.first * b.first % mod1,1ll * a.second * b.second % mod2);
}

pair<int,int> operator * (const pair<int,int> &a, int x)
{
    return make_pair(a.first*x%mod1 , a.second*x%mod2);
}

bool operator == (const pair<int,int> &a, const pair<int,int> &b)
{
    return a.first==b.first && a.second==b.second;
}

void update(N_T *n)
{
    n->h = ((n->left->h * hpow[1]) + (make_pair(n->ch,n->ch))) * hpow[n->right->nr] + n->right->h;
    n->nr = n->left->nr + n->right->nr + 1;
}

void rot_left(N_T *&n)
{
    N_T *son=n->left;

    n->left = son->right;
    son->right = n;

    update(n);
    update(son);

    n=son;
}

void rot_right(N_T *&n)
{
    N_T *son=n->right;

    n->right = son->left;
    son->left = n;

    update(n);
    update(son);

    n=son;
}

void balance(N_T *&n)
{
    if(n->pr < n->left->pr) rot_left(n);
    else if(n->pr < n->right->pr) rot_right(n);
    else update(n);
}

void insert_treap(N_T *&n,double pos,int pr,char ch)
{
    if(n==nil)
    {
        n=new N_T{1,pr,ch-96,{ch-96,ch-96},nil,nil};
        return;
    }

    if(n->left->nr+1<pos) insert_treap(n->right,pos-n->left->nr-1,pr,ch);
    else insert_treap(n->left,pos,pr,ch);

    balance(n);
}

pair<int,int> query(N_T *n,int x,int y)
{
    if(x>y) return make_pair(0,0);
    if(x==1 && n->nr<=y) return n->h;

    if(n->left->nr>=y) return query(n->left,x,y);
    else if(n->left->nr + 1 < x) return query(n->right,x-n->left->nr-1,y-n->left->nr-1);
    else return (query(n->left,x,n->left->nr) * hpow[1] + (make_pair(n->ch,n->ch))) * hpow[y-n->left->nr-1] + query(n->right,1,y-n->left->nr-1);
}

int main()
{
    int n,m,tip,x,y,l,i,pos;
    char ch;
    srand(time(NULL));
    string s;
    fin>>n>>m;
    fin>>s;

    hpow[0]={1,1};
    for(i=1;i<=n+m;++i) hpow[i]=hpow[i-1]*BASE;

    for(i=0;i<n;++i)
        insert_treap(root,(i+1)*1.0-0.5,rand()+1,s[i]);

    for(;m;--m)
    {
        fin>>tip;
        if(tip==1)
        {
            fin>>pos>>ch;
            insert_treap(root,(pos+1)*1.0-0.5,rand()+1,ch);
        }
        else
        {
            fin>>x>>y>>l;
            cout<<(query(root,x+1,x+l)==query(root,y+1,y+l))<<'\n';
        }
    }

    return 0;
}
