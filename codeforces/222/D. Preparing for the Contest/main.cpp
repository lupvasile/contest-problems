#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

#define nmax 100010

int nr_s,nr_b,i,s;
int bug[nmax],s_bug[nmax],fix[nmax];//cine repara bug-ul i
int s_stud[nmax];
struct {int skill,cost;} stud[nmax];

bool cmp_bug(int a,int b);
bool cmp_stud(int a,int b);
bool possible(int days,int s);
int gi();



int main()
{
    #ifndef ONLINE_JUDGE
    freopen("date.in","r",stdin);
    #endif // ONLINE_JUDGE

    nr_s=gi();nr_b=gi();s=gi();
    for(i=1;i<=nr_b;++i)
    {
        bug[i]=gi();
        s_bug[i]=i;
    }
    sort(s_bug+1,s_bug+nr_b+1,cmp_bug);

    for(i=1;i<=nr_s;++i)
    {
        stud[i].skill=gi();
        s_stud[i]=i;
    }
    for(i=1;i<=nr_s;++i) stud[i].cost=gi();
    sort(s_stud+1,s_stud+nr_s+i,cmp_stud);

    int st=1,dr=nr_b,m;

    while (st<=dr)
    {
        m=(st+dr)/2;
        if(possible(m,s)) dr=m-1;
        else st=m+1;
    }
    if(st>nr_b) cout<<"NO";
    else
    {
        possible(st,s);
        cout<<"YES\n";
        for(i=1;i<=nr_b;++i) cout<<fix[i]<<' ' ;
    }

   return 0;
}

struct cmp_queue
{
    bool operator() (int a,int b)
    {
        return stud[a].cost>stud[b].cost;
    }
};

bool possible(int days,int s)
{

    int pos_s=1,pos_b=1,x,i;
    priority_queue <int, vector<int> ,cmp_queue> q;
    while(pos_b<=nr_b)
    {
        while(stud[s_stud[pos_s]].skill>=bug[s_bug[pos_b]])
        {
            q.push(s_stud[pos_s]);
            ++pos_s;
        }
        if(q.empty()) return false;
        x=q.top();
        q.pop();
        s-=stud[x].cost;
        if(s<0) return false;
        for(i=0;i<days && pos_b+i<=nr_b;++i) fix[s_bug[pos_b+i]]=x;
        pos_b+=days;
    }
    return true;

}

bool cmp_bug(int a,int b)
{
    return bug[a]>bug[b];
}
bool cmp_stud(int a,int b)
{
    return stud[a].skill>stud[b].skill;
}

#define nbuf 30000
int p(nbuf);
char buf[nbuf];
int gi()
{
    int n=0;
    while (buf[p]<'0' || buf[p]>'9')
        if(++p>=nbuf) cin.read(buf,nbuf),p=0;

    while(buf[p]>='0' && buf[p]<='9' )
    {
        n=n*10+buf[p]-'0';
         if(++p>=nbuf) cin.read(buf,nbuf),p=0;
    }
    return n;
}

