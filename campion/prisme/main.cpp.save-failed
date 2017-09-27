#include <iostream>
#include <fstream>

using namespace std;

ifstream f("prisme.in");
ofstream g("prisme.out");
#define cout g
bool use[8];
int out[8],ord[8],pr[8][3],maxx,i;
void det_rot(int lev)
{
    int i;
    if(lev==7)
    {
        if(pr[ord[lev-1]][(out[lev-1]+1)%3]!=pr[1][(out[1]+2)%3]) return;
        int sum=0;
        for(i=1;i<=6;++i) sum+=pr[ord[i]][out[i]];
        maxx=max(maxx,sum);
        return;
    }
    for(i=0;i<3;++i)
        if(lev==1 || pr[ord[lev-1]][(out[lev-1]+1)%3]==pr[ord[lev]][(i+2)%3])
    {
        out[lev]=i;
        det_rot(lev+1);
    }
}
void det_ord(int lev)
{
    int i;
    if(lev==7)
    {
        det_rot(1);
        return;
    }
    for(i=2;i<=6;++i) if(!use[i])
    {
        use[i]=true;
        ord[lev]=i;
        det_ord(lev+1);
        use[i]=false;
    }
}

int main()
{
    for(i=1;i<=6;++i) f>>pr[i][0]>>pr[i][1]>>pr[i][2];
    use[1]=true;
    ord[1]=1;
    det_ord(2);
    cout<<maxx;
    return 0;
}
