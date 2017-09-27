#include <iostream>
#include <cstring>
using namespace std;
void f(int x)
{
    int i,j;
    for(i=1;i<=x;i++)
    {
        j=i;
        while(j>0)
        {
            cout<<j%2;
            j=j/2;
        }
    }
}
int v(int x)
   {
       for(int i=1;i<=x;i++)
       cout<<i;
       return x+1;

   }
int main()
{
   //f(10);
   v(v(v(1)));

    return 0;
}
