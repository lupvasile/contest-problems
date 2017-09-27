#include <iostream>

using namespace std;
int n,v[100],i;
void f(int x)
{
    int i,j;
    for(i=1;i<=x;i++)
    {
        j=i;
        while(j>0)
        {
            v[++n]=j%2;
            j=j/2;
        }
    }
}
int main()
{
    f(10);
    int s(1),maxx(0);
    for(i=2;i<=n;i++)
    {
        if(v[i]==v[i-1]) s++;
        else s=1;
        if(s>maxx) maxx=s;
    }
    cout<<maxx;
    return 0;
}

