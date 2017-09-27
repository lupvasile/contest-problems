#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

ifstream f("lego.in");
ofstream g("lego.out");

#define cout g
#define nrmax 6500
#define LL long long

int pattern[nrmax][6][6];
int sol_curenta[6][6],nr_sol;
long long nr_constructii;
int i,j,h;
string A[7],B[7];
vector <pair<int,long long> > p[8];//p[i] imi zice ce patternuri pot avea pe stratul i

void afisare(int a[][6])
{
    for(int i=0; i<=5; ++i)
    {
        for(int j=0; j<=5; ++j)
            cout<<a[i][j]<<' ';
        cout<<'\n';
    }

}
void pune(int i,int j,int val)//seteaza patratelul cu val (pune o piesa pe plansa)
{
    sol_curenta[i][j]=sol_curenta[i][j+1]=sol_curenta[i+1][j]=sol_curenta[i+1][j+1]=val;
}
void adauga_solutie()
{
    ++nr_sol;//cout<<nr_sol<<'\n';
    for(int i=0; i<=5; ++i) for(int j=0; j<=5; ++j) pattern[nr_sol][i][j]=sol_curenta[i][j];
}
bool liber(int i,int j)//daca pot pune o piesa cu coltul stanga sus i,j
{
    return (sol_curenta[i][j] || sol_curenta[i][j+1] || sol_curenta[i+1][j] || sol_curenta[i+1][j+1])==false;
}
bool egale(int a[][6],int b[][6])
{
    for(int i=0; i<=5; ++i) for(int j=0; j<=5; ++j) if((a[i][j]==0 )&& b[i][j] || a[i][j] && (b[i][j]==0)) return false;
    return true;
}
bool nu_mai_este()
{
    for(int i=1; i<=nr_sol; ++i) if (egale(pattern[i],sol_curenta)) return false;
    return true;
}
void generare_patternuri(int nr_piese,int limita_linie,int limita_coloana)
{
    int i,j;// i si j reprezinta coltul dreapta sus al unei piese
    //if(nr_sol<=5000000)
    for(i=0; i<=4; ++i)
        for(j=0; j<=4; ++j)
            if(i>limita_linie || (i==limita_linie && j>=limita_coloana))
                if (liber(i,j))
                {
                    pune(i,j,nr_piese);
                    //if(nu_mai_este())
                    adauga_solutie();
                    generare_patternuri(nr_piese+1,i,j);
                    pune(i,j,0);
                }
}
bool se_suprapune(int a[][6],int b[][6])//daca pot sa pun b pe a
{
    int i,j,lim(0);
    bool v[10];
    memset(v,0,sizeof v);
    for(i=0;i<=5;++i) for(j=0;j<=5;++j)
    {
        lim=max(lim,b[i][j]);
        if(a[i][j]) v[b[i][j]]=true;
    }
    for(i=1;i<=lim;++i) if (v[i]==false) return false;
    return true;
}
long long are_baza(int m,int niv)
{
    if (niv==0) return 1;
    long long nr=0;
    for(int i=0;i<p[niv].size();++i) if (se_suprapune(pattern[p[niv][i].first],pattern[m])) nr+=p[niv][i].second;
    return nr;
}
long long coincide_cu_poza(int m,int niv)
{
    char v[10];
    memset(v,'.',sizeof v);
    int i,j;
    for(i=0;i<=5;++i)
    {
        for(j=0;pattern[m][i][j]==0 && j<=5;++j);
        if(A[niv][i]=='.') {if(j<=5) return 0;}
        else
        {if (j>5) return 0;
        if (v[pattern[m][i][j]]!='.'){if (v[pattern[m][i][j]]!=A[niv][i]) return 0;}
        else v[pattern[m][i][j]]=A[niv][i];
        }

        for(j=5;j>=0 && pattern[m][j][i]==0;--j );
        if(B[niv][i]=='.') {if(j>=0) return 0;}
        else
        {if(j<0) return 0;
        if (v[pattern[m][j][i]]!='.'){if(v[pattern[m][j][i]]!=B[niv][i]) return 0;}
        else v[pattern[m][j][i]]=B[niv][i];}
    }
    long long nr=1;
    int lim=0;
    for(i=0;i<=5;++i) for(j=0;j<=5;++j) lim=max(lim,pattern[m][i][j]);
    for(i=1;i<=lim;++i) if (v[i]=='.') nr*=3LL;
    return nr;
}
void gaseste_posibilitati(int niv)
{
    int i,nr_loc;
    long long n,nn;
    for(i=1;i<=nr_sol;++i)
    {
      n=coincide_cu_poza(i,niv);
      nn=are_baza(i,niv-1);
      if(n && nn)p[niv].push_back(make_pair(i,n*nn));
      }
}
int main()
{
    nr_sol=1;
    generare_patternuri(1,0,0);
    //cout<<nr_sol<<'\n';
    //for(int i=1; i<=nr_sol; ++i) afisare(pattern[i]),g<<"asdf\n";
    //afisare(pattern[2]);
    /*for(int i=1; i<=nr_sol; ++i) for(int j=i+1; j<=nr_sol; ++j) if (egale(pattern[i],pattern[j]))
            {
                cout<<"loser";
                return 0;
            }
*/
    /*int a[6][6],b[6][6];
     for(int i=0; i<=5; ++i) for(int j=0; j<=5; ++j) a[i][j]=1;
     for(int i=0; i<=5; ++i) for(int j=0; j<=5; ++j) b[i][j]=4;
    cout<<egale(a,b);*/
    f>>h;
    for(i=h;i;--i) f>>A[i];
    for(i=h;i;--i) f>>B[i];
    //for(i=1;i<=2;++i) cout<<B[i]<<'\n';
    for(i=1;i<=h;++i)
    {
       gaseste_posibilitati(i);
    }
    //afisare(pattern[2]);
    //A[1]="WW....";
    //B[1]="WW....";
    //cout<<coincide_cu_poza(2,1);
    //cout<<p[h].size()<<'\n';
    for(i=0;i<p[h].size();++i) nr_constructii+=p[h][i].second;
    cout<<nr_constructii;
    //int r=0;
    //for(i=0;i<p[1].size();++i) r+=p[1][i].second;
    //cout<<r;
    g.close();
    return 0;
}
