#include <iostream>
#include <fstream>
#include <queue>
#include <iomanip>
#include <stack>
using namespace std;
//ifstream f("teste/0-SUDEST.IN");
ifstream f("sudest.in");
ofstream g("sudest.out");
// in a tiiminte matricea
//in v tii minte numaru de pasi
//in sol tii minte solutia
#define foor(i,a,b) for(i=a;i<=b;i++)
#define cout g
int a[101][101],v[201],k,n,i,j,maxx,x,y,cmax[101][101],pas[101][101],ii,jj;
struct un_element
    {
    int x,y;
    };
un_element sud,est,el;
queue <un_element> q;
stack <un_element> stiva;


int main()
    {
    f>>n;
    sud.x=1;
    sud.y=0;
    est.x=0;
    est.y=1;
    foor(i,1,n) foor(j,1,n) f>>a[i][j];
    f>>k;
    foor(i,1,k) f>>v[i];
    cmax[1][1]=a[1][1];
    pas[1][1]=1;
    el.x=el.y=1;
    q.push(el);
    while(!q.empty())
        {
        el.x=q.front().x+v[pas[q.front().x][q.front().y]]*sud.x;
        el.y=q.front().y+v[pas[q.front().x][q.front().y]]*sud.y;
        if (el.x>=1 && el.x<=n && el.y>=1 && el.y<=n && cmax[q.front().x][q.front().y]+a[el.x][el.y]>cmax[el.x][el.y] && pas[q.front().x][q.front().y]<=k)
            {
            cmax[el.x][el.y]=cmax[q.front().x][q.front().y]+a[el.x][el.y];
            q.push(el);
            pas[el.x][el.y]=pas[q.front().x][q.front().y]+1;
            }
        el.x=q.front().x+v[pas[q.front().x][q.front().y]]*est.x;
        el.y=q.front().y+v[pas[q.front().x][q.front().y]]*est.y;
        if (el.x>=1 && el.x<=n && el.y>=1 && el.y<=n && cmax[q.front().x][q.front().y]>cmax[el.x][el.y]&& pas[q.front().x][q.front().y]<=k)
            {
            cmax[el.x][el.y]=cmax[q.front().x][q.front().y]+a[el.x][el.y];
            q.push(el);
            pas[el.x][el.y]=pas[q.front().x][q.front().y]+1;
            }
        /*foor(ii,1,n)
                {
                foor(jj,1,n)cout<<setw(3)<<cmax[ii][jj];
                cout<<'\n';
                }
                cout<<"*********************************************\n\n";*/
        q.pop();
        }
    /*foor(ii,1,n)
        {
        foor(jj,1,n)cout<<setw(3)<<pas[ii][jj];
        cout<<'\n';
        }*/
    cout<<cmax[n][n]<<'\n';
    x=y=1;
    el.x=el.y=n;
    stiva.push(el);
    while(k)
        {
        if (cmax[el.x-v[k]*sud.x][el.y-v[k]*sud.y]>cmax[el.x-v[k]*est.x][el.y-v[k]*est.y])
            {
            el.x=el.x-v[k]*sud.x;
            el.y=el.y-v[k]*sud.y;
            stiva.push(el);
            //cout<<el.x<<' '<<el.y<<"\n";
            }
        else
            {
            el.x=el.x-v[k]*est.x;
            el.y=el.y-v[k]*est.y;
            stiva.push(el);
            //cout<<el.x<<' '<<el.y<<"\n";
            }
        k--;
        }
        while (!stiva.empty())
        {
           cout<<stiva.top().x<<' '<<stiva.top().y<<'\n';
          stiva.pop();
        }
    //cout<<v[0];
    return 0;
    }
