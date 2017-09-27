#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#ifdef INFOARENA
#define cout g
#endif // INFOARENA

ifstream f("matrice2.in");
ofstream g("matrice2.out");

#define nmax 310
#define qmax 20010

int a[nmax][nmax];
int depl[4][2]={ {-1,0},{0,1},{1,0},{0,-1} };
struct elem_mat_sorted
    {
    int x,y;
    bool operator<(elem_mat_sorted b)const
        {
        return a[x][y]>a[b.x][b.y];
        }
    bool operator==(elem_mat_sorted b)
    {
        return (x==b.x && y==b.y);
    }
    bool operator!=(elem_mat_sorted b)
    {
        return !(x==b.x && y==b.y);
    }
    } dad[nmax][nmax],d;
struct elem_q
    {
    int x1,y1,x2,y2,val;
    } Q[qmax];

int n,nrq,i,j,hmax,step,pos,nx,ny,new_val,xx,yy;
int q_sorted[qmax];
vector <elem_mat_sorted> mat_sorted;

bool cmp_q(int a,int b)
    {
    return Q[a].val>Q[b].val;
    }

elem_mat_sorted d_dad(elem_mat_sorted nod)
{
    if(dad[nod.x][nod.y]!=nod) dad[nod.x][nod.y]=d_dad(dad[nod.x][nod.y]);
    return dad[nod.x][nod.y];
}

bool query(int x1,int y1,int x2,int y2)
{
    return (d_dad(dad[x1][y1])==d_dad(dad[x2][y2]));
}

int main()
    {
    f>>n>>nrq;
    for(i=1; i<=n; ++i)
        for(j=1; j<=n; ++j)
            {
            f>>a[i][j];
            mat_sorted.push_back({i,j});
            hmax=max(hmax,a[i][j]);
            }

    sort(mat_sorted.begin(),mat_sorted.end());

    for(i=1; i<=nrq; ++i)
        {
        f>>Q[i].x1>>Q[i].y1>>Q[i].x2>>Q[i].y2;
        q_sorted[i]=i;
        }

    for(step=1; step<=hmax; step<<=1);
    step>>=1;

    for(; step; step>>=1)
        {
        pos=0;
        sort(q_sorted+1,q_sorted+nrq+1,cmp_q);
        for(i=1; i<=n; ++i)
            for(j=1; j<=n; ++j) dad[i][j]= {i,j};
        for(i=1; i<=nrq; ++i)
            {
            new_val=Q[q_sorted[i]].val+step;
            while (a[mat_sorted[pos].x][mat_sorted[pos].y]>=new_val && pos<n*n)
                {
                for(j=0; j<=3; ++j)
                    {
                    nx=mat_sorted[pos].x+depl[j][0];
                    ny=mat_sorted[pos].y+depl[j][1];
                    if(a[nx][ny]>=new_val)
                    {
                        d=d_dad({nx,ny});
                        if(d!=d_dad(mat_sorted[pos])) dad[d.x][d.y]=mat_sorted[pos];
                    }
                    }
                ++pos;
                }

            if(query(Q[q_sorted[i]].x1,Q[q_sorted[i]].y1,Q[q_sorted[i]].x2,Q[q_sorted[i]].y2)) Q[q_sorted[i]].val=new_val;

            }
        }
    for(i=1;i<=nrq;++i) cout<<Q[i].val<<'\n';
    return 0;
    }
