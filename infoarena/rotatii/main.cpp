#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("rotatii.in");
ofstream fout("rotatii.out");
/// ////////////////////////////////

#define inf (1LL<<62)
struct N_T
{
    int nr,pr;
    long long val,sum,minSum;
    N_T *left,*right;
};

N_T *nil=new N_T {0,0,0,0,inf,NULL,NULL};
N_T *root = nil;
int pos;

void update(N_T *n)
{
    n->nr = n->left->nr + n->right->nr + 1;
    n->minSum = min(n->left->minSum,min(n->left->sum + n->val, n->left->sum + n->val + n->right->minSum));
    n->sum = n->left->sum + n->right->sum + n->val;
}

void rot_left(N_T *&n)
{
    N_T *son = n->left;

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
    else if (n->pr < n->right->pr) rot_right(n);
}

void insert_treap(N_T *&n,int pos,int val,int pr)
{
    if(n==nil)
    {
        n=new N_T {1,pr,val,val,val,nil,nil};
        return;
    }

    if(n->left->nr+1 < pos) insert_treap(n->right,pos - n->left->nr - 1,val,pr);
    else insert_treap(n->left,pos,val,pr);

    update(n);
    balance(n);
}

void delete_treap(N_T *&n,int pos)
{
    if(n->left==nil && n->right==nil)
    {
        delete n;
        n=nil;
        return;
    }

    if(n->left->nr+1==pos)
    {
        if(n->left->pr > n->right->pr) rot_left(n);
        else rot_right(n);

        delete_treap(n,pos);
    }

    else if(pos <= n->left->nr) delete_treap(n->left,pos);
    else delete_treap(n->right,pos-n->left->nr-1);

    update(n);
}

int query_treap(N_T *n,long long val)
{
    if(n->left->sum + n->val == val) return 1+n->left->nr;

    if(n->left->minSum == val) return query_treap(n->left,val);
    else return n->left->nr + 1 + query_treap(n->right,val-n->left->sum-n->val);

}

void af(N_T *n)
{
    if(n==nil) return;
    af(n->left);
    cout<<n->val<<' ';
    af(n->right);
}

int main()
{
    srand(time(NULL));
    int n,m,i,x,tip;

    fin>>n>>m;

    for(i=1; i<=n; ++i)
    {
        fin>>x;
        insert_treap(root,i,x,rand()+1);
    }

    //af(root);cout<<'\n';
    for(; m; --m)
    {
        fin>>tip;
        if(tip==0)
        {
            fin>>i>>x;
            insert_treap(root,i+1,x,rand()+1);
        }
        else if(tip==1)
        {
            fin>>i;
            delete_treap(root,i);
        }
        else
        {
            if(root->sum<0) cout<<"-1\n";
            else
            {
                x=query_treap(root,root->minSum);
                if(x==root->nr) x=0;
                cout<<x<<'\n';
            }
        }
        // af(root);cout<<'\n';
    }
    return 0;
}
