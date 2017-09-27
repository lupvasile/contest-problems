#include <iostream>
#include <fstream>
using namespace std;
//ifstream f("teste/0-SUDEST.IN");
ifstream f("sudest.in");
ofstream g("sudest.out");
// in a tiiminte matricea
//in v tii minte numaru de pasi
//in sol tii minte solutia
#define foor(i,a,b) for(i=a;i<=b;i++)
#define cout g
int a[101][101],v[201],k,n,i,j,sol[201],maxx,x,y;
struct
    {
    int x,y;
    } sud,est;
bool back(int i,int x,int y,int sum)
    {bool ok(false);
    int aux;
    if(x>n || x<1 || y>n || y<1) return false;
    else if (i<=k)
        {
        if (back(i+1, x+v[i]*sud.x, y+v[i]*sud.y, sum+a[x+v[i]*sud.x][y+v[i]*sud.y]))
            {
            sol[i]=1;
            ok=true;
            }
        if (back(i+1, x+v[i]*est.x, y+v[i]*est.y, sum+a[x+v[i]*est.x][y+v[i]*est.y]))
            {
            sol[i]=2;
            ok=true;
            }
            return ok;
        }
    else if(x!=n || y!=n) return false;
    else if (sum>maxx)
        {
        maxx=sum;
        return true;
        }
    else return false;
    }
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
    back(1,1,1,a[1][1]);
    cout<<maxx<<'\n';
    x=y=1;
    cout<<"1 1\n";
    foor(i,1,k) {
    if (sol[i]==1) x+=v[i]*sud.x,y+=v[i]*sud.y;
    if (sol[i]==2) x+=v[i]*est.x,y+=v[i]*est.y;
    cout<<x<<' '<<y<<'\n';
    }
    return 0;
    }
