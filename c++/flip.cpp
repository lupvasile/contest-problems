#include<iostream>
#include<fstream>
using namespace std;
ifstream f("flip.in");
ofstream g("flip.out");
int j,s,n,m,a,i,s1[17],s2[17],s3[17],s4[17],v[17][17];
void incearca(int i,int j;)
{

}
int main()
{
f>>n>>m;
//for (j=1;j<=m;j++) cout<<s4[j]<<" ";
//cout<<"\n";
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
           {
             f>>v[i][j];
             s1[i]+=v[i][j];
             //s2[i]+=-v[i][j];
             s3[j]+=v[i][j];
            // s4[j]+=-v[i][j];
           }
/*for (i=1;i<=n;i++)
    if (s1[i]<s2[i]) for (j=1;j<=m;j++)
        {s3[j] -=2*v[i][j];
        s4[j]  -=2*(-v[i][j]);
     //   cout<<i<<"\n";
        }
for (j=1;j<=m;j++) s += max(s3[j],s4[j]);
for (j=1;j<=m;j++) cout<<s4[j]<<" ";cout<<"\n";
for (j=1;j<=m;j++) cout<<s3[j]<<" ";
*/
for (i=1;i<=n;i++) for (j=1;j<=m;j++) if (v[i][j]<0) incearca(i,j);
                else s+=s1;
g<<s;
g.close();

    return 0;
}