#include <fstream>
using namespace std;
ifstream f("flip.in");
ofstream g("flip.out");
int n, m, a[20][20], x[20], maxim;
bool c[20];
void Calculare()
{int sum = 0;
for(int j=1; j <=m; j++)
{  int sum2 = 0;
for(int i=1; i<=n; i++)
if(c[i]) sum2 += -a[i][j];
        else sum2 += a[i][j];
if(sum2 < -sum2)
 sum2 = -sum2;
    sum += sum2;
if(maxim < sum) maxim = sum;
 }}
  void Back(int k)
  {    if(k == n+1) Calculare();
      else        for(int j=0; j<=1; j++)
              {            c[k] = j;
                       Back(k+1);
                            }}
int main()
{    f>>n>>m;
    for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
                f>>a[i][j];
        Back(1);
            g<<maxim;
             return 0;
             }
