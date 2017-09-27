#include<iostream>
#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025],b[1025],m,n,j,i;
int d[1025][1025];
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++) f>>a[i];
    for(i=1;i<=m;i++)f>>b[i];
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
        {
            if (a[i]==b[j])
                    d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    int l,sir[1025];
    l=0;
  /*  cout<<"  ";
    for (i=1;i<=m;i++,cout<<b[i]<<" ");
    cout<<"\n";
    for (i=1;i<=n;i++){cout<<a[i]<<" ";for (j=1;j<=m;j++,cout<<d[i][j]<<" "); cout<<"\n";}*/
    for (i=n,j=m;i && j;)
    {   if (a[i]==b[j]) sir[++l]=a[i],--i,--j;
        else if (d[i-1][j]<d[i][j-1]) --j;
        else --i;
    }
    g<<l<<"\n";
    for (i=l;i;i--) g<<sir[i]<<" ";
    g.close();
return 0;
}
