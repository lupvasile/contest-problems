#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int n=200;
bool a[201][201];
void find_new(int &x,int &y)
{
    x=rand()%200;
    y=rand()%200;
}
int main()
{
    srand(time(NULL));
    int res=100,ml,mc,nr,x,y,i,j;
    while (res!=0)
    {
        /*ml=mc=nr=0;
        for(i=1; i<=n; ++i)
            for(j=1; j<=n; ++j)
                if(!a[i][j])
                {
                    ml+=i;
                    mc+=j;
                    ++nr;
                }
        x=ml/nr;
        y=mc/nr;
        if(a[x][y]) find_new(x,y);*/
        do
        {
            find_new(x,y);
        } while(a[x][y]);
        cout<<x<<' '<<y<<'\n';
        cout.flush();
        cin>>res;
        if(res!=0)
        {
            if(res<0){
                for(i=x;i>=0;--i)
                {
                    for(j=y;j>=0;--j)
                    if(a[i][j]) break;
                    else a[i][j]=1;
                }
            }
            else
            {
                for(i=x;i<n;++i)
                {
                    for(j=y;j<n;++j)
                    if(a[i][j]) break;
                    else a[i][j]=1;
                }
            }
        }
    }
    return 0;
}
