#include <iostream>
#include <fstream>

using namespace std;

ifstream f("amedie.in");
ofstream g("amedie.out");

#define cout g
#define nmax 820
#define val_max 100101
#define foor(i,a,b) for(i=a;i<=b;++i)

int a[nmax][nmax],v[nmax*nmax],pos[val_max],w[val_max],maxx,l;
int right1[nmax*nmax],left1[nmax*nmax];
int i,j,n,m,p,q,mediana,nr_elemente,x;
char c;

void sortare()//acuma sortezi matricea si faci right[i] si left[i]
{
  foor(i,1,maxx)
  {
    for(; w[i]; --w[i]) v[++l]=i;
    if(v[l]==i) pos[i]=l;
  }
  foor(i,1,l)
  {
    right1[i]=i+1;
    left1[i]=i-1;
  }
}
void elimina(int i,int j)
{
    int x=pos[a[i][j]];
    if(v[left1[x]]==v[x]) pos[a[i][j]]=left1[x];
    else pos[a[i][j]]=0;
    if(nr_elemente%2==0)
    {
        if(x<=mediana) mediana=right1[mediana];
    }
    else if(x>=mediana)mediana=left1[mediana];
    --nr_elemente;
    right1[left1[x]]=right1[x];
    left1[right1[x]]=left1[x];
    a[i][j]=-1;
}
int main()
{
  f>>n>>m>>q;
  foor(i,1,n) foor(j,1,m)
  {
    f>>a[i][j];// in w o sa ai un sir de frecventa pentru sortare
    ++w[a[i][j]];
    maxx=max(a[i][j],maxx);
  }
  nr_elemente=n*m;
  mediana=(nr_elemente+1)/2;
  sortare();
  for(; q; --q)
    {
      f>>c;
      switch (c)
        {
        case 'L':
        {
          f>>x;
          foor(i,1,m) if(a[x][i]>-1) elimina(x,i);
          break;
        }
        case 'C':
        {
          f>>x;
          foor(i,1,n) if(a[i][x]>-1) elimina(i,x);
          break;
        }
        case 'Q':
        {
          cout<<v[mediana]<<'\n';
          break;
        }
        }
    }
  return 0;
}
