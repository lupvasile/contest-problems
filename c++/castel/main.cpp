#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

ifstream f("castel.in");
ofstream g("castel.out");

#define nmax 151
#define cout g
int n,m,i,j,k,nr,last_nr,w,x,y,nx,ny;
int a[nmax][nmax],stare[nmax][nmax],acces[nmax][nmax];
vector <int> key[nmax*nmax];
queue <int> q;
void afisare(int v[][nmax]);

inline int to_x(int k)
{
  return (k-1)/m+1;
}
inline int to_y(int k)
{
  return (k-1)%m+1;
}
inline int to_key(int i,int j)
{
  return (i-1)*m+j;
}
inline int deplx(int x,int i)
{
  if (i==1) return x-1;
  else if (i==2) return x;
  else if (i==3) return x+1;
  else return x;
}
inline int deply(int y,int i)
{
  if (i==1) return y;
  else if (i==2) return y+1;
  else if (i==3) return y;
  else return y-1;
}
void open(int k)
{
  int i,x,y;
  for(i=0; i<key[k].size(); ++i)
    {
      x=to_x(key[k][i]);
      y=to_y(key[k][i]);
      acces[x][y]=1;
      if(stare[x][y]==2) stare[x][y]=1,q.push(key[k][i]);
    }
  key[k].clear();
}
int main()
{
  f>>n>>m>>k;
  for(i=1; i<=n; i++)
    for(j=1; j<=m; j++)
      {
        f>>a[i][j];
        key[a[i][j]].push_back(to_key(i,j));
      }
  q.push(k);
  while (q.size())
    {
      x=to_x(q.front());
      y=to_y(q.front());
      open(q.front());
      q.pop();
      stare[x][y]=1;
      //afisare(stare);
      for(int i=1; i<=4; i++)
        {
          nx=deplx(x,i);
          ny=deply(y,i);
          if (a[nx][ny]>0 && stare[nx][ny]!=1)
            if (acces[nx][ny])
                q.push(to_key(nx,ny));
            else stare[nx][ny]=2;
        }
    }
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    if(stare[i][j]==1) ++nr;
  cout<<nr;
  return 0;
}
void afisare(int v[][nmax])
{
  int i,j;
  for(i=1; i<=n; i++)
    {
      for(j=1; j<=m; j++) cout<<v[i][j]<<' ';
      cout<<"\n";
    }
  cout<<"*************************\n";
}