#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

ifstream f("fibo.in");
ofstream g("fibo.out");

#define cout g

int fib[]= {1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040};
int i,n,nsol;
bool sol[40];

#define l_f 28

void back(int lev,long long nr)
{
    if(lev>14) return;
    int i,k;
    long long s=nr;
    sol[lev]=0;
    if(nr>n) return;
    if(sol[0]==false) goto asdf;
    k=lev+1;
    for(i=lev-1; i>=0&& k<=l_f; --i,++k)
    {
        s+=sol[i]*fib[k];
    }
    if(s<=n && s>0 && i==-1)
        ++nsol;
    if(s<=n)
    {
        s=nr;
        k=lev+1;
        for(i=lev; i>=0&& k<=l_f; --i,++k)
        {
            s+=sol[i]*fib[k];
        }
        if(s<=n && s>0 && i==-1)
                ++nsol;
    }
    back(lev+1,nr);
    asdf:;
    if(lev) if(sol[lev-1]==1) return;
    sol[lev]=1;
    s=nr+fib[lev];
    if(s>n || s<0) return;
    k=lev+1;
    for(i=lev-1; i>=0&& k<=l_f; --i,++k)
    {
        s+=sol[i]*fib[k];
    }
    if(s<=n && s>0 && i==-1)
            ++nsol;
    back(lev+1,nr+fib[lev]);

}

int main()
{
    f>>n;
    back(0,0);
    cout<<nsol;
    return 0;
}
