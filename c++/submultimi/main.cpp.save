#include <iostream>
#include <fstream>
using namespace std;
ifstream f("submultimi.in");
ofstream g("submultimi.out");
int s[20],n;
#define cout g
void back(int k)
{
    int i;
    for(i=1;i<k;++i) cout<<s[i]<<' ';
    if (k>1) cout<<'\n';
    for(i=s[k-1]+1;i<=n;++i)
    {
        s[k]=i;
        if(k<=n) back(k+1);
    }
}
int main()
{
f>>n;
//back(1);
back_mai_tare();
    return 0;
}
