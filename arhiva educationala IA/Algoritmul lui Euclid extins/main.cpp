#include <bits/stdc++.h>
using namespace std;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA
ifstream fin("euclid3.in");
ofstream fout("euclid3.out");
/// ////////////////////////////////////////

void euclid_extins(int a,int b,int &x,int &y,int &d)
{
    if(b==0)
    {
        d=a;
        y=0;
        x=1;
        return;
    }
    else
    {
        int x1,y1;
        euclid_extins(b,a%b,x1,y1,d);
        x=y1;
        y=x1-y1*(a/b);
    }
}

int main()
{
    int T,x,y,d,a,b,c;
    fin>>T;
    for(;T;--T)
    {
        fin>>a>>b>>c;
        euclid_extins(a,b,x,y,d);
        if(c%d!=0) cout<<"0 0\n";
        else cout<<x*(c/d)<<' '<<y*(c/d)<<'\n';
    }
    return 0;
}
