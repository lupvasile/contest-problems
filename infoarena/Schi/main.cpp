#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

struct N_TREAP
{
    short ind,nr;
    int priority;
    N_TREAP *left,*right;

} *nil = new N_TREAP {0,0,0,NULL,NULL};

class C_TREAP
{
private:
    N_TREAP *root=nil;

    void update_sons(N_TREAP *n)
    {
        n->nr = n->left->nr + n->right->nr + 1;
    }

    void rot_left(N_TREAP *&n)
    {
        N_TREAP *son = n->left;
        n->left = son->right;
        son->right = n;

        update_sons(n);
        update_sons(son);

        n=son;
    }

    void rot_right(N_TREAP *&n)
    {
        N_TREAP *son = n->right;
        n->right = son->left;
        son->left = n;

        update_sons(n);
        update_sons(son);

        n=son;
    }

    void balance(N_TREAP *&n)
    {
        if(n->left->priority > n->priority) rot_left(n);
        else if(n->right->priority > n->priority) rot_right(n);
    }

    void insert(N_TREAP *&n,short ind,short pos)
    {
        if(n==nil)
        {
            n= new N_TREAP{ind,1,rand()+1,nil,nil};
            return;
        }

        if(pos<=n->left->nr+1) insert(n->left,ind,pos);
        else insert(n->right,ind,pos-n->left->nr-1);

        update_sons(n);

        balance(n);
    }

    void dfs(N_TREAP *n)
    {
        if(n==nil) return;
        dfs(n->left);
        printf("%d\n",n->ind);
        dfs(n->right);
    }
public:
    void add(int ind,int pos)
    {
        insert(root,ind,pos);
    }

    void show()
    {
        dfs(root);
    }

} treap;

int main()
{
    int i,n,x;

    srand(time(NULL));

    freopen("schi.in","r",stdin);
    freopen("schi.out","w",stdout);

    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&x);
        treap.add(i,x);
    }
    treap.show();
    return 0;
}
