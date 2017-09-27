#include <iostream>
#include <fstream>
#include <set>
#include <queue>

using namespace std;

ifstream f("zone2.in");
ofstream g("zone2.out");

#define foor(i,a,b) for(i=a;i<=b;++i)
#define nmax 302
#define tr(container,it)\
        for(__typeof(container.begin()) it=container.begin();it!=container.end();++it)
#define cout g

int numar_zone;
int n,m,k,nr;
int i,j,v[nmax][nmax],grad[nmax*nmax];
char a[nmax][nmax];
int depl[4][2]= {{-1,0},{0,1},{1,0},{0,-1}};
set <int> vecini[nmax*nmax];
queue <int> q;
int nod;
void fill(int x,int y,int nr)
{
  int i;
  if(v[x][y]>0) return;
  v[x][y]=nr;
  for(i=0; i<=3; ++i)
    {
      if (a[x][y]==a[x+depl[i][0]][y+depl[i][1]]) fill(x+depl[i][0],y+depl[i][1],nr);
    }
}
void gaseste_vecini(int x,int y,int val)
{
  int i,nx,ny;
  if(a[x][y])
    {
      a[x][y]=0;
      for(i=0; i<=3; ++i)
        {
          nx=x+depl[i][0];
          ny=y+depl[i][1];
          if(v[nx][ny])
            if(v[x][y]!=v[nx][ny])vecini[val].insert(v[nx][ny]);
            else gaseste_vecini(nx,ny,val);
        }
    }
}
int main()
{
  f>>n>>m>>k;
  foor(i,1,n) foor(j,1,m) f>>a[i][j];
  foor(i,1,n) foor(j,1,m) if(v[i][j]==0) ++numar_zone,fill(i,j,numar_zone);
  foor(i,1,n) foor(j,1,m) if(isalpha(a[i][j]))
    {
      gaseste_vecini(i,j,v[i][j]);
      if (vecini[v[i][j]].size()<k) q.push(v[i][j]);
      grad[v[i][j]]=vecini[v[i][j]].size();
    }
  while (!q.empty())
    {
      nod=q.front();
      q.pop();
      tr(vecini[nod],it)
      {
        if (grad[*it]>=k)
          {
            --grad[*it];
            if(grad[*it]<k)
              q.push(*it);
          }
      }
    }
    foor(i,1,n) foor(j,1,m) if(grad[v[i][j]]>=k) ++nr;
    cout<<nr;
  return 0;
}
