#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>
#include <tr1/unordered_map>
using namespace std;
using namespace tr1;
#ifdef INFOARENA
#define cout fout
#endif // INFOARENA

ifstream fin("base3.in");
ofstream fout("base3.out");

inline int abs(int x)
{
    return x>0?x:-x;
};

struct eee
{
    int state,dist;
    bool operator <(eee a) const
    {
        if(dist!=a.dist)return dist>a.dist;
        return abs(state)>abs(a.state);
    }
} top;

priority_queue<eee> q;
unordered_map<int,int> m;
#define nmax 16001

int len[3];
char s[3][nmax];

int main()
{
    int i,j;
    for(i=0; i<3; ++i)
    {
        fin>>s[i];
        len[i]=strlen(s[i]);
    }

    for(i=0; i<3; ++i)
        for(j=0; j<len[i]; ++j)
            if(s[i][j]=='1')
            {
                q.push({len[i]-j-j-1,len[i]});
                //     m[len[i]-j-j-1]=m[len[i]-j-j-1]>0?min(m[len[i]-j-j-1],len[i]):len[i];
            }

    while(!q.empty())
    {
        top=q.top();
        q.pop();
        //cerr<<top.dist<<'\n';
        if(top.state==0)
        {
            cout<<top.dist;
            return 0;
        }
        for(i=0; i<3; ++i)
        {
            if(top.state<0)
            {
                if(!m[top.state+len[i]] || m[top.state+len[i]]>top.dist+len[i])
                {
                    q.push({top.state+len[i],top.dist+len[i]});
                    m[top.state+len[i]]=top.dist+len[i];
                }
            }
            else if(!m[top.state-len[i]] || m[top.state-len[i]]>top.dist+len[i])
            {
                q.push({top.state-len[i],top.dist+len[i]});
                m[top.state-len[i]]=top.dist+len[i];
            }
        }
    }
    cout<<0;
    return 0;
}
