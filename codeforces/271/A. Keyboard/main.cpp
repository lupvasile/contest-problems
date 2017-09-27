#include <iostream>
//#include <fstream>
//#include <algorithm>
using namespace std;


char s[110];
int pos[200];
char d;
int i,p;
/*struct elele{char a,l,r;} m[40];
bool cmp(elele a,elele b)
{
    return a.a<b.a;
}*/
char vvv[30][3]={{',','m','.'},{'.',',','/'},{'/','.','7'},{';','l','7'},{'a','7','s'},{'b','v','n'},{'c','x','v'},{'d','s','f'},{'e','w','r'},{'f','d','g'},{'g','f','h'},{'h','g','j'},{'i','u','o'},{'j','h','k'},{'k','j','l'},{'l','k',';'},{'m','n',','},{'n','b','m'},{'o','i','p'},{'p','o','7'},{'q','7','w'},{'r','e','t'},{'s','a','d'},{'t','r','y'},{'u','y','i'},{'v','c','b'},{'w','q','e'},{'x','z','c'},{'y','t','u'},{'z','7','x'}};

int main()
{
    /*cin>>s;
    for(i=0;s[i]!='\0';++i)
    {
        if(i>0 && s[i+1]!='\0') cout<<s[i]<<' '<<s[i-1]<<' '<<s[i+1]<<'\n';
        if(i==0) cout<<s[i]<<' '<<"7"<<' '<<s[i+1]<<'\n';
        if (s[i+1]=='\0') cout<<s[i]<<' '<<s[i-1]<<' '<<"7\n";
    }

    sort(m+1,m+31,cmp);
     for(i=1;i<=30;++i) cout<<m[i].a<<' '<<m[i].l<<' '<<m[i].r<<'\n';

    for(i=1;i<=30;++i) f>>m[i].a>>m[i].l>>m[i].r;
    for(i=1;i<=30;++i) cout<<"{'"<<m[i].a<<"','"<<m[i].l<<"','"<<m[i].r<<"'},";
    */
    for(i=0;i<30;++i) pos[vvv[i][0]]=i;
    cin>>d;
    cin>>s;
    if(d=='R') p=1;
    else p=2;
    for(i=0;s[i]!='\0';++i) cout<<vvv[pos[s[i]]][p];
    return 0;
}
