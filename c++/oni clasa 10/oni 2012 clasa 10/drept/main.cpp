#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#define cout g

ifstream f("drept3.in");
ofstream g("drept3.out");

int n,x,y,d,i;
struct element {int coord,tip,dreptunghi; };//0 intrare,1 iesire
vector <element> eveniment_x,eveniment_y;
bool activ[11000];
int lx,ly,dr_active,last_y,max_act,aria,j;
bool cmp(element a,element b)
{
    if(a.coord!=b.coord) return (a.coord<b.coord);
    return a.tip>b.tip;
}
int main()
{
    f>>n;
    eveniment_x.push_back({0,2,0});
    eveniment_y.push_back({0,2,0});
    for(i=1;i<=n;++i)
    {
        f>>x>>y>>d;
        eveniment_x.push_back({x,0,i});
        eveniment_x.push_back({x+d,1,i});
        eveniment_y.push_back({y,0,i});
        eveniment_y.push_back({y+d,1,i});
    }
    sort(eveniment_x.begin(),eveniment_x.end(),cmp);
    sort(eveniment_y.begin(),eveniment_y.end(),cmp);

    for(i=1;i<eveniment_x.size();++i)
    {
        lx=eveniment_x[i].coord-eveniment_x[i-1].coord;
        ly=0;
        if(lx)
        {
            dr_active=0;
            last_y=0;
            for(j=1;j<eveniment_y.size();++j)
            if(activ[eveniment_y[j].dreptunghi])
            {
                if(dr_active>0) ly+=eveniment_y[j].coord-last_y;
                last_y=eveniment_y[j].coord;
                if(eveniment_y[j].tip==0) ++dr_active;
                else --dr_active;
                max_act=max(dr_active,max_act);
            }
        }
        aria+=ly*lx;
        if(eveniment_x[i].tip==0) activ[eveniment_x[i].dreptunghi]=true;
        else activ[eveniment_x[i].dreptunghi]=false;
    }
    cout<<aria<<'\n'<<max_act;
        return 0;
}
