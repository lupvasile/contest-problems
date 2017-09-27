#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("mexc.in");
ofstream fout("mexc.out");
#define MAX 810
struct sebi{
    int tip, val;
    int i, j;
} q[3 * MAX * MAX];

sebi make_sebi(int t, int v, int ix, int jx)
{
    sebi s;
    s.tip = t;
    s.val = v;
    s.i = ix;
    s.j = jx;
    return s;
}

bool cmp(sebi a, sebi b)
{
    if(a.val == b.val)
        return a.tip > b.tip;
    return a.val > b.val;
}

int dr, tata[MAX * MAX], comp, s[MAX * MAX], rez[MAX][MAX], dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int a[MAX][MAX];
int dad(int nod)
{
    if(nod != tata[nod])
        tata[nod] = dad(tata[nod]);
    return tata[nod];
}

void unite(int d, int f)
{
   // if(d==0 || f==0) return;
    if(dad(f) != dad(d))
    {
        int t = dad(f);
        tata[t] = d;
        s[dad(d)] += s[t];
        s[t] = 0;
    }
}

int main()
{
    int n, m, d, i, j, x, ni, nj, k, nni, nnj;;
    fin >> n >> m >> d;
    for(i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j < m ; j++)
        {
            fin >> x;
            q[++dr] = make_sebi(0, x, i, j);
            q[++dr] = make_sebi(1, x, i, j);
            q[++dr] = make_sebi(2, x + d, i, j);
        }
    }
    for(i = 1 ; i <= n * m ; i++)
    {
       // s[i] = 1;
        tata[i] = i;
    }

    /*int vasi(0);
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j) a[i][j]=++vasi;
*/
    sort(q + 1, q + dr + 1, cmp);
    for(i = 1 ; i <= dr ; i ++)
    {
     //   cout << q[i].val << " " << q[i].tip << " " << q[i].i << " " << q[i].j << "\n";
        if(q[i].tip == 2)
        {
            ++comp;
            ni = q[i].i;
            nj = q[i].j;
            a[ni][nj] = comp;
            for(k = 0 ; k < 4 ; k++)
            {
                nni = ni + dir[k][0];
                nnj = nj + dir[k][1];
                if(nni<0 || nnj<0 || nni>=n || nnj>=m) continue;
                if(a[nni][nnj])
                {
                    unite(a[ni][nj], a[nni][nnj]);
                }
            }
        }
        else if(q[i].tip == 1)
        {
            s[dad(a[q[i].i][q[i].j])]++;
        }
        else if(q[i].tip == 0)
        {
            rez[q[i].i][q[i].j] = s[dad(a[q[i].i][q[i].j])];
        }
    }
    #define cout fout
    for(i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j < m ; j++)
        {
            cout << rez[i][j] << " ";
        }
        cout << "\n";
    }
}
