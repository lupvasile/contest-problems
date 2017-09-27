#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

ifstream f("showroom.in");
ofstream g("showroom.out");

#define nmax 502
#define cout g
#define mod 9001

int a,r,k,n,i,nr_modele,this_root,j,nr_companii;

string s;
map <string,int> m;
vector <int> lines[nmax],company_sizes,power;
int tree_size[103*nmax],father[nmax*103];
int ciur[50000];
void do_erast(int n)
{
  long long i,j;
  for(j=2; j<=n; j+=2) ciur[j]=2;
  for(i=3; i<=n; i+=2)
    {
      if(ciur[i]==0)
      {
        for(j=i*i; j<=n; j+=i) ciur[j]=i;
        ciur[i]=i;
      }
    }
}
int get_root(int k)
{
  if(father[k]==0) return k;
  return get_root(father[k]);
}
void add_powers(int i)
{
    if(i<=1) return;
    ++power[ciur[i]];
    add_powers(i/ciur[i]);
}
void sub_powers(int i)
{
    if(i<=1) return;
    --power[ciur[i]];
    sub_powers(i/ciur[i]);
}
int get_combination(int n,int k)
{
    int res(1),j,i;
    power.clear();power.resize(n+1);
    for(i=n-k+1;i<=n;++i)add_powers(i);
    for(i=2;i<=k;++i)sub_powers(i);
    if(n>1)res=1LL*(res<<(power[2]))%mod;
    for(i=3;i<=n;i+=2)
    for(j=1;j<=power[i];++j) res=1LL*res*i%mod;
    return res;
}
void unite(int root1,int root2)
{
  root1=get_root(root1);
  root2=get_root(root2);
  if(root1==root2) return;
  if(tree_size[root1]<tree_size[root2]) swap(root1,root2);
  father[root2]=root1;
  tree_size[root1]+=tree_size[root2];
}
int main()
{
  f>>n>>a>>r>>k;
  f.get();
  //citirea
  for(i=1; i<=n; ++i)
    {
      getline(f,s);
      stringstream ss(s);
      while (ss>>s)
        {
          if(m.find(s)==m.end())
            {
              ++nr_modele;
              m[s]=nr_modele;
            }
          lines[i].push_back(m[s]);
        }
    }
//gata citirea
  for(i=1; i<=n; ++i)
    {
      this_root=nr_modele+i;
      for(j=0; j<lines[i].size(); ++j)
        {
          if(father[lines[i][j]]==0)
            {
              father[lines[i][j]]=this_root;
              ++tree_size[this_root];
            }
          else
            {
              unite(this_root,father[lines[i][j]]);
              this_root=get_root(this_root);
            }
        }
    }
  set<int> used_roots;
  int maxx=k;
  for(i=1; i<=n; ++i)
    {
      this_root=get_root(father[lines[i][0]]);
      if(used_roots.find(this_root)==used_roots.end())
        {
          company_sizes.push_back(tree_size[this_root]);
          maxx=max(maxx,tree_size[this_root]);
          used_roots.insert(this_root);
        }
    }
  do_erast(maxx);
int solution(1);
for(i=0;i<company_sizes.size();++i)
{
    if(a<=company_sizes[i]) solution=(1LL*solution*get_combination(company_sizes[i],a))%mod;
    a=(a+r)%k;
}
cout<<company_sizes.size()<<'\n'<<solution<<'\n';
//cout<<maxx;
//cout<<"amea";
/*for(i=0;i<company_sizes.size();++i)
{
    cout<<i<<' '<<a<<' ';
   if(a<=company_sizes[i]) cout<<get_combination(company_sizes[i],a)%mod;
   //else cout<<0;
    a=(a+r)%k;
    cout<<'\n';

}
*/
//do_erast(500);
//cout<<"\n"<<get_combination(1,1);
  return 0;
}
