#include <iostream>
#include <vector>

using namespace std;
struct elem
{
  int ok,nod;
};
vector <elem> v[100010];
elem el;
pair <int,int> v2[400010];
int m,a,x,n,b,lv2,h,i,nn;
bool ook;
int main()
{
  cin>>n>>m;
  for(; m; --m)
    {
      cin>>x;
      if (x==1)
        {
          cin>>a>>b;
          el.nod=b;
          el.ok=1;
          v[a].push_back(el);
          el.nod=a;
          v[b].push_back(el);
          v2[++lv2]=make_pair(a,b);
        }
      else if (x==2)
        {
          cin>>h;
          a=v2[h].first;
          b=v2[h].second;
          for(i=0; i<v[a].size(); ++i)
            {
              if (v[a][i].nod==b && v[a][i].ok)
                {
                  v[a][i].ok=0;
                  break;
                }
            }
          for(i=0; i<v[b].size(); ++i)
            {
              if (v[b][i].nod==a && v[b][i].ok)
                {
                  v[b][i].ok=0;
                  break;
                }
            }
        }
      else
        {
          cin>>a>>b;
          ook=1;
          for(nn=a; (nn<=b) && ook; ++nn)
            for (i=0; (i<v[nn].size()) && ook; ++i)
              if (v[nn][i].ok) if ((v[nn][i].nod<a) || (v[nn][i].nod>b))
                  {
                    ook=0;
                  }
        if(ook) cout<<"YES\n";
        else cout<<"NO\n";
        }
    }
  return 0;
}
