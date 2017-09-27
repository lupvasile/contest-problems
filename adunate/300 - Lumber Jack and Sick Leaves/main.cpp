#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector<int> bus;
int n,credit;

void afis()
{
    cout<<2<<' '<<bus.size()<<' ';
    for(auto it:bus) cout<<it<<' ';
    cout<<'\n';
    cout.flush();
    cerr<<credit;
    exit(0);
}

bool posibil(int a,int b)
{
    if(a==b) return 1;
    credit+=(b-a+1);
    return 0;
    if(credit>8*n) afis();
    cout<<1<<' '<<a<<' '<<b<<'\n';
    cout.flush();
    cin>>a;
    return a;
}

int caut(int x)
{
    int st(x),dr(n),mid,sol;
    while(st<=dr)
    {
        mid=(st+dr)>>1;
        if(posibil(x,mid))
        {
            st=mid+1;
            sol=mid;
        }
        else dr=mid-1;
    }

    return sol;
}

int main()
{
    int i,x,start;
    cin>>n;
    start=1;
    while(start<=n)
    {
        bus.push_back(start);
        start=caut(start)+1;
    }

    afis();

    return 0;
}

