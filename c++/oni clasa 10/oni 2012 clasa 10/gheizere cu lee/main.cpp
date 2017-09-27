#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream f("teste/0-gheizere.in");
ofstream g("gheizere.out");

#define nmax 1003
#define pb push_back
#define mp make_pair
#define tr(container,iterator)\
for(__typeof(container.begin()) it=container.begin();it!=container.end();++it)
//#define cout g
int n,m,p,v,e;
int x,y,r,t,d,nx,ny;
int i,j,timp;
int depl[3][2]={{-1,0},{0,1},{1,0}};
vector <pair<int,int> > a[nmax][nmax];
queue <pair<int,int> > q;
int vizitat[nmax][nmax];//in vizitat faci parcurgerea
bool ok;

bool on_map(int i,int j)
{
  return i>=1 && j>=1 && i<=n && j<=m;
}
int main()
{
  f>>n>>m>>p;
  f>>v>>e;
  for(; p; --p)
    {
      f>>x>>y>>r>>t>>d;
      for(i=x-r; i<=x+r; ++i)
        for(j=y-r; j<=y+r; ++j)
          if(on_map(i,j))
            {
              a[i][j].pb(mp(t,d));
            }
    }

  /*for(i=1;i<=n;++i)
  {
  for(j=1;j<=m;++j) if (a[i][j].empty()) cout<<"0 ";
  else cout<<"1 ";
  cout<<'\n';
  }*/
  q.push(mp(v,1));
  vizitat[v][1]=1;
  while (!q.empty())
    {
      x=q.front().first;
      y=q.front().second;
      q.pop();
      for(i=0; i<=2; ++i)
        {
          nx=x+depl[i][0];
          ny=y+depl[i][1];
          if(on_map(nx,ny) && (!vizitat[nx][ny]))
          {
              ok=true;
              tr(a[nx][ny],it)
              {
                  ok=true;
                  int sum=((it->first)+(it->second));
                 // if(nx==7 && ny==2) cout<<((vizitat[x][y]+1)%sum>=it->first);
            if((vizitat[x][y])%sum>=it->first)
                {
                    ok=false;
                   //if(nx==7 && ny==2)cout<<(((vizitat[x][y]+1)%((it->first)+(it->second)))>=(it->first));
                    break;
                }
              }
              if(ok)
              {
                  vizitat[nx][ny]=vizitat[x][y]+1;
                  q.push(mp(nx,ny));
                  if (nx==e && ny==m)
                  {
                      cout<<vizitat[nx][ny]<<'\n';
                      return 0;
                  }
              }
          }

        }
    }

  for(i=1;i<=n;++i)
  {
  for(j=1;j<=m;++j)  cout<<vizitat[i][j]<<' ';

  cout<<'\n';
  }
  return 0;
}
