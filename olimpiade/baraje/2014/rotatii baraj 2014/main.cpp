#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream f("rotatii.in");
ofstream g("rotatii.out");

#define cout g
#define nmax 1000010

int fdm[nmax],fsm[nmax],pm[nmax],radm;
int fds[nmax],fss[nmax],ps[nmax],rads;
int n,i,rad;
vector <pair<int, int> > mvs,mvm;

void cit_si_cons(int fs[],int fd[],int p[],int &rad);
void forma_de_mijloc(int fs[],int fd[],int p[],int rad,int sens);
void afisare();
int gi();

int main()
{
    n=gi();
    cit_si_cons(fsm,fdm,pm,radm);
    cit_si_cons(fss,fds,ps,rads);
    forma_de_mijloc(fss,fds,ps,rads,1);
    forma_de_mijloc(fsm,fdm,pm,radm,0);
    afisare();
    return 0;
}

void afisare()
{
    cout<<mvs.size()+mvm.size()<<'\n';
    for(int i=0; i<mvs.size(); ++i) cout<<mvs[i].first<<' '<<mvs[i].second<<'\n';
    for(int i=mvm.size()-1; i>=0; --i) cout<<mvm[i].first<<' '<<mvm[i].second<<'\n';
}

void forma_de_mijloc(int fs[],int fd[],int p[],int rad,int sens)
{
    int b,c,d,pp,i(0);
    for(i=1; i<=n; ++i)
    {
        while(fd[rad])
        {
            pp=p[rad],b=rad,d=fd[rad],c=fs[d];

            fs[d]=b;
            fd[b]=c;
            if(b==fs[pp]) fs[pp]=d;
            if(b==fd[pp]) fd[pp]=d;
            rad=d;
            if(sens==1) mvs.push_back(make_pair(2,b));
            else mvm.push_back(make_pair(1,d));
        }
        rad=fs[rad];
    }
}


void cit_si_cons(int fs[],int fd[],int p[],int &rad)
{
    for(i=1; i<=n; ++i)
    {
        fs[i]=gi();
        fd[i]=gi();
        p[fs[i]]=p[fd[i]]=i;
    }
    for(i=1; i<=n; ++i)
        if(p[i]==0)
        {
            rad=i;
            break;
        }
}

#define nb 100000
int pos(nb);
char b[nb];
int gi()
{
    int n(0);
    while(b[pos]<'0' || b[pos]>'9') if(++pos>=nb) f.read(b,nb),pos=0;
    while (b[pos]>='0' && b[pos]<='9')
    {
        n=n*10+b[pos]-'0';
        if(++pos>=nb) f.read(b,nb),pos=0;
    }
    return n;
}
