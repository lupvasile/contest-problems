#include <iostream>
#include <deque>
#include <fstream>

using namespace std;

ifstream f("deque.in");
ofstream g("deque.out");

deque <int> d;
int i,n,a[5000010],k,x;
long long sum;
int main()
{
    f>>n>>k;
    for(i=1;i<=n;++i) f>>a[i];
    for(i=1;i<=n;++i)
    {
        while (!d.empty() && a[d.back()]>=a[i]) d.pop_back();
        d.push_back(i);
        if(d.front()==i-k) d.pop_front();
        if(i>=k)sum+=a[d.front()];
        //cout<<a[d.front()]<<' ';
    }
    g<<sum;
    return 0;
}
