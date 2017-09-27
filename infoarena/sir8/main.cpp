#include <bits/stdc++.h>
using namespace std;
#define INFOARENA 1
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("sir8.in");
ofstream fout("sir8.out");
/// ////////////////////////////////

void read();
void make_hpow();

#define  mod1  666013
#define  mod2  700001
#define BASE 27
#define g_nr(c) ((c) - 'a' + 1)
#define nmax 60002

vector<pair<int,int>> hsh;
vector<int> sz;
pair<int,int> hpow[nmax],res_q;

struct T
{
    int nr,pr,val;
    pair<int,int> h;
    T *left,*right;
};

T *nil=new T {0,0,0,{0,0},NULL,NULL};
T *root=nil;

pair<int,int> operator * (const pair<int,int> &a,const pair<int,int> &b)
{
    return make_pair(1ll*a.first*b.first%mod1,1ll*a.second*b.second%mod2);
}

pair<int,int> operator + (const pair<int,int> &a,const pair<int,int> &b)
{
    pair<int,int> p;
    p.first = a.first + b.first;
    p.second = a.second + b.second;

    if(p.first >= mod1) p.first-=mod1;
    if(p.second >= mod2) p.second-=mod2;

    return p;
}

pair<int,int> operator * (const pair<int,int> &a,int x)
{
    return make_pair(a.first*x%mod1,a.second*x%mod2);
}



void update(T *n)
{
    n->nr = n->left->nr + n->right->nr + 1;
    n->h = (n->left->h * hpow[1] + make_pair(n->val,n->val) ) * hpow[n->right->nr] + n->right->h;
}

void rot_left(T *&n)
{
    T *son = n->left;

    n->left = son->right;
    son->right = n;

    update(n);
    update(son);

    n = son;
}

void rot_right(T *&n)
{
    T *son = n->right;

    n->right = son->left;
    son->left = n;

    update(n);
    update(son);

    n = son;
}

void balance(T *&n)
{
    if(n->left->pr > n->pr) rot_left(n);
    else if(n->right->pr > n->pr) rot_right(n);
    else update(n);
}

void insert_treap(T *&n,int pos,int pr,int val)
{
    if(n==nil)
    {
        n=new T{1,pr,val,{val,val},nil,nil};
        return;
    }

    if(pos > n->left->nr + 1) insert_treap(n->right,pos-n->left->nr-1,pr,val);
    else insert_treap(n->left,pos,pr,val);

    balance(n);
}

void query_treap(T *n,int x,int y)
{
    if(x>y) return ;

    if(x==1 && n->nr<=y)
    {
        res_q = res_q * hpow[n->nr] + n->h;
        return ;
    }

    if(n->left->nr >=x) query_treap(n->left,x,min(n->left->nr,y));
    if(y>=n->left->nr + 1 && x<=n->left->nr + 1) res_q = res_q * hpow[1] + make_pair(n->val,n->val);
    if(y>n->left->nr + 1) query_treap(n->right,max(1,x-n->left->nr-1),y-n->left->nr-1);

}

int main()
{
    srand(time(0));

    make_hpow();
    read();

    int m,tip,x=0,pos,ind,a,b;
    char ch;

    fin>>m;
    for(; m; --m)
    {
        fin>>tip>>pos;

        if(tip==0) fin>>ch;
        else   fin>>ind;

        fin>>a>>b;
        if(x) pos^=b;
        else pos^=a;

        if(tip==0) insert_treap(root,pos,rand()+1,g_nr(ch));
        else
        {
            res_q={0,0};
            query_treap(root,pos-sz[ind]+1,pos);
            cout<<(x = (res_q==hsh[ind]) )<<'\n';
        }

    }

    return 0;
}

void make_hpow()
{
    hpow[0]={1,1};
    for(int i=1;i<nmax;++i) hpow[i]=hpow[i-1] * BASE;
}

void make_hash(string &s, pair<int,int> &h, int &sz)
{
    sz=s.size();

    for(int i=0;i<sz;++i)
        h=h*hpow[1] + make_pair(g_nr(s[i]),g_nr(s[i]));
}

void read()
{
    int i,n;
    string s;

    fin>>s;
    for(i=0; i<s.size(); ++i)
        insert_treap(root,i+1,rand()+1,g_nr(s[i]));

    fin>>n;

    sz.resize(n+1);
    hsh.resize(n+1);

    for(i=1; i<=n; ++i)
    {
        fin>>s;
        make_hash(s,hsh[i],sz[i]);
    }
}
