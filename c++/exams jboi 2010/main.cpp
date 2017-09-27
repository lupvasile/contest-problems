#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream f("exams.in");
ofstream g("exams.out");

#define cout g

long long n,t,v[40],i,mask;
long long number_of_ways;
vector <long long> x,y;
long long s,lx,ly;
void v_1()
{
    lx=n/2;
    ly=n-n/2;
    for(mask=0; mask<(1LL<<lx); ++mask)
    {
        s=0;
        for(i=0; (1LL<<i)<=mask; ++i)
            if(mask & (1LL<<i)) s+=v[i];
        x.push_back(s);
    }
    n>>=1;
    for(mask=0; mask<(1LL<<ly); ++mask)
    {
        s=0;
        for(i=0; (1LL<<i)<=mask; ++i)
            if(mask & (1LL<<i)) s+=v[n+i];
        y.push_back(s);
    }
    sort(y.begin(),y.end());
    for(i=0;i<x.size();++i)
    {
        s=lower_bound(y.begin(),y.end(),t-x[i])-y.begin();
        number_of_ways+=(y.size()-s);
    }
}
void v_2()
{
    for(mask=0;mask<=(1LL<<n);++mask)
    {
        s=0;
        for(i=0;(1LL<<i)<=mask;++i)
        if(mask & (1LL<<i)) s+=v[i];
        if(s>=t) ++number_of_ways;
    }
}
int main()
{
    f>>n>>t;
    for(i=0; i<n; ++i) f>>v[i];
    v_1();
    cout<<number_of_ways;
    return 0;
}
