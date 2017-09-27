#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");
int i,v[100],n;
inline int father(int k)
{
    return k/2;
}
inline int left_son(int k)
{
    return 2*k;
}
inline int right_son(int k)
{
    return 2*k+1;
}
void sift(int k)
{
    int son;
    do
    {
        son=0;
        if (left_son(k)<=n)
        {
            son=left_son(k);

            if (right_son(k)<=n && v[right_son(k)]>v[left_son(k)]) son=right_son(k);
            if (v[k]<v[son])
            {
                swap(v[k],v[son]);
                k=son;
            }
        else son=0;
        }
    }
    while (son);
}
int main()
{
    f>>n;
    for(i=1; i<=n; i++) f>>v[i];
    for(i=n/2; i>=1; i--)
    {
        sift(i);
    }
    for(i=1;i<=n;i++) cout<<v[i]<<' ';
    return 0;
}
