#include <iostream>
#include <thread>
#include <fstream>
using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");
int t;

#define dim 18
///fa coloana 0 din a

class clasa
{
public:
    int n;
    bool on[dim],a[dim][dim];
    int v[dim],rmq[dim][dim],win[dim],place[dim],res[2][dim];///0 pentru best si 1 pentru rau

    void initialize()
    {
        int i,j;
        for(i=0;i<dim;++i)
        for(j=0;j<dim;++j)
            a[i][j]=rmq[i][j]=0;
        for(i=0;i<dim;++i) {
                res[1][i]=win[i]=v[i]=on[i]=0;
                res[0][i]=20;
        }
        fin>>n;
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
                fin>>a[i][j];
    }

void bback(int k)
{
    int i;
    if(k==n+1)
    {
        int j;
        win[0]=0;
        for(i=1;i<=n;++i)
        {
            place[i]=1;
            for(j=1;j<=n;++j)
            if(win[j]>win[i]) ++place[i];
        }

        for(i=1;i<=n;++i)
        {
            if(place[i]<res[0][i]) res[0][i]=place[i];
            if(place[i]>res[1][i]) res[1][i]=place[i];
        }

        return;
    }

    if(!(k&1))///multiplu de 2
    {
        for(i=v[k-1]+1; i<=n; ++i)
            if(!on[i])
            {
                rmq[1][k]=a[v[k-1]][i] ? v[k-1]:i;

                ++win[rmq[1][k]];

                /*if(k-2>0) if(rmq[1][k-2]>rmq[1][k])
                {
                    --win[rmq[1][k]];
                    continue;
                }*/

                if(!(k&3))///multiplu de 4
                {
                    rmq[2][k] = a[rmq[1][k-2]][rmq[1][k]] ? rmq[1][k-2]:rmq[1][k];


                    if(rmq[1][k-2]>rmq[1][k])
                    {
                         --win[rmq[1][k]];
                        continue;
                    }
                     ++win[rmq[2][k]];

                    if(!(k&7))///multiplu de 8
                    {
                        rmq[3][k] = a[rmq[2][k-4]][rmq[2][k]] ? rmq[2][k-4]:rmq[2][k];


                        if(rmq[2][k-4]>rmq[2][k])
                        {
                            --win[rmq[2][k]];
                            continue;
                        }
                        ++win[rmq[3][k]];

                        if(!(k&15))
                        {
                            rmq[4][k] = a[rmq[3][k-8]][rmq[3][k]] ? rmq[3][k-8]:rmq[3][k];
                            ++win[rmq[4][k]];
                        }
                    }
                }

                on[i]=true;
                v[k]=i;
                bback(k+1);

                for(int w=1;w<5;++w) --win[rmq[w][k]];
                on[i]=false;
            }
    }
    else
        for(i=1; i<=n; ++i)
            if(!on[i])
            {
                on[i]=true;
                v[k]=i;
                bback(k+1);
                on[i]=false;
            }

}

void afis()
{
    int i;
    for(i=1;i<=n;++i)
        cerr<<res[0][i]<<' '<<res[1][i]<<'\n';
}

} th[300];



thread luna[260];

int main()
{
    int i,j,k;

    fin>>t;

    for(i=1;i<=t;++i) th[i].initialize();

    for(i=1;i<=t;++i)
                    luna[i]=thread (&clasa::bback,&th[i],1);
    for(i=1;i<=t;++i)
        if(luna[i].joinable())
    {
        luna[i].join();
        fout<<"Case #"<<i<<":\n";
        th[i].afis();
    }
    return 0;
}
