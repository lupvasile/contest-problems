#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream f("reactii.in");
ofstream g("reactii.out");
struct eee{int lo,hi;};
vector <eee> stack;
int n,m,vf,i;
#define cout g
bool intersectie (int a,int b, int x,int y)
{
    if(x-1>b || a-1>y) return false;
    return true;
}
int main()
{
    f>>n>>m;
    stack.resize(n+2);
    for(;m;--m)
    {
        vf=0;
        for(i=1;i<=n;++i)
        {
            f>>stack[++vf].lo;
            stack[vf].hi=stack[vf].lo;
            while (vf>1 && intersectie(stack[vf-1].lo , stack[vf-1].hi , stack[vf].lo , stack[vf].hi)) stack[--vf]={min(stack[vf].lo,stack[vf+1].lo),max(stack[vf].hi,stack[vf+1].hi)};
        }
        if(vf==1) cout<<"1\n";
        else cout<<"0\n";
    }
    return 0;
}
