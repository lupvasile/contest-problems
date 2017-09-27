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
void percolate(int k)
    {
    int val=v[k];
    while(father(k)>0 && val>v[father(k)])
        {
        v[k]=v[father(k)];
        k=father(k);
        }
    v[k]=val;
    }
void build_heap()
    {
    for(i=n/2; i>=1; i--)
        {
        sift(i);
        }
    }
void heap_sort()
{   int naux=n,aux;
    while(n>=2)
    {
        swap(v[1],v[n]);
        n--;
        sift(1);
    }
    n=naux;
}
int main()
    {
    f>>n;
    for(i=1; i<=n; i++) f>>v[i];
    build_heap();
    heap_sort();
    for(i=1; i<=n; i++) cout<<v[i]<<' ';
    return 0;
    }
