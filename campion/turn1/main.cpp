#include <cstdio>
#include <iostream>
using namespace std;

#define nmax 10010

int n,m,x,y,xx,yy,max1,max2;
int T[nmax],R[nmax];

int find(int x)
    {
    if(x!=T[x]) T[x]=find(T[x]);
    return T[x];
    }
void uneste(int a,int b)
    {
    if(R[a]>=R[b])
        {
        T[b]=a;
        R[a]+=R[b];
        }
    else
        {
        T[a]=b;
        R[b]+=R[a];
        }
    }
int main()
    {
    freopen("turn1.in","r",stdin);
    freopen("turn1.out","w",stdout);

    scanf("%d%d",&n,&m);

    for(int i=1; i<=n; ++i) T[i]=i,R[i]=1;
    for(; m; --m)
        {
        scanf("%d%d",&x,&y);
        xx=find(x);
        yy=find(y);
        if(xx!=yy) uneste(xx,yy);
        }
    for(int i=1; i<=n; ++i)
        if(i==T[i])//x e radacina
            {

            if(R[i]>R[max1])
                {
                max2=max1;
                max1=i;
                }
            else if (R[i]>R[max2]) max2=i;
            }
    if(max1==0 || max2==0) printf("1 1");
    else
    printf("%d %d",max1,max2);

    return 0;
    }
