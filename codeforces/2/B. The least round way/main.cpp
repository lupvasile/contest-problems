#include <iostream>

using namespace std;

#define nmax 1001

int dp2[nmax][nmax],dp5[nmax][nmax],a[nmax][nmax];
struct eee{int x,y;} from2[nmax][nmax],from5[nmax][nmax];
bool caz_0;
int n,i,j,x;

void make_dp(int dp[][nmax],eee from[][nmax])
{

}

int main()
{
    cin>>n;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
    {
        cin>>a[i][j];
        x=a[i][j];
        if(x==0) x=10,caz_0=true;

        while(x%2==0)
        {
            ++dp2[i][j];
            x/=2;
        }

        while(x%5==0)
        {
            ++dp5[i][j];
            x/=5;
        }

    }

    make_dp(dp2,from2);
    make_dp(dp5,from5);
    return 0;
}
