#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

ifstream f("numar2.in");
ofstream g("numar2.out");

int n,m,x,l;
priority_queue <pair<int,int> > q;

int main()
{
    f>>n>>m;
    for(;n;--n)
    {
        f>>x;
        q.push({-x,-x});
    }
    l=0;
    while(m>1)
    {
        if(q.top().first!=l)
        {
            --m;
            l=q.top().first;
        }
        q.push({q.top().first+q.top().second,q.top().second});
        q.pop();
    }
    while(q.top().first==l) q.pop();
    g<<-q.top().first;
    return 0;
}
