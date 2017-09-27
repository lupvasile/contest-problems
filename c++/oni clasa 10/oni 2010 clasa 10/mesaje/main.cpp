#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <bitset>
#include <cstring>
#include <algorithm>
using namespace std;

ifstream f("mesaje.in");
ofstream g("mesaje.out");

#define cout g
#define pb push_back

istringstream ss;
string s;
//char cs[30502];
vector <string> mesaj;
int nrcuv,i,n,maxx,nr_cuv_bune;
struct
{
    long long hi,lo;
} cuv[15000];
struct eee
{
    long long hi,lo;
    int pos;
    bool operator < (const eee & a) const
    {
        if (a.hi!=hi) return hi>a.hi;
        if (a.lo!=lo) return lo>a.lo;
        return pos<a.pos;
    }
} ;
vector <eee> v;
bitset <130> on;
void rev(int pos)
{
    for(int i=mesaj[pos].size()-1; i>=0; --i) cout<<mesaj[pos][i];
}
int main()
{
    getline(f,s);
    ss.str(s);
    while (ss>>s) mesaj.pb(s);
    nrcuv=mesaj.size();
    while (f.good())
    {
        ++n;
        for(i=0; i<nrcuv; ++i)
        {
            f>>s;
            if (!f.good()) break;
            if (s==mesaj[i])
            {
                if(n>=64) cuv[i].hi|=(1LL<<(n-64));
                else cuv[i].lo|=(1LL<<(n-1));
                if(maxx<n)
                {
                    maxx=n;
                    nr_cuv_bune=1;
                }
                else if (maxx==n) ++nr_cuv_bune;
            }
        }
    }
    --n;
    if(maxx==0)
    {
        cout<<nrcuv<<'\n';
        for(i=0; i<nrcuv; ++i) rev(i),cout<<' ';
    }
    else
    {
        cout<<nr_cuv_bune<<'\n';
        if (maxx>63) for(i=0;i<nrcuv;++i) if (cuv[i].hi & (1LL<<(maxx-64))) v.push_back({cuv[i].hi,cuv[i].lo,i});
        if (maxx<=63)for(i=0;i<nrcuv;++i) if (cuv[i].lo & (1LL<<(maxx-1))) v.push_back({cuv[i].hi,cuv[i].lo,i});
        sort(v.begin(),v.end());
        for(i=0;i<v.size();++i) rev(v[i].pos),cout<<' ';
    }
    //if (maxx)for(i=1;i<=nrcuv;++i) if ()


    return 0;
}
