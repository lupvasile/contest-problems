#include <iostream>
#include <fstream>
#include <set>
#include <vector>
using namespace std;

ifstream f("competition.in");
ofstream g("competition.out");

#define kmax 10010
#define mp make_pair
#define ff first
#define ss second

int time[kmax],power_lap[kmax];
int k,n,i,nr,maxx,id_player,nr_tura;
struct el{int timp,nr_tura,id;};
struct cmp
{
    bool operator() (el a, el b)
    {
        return a.timp<=b.timp;
    }
};
multiset <el,cmp, allocator<int>  > v;//timpul curent la linia de start,numarul turei incheiate, id-ul atletului
el last_element,element;
int main()
{
    f>>k>>n;
    for(i=1; i<=k; ++i)
    {
        f>>time[i]>>power_lap[i];
        v.insert({time[i],1,i});
    }
    while (!v.empty())
    {
        element=*v.begin();
        v.erase(v.begin());
        if(element.timp==last_element.timp) ++nr;
        else nr=1;
        last_element=element;
        id_player=element.id;
        nr_tura=element.nr_tura;
        if(nr_tura<n)
        {
            element.timp+=time[id_player]+nr_tura%power_lap[id_player];
            ++element.nr_tura;
            v.insert(element);
        }
        maxx=max(maxx,nr);
    }
    cout<<maxx;
    return 0;
}
