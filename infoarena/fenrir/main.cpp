#include <iostream>
#include <fstream>

using namespace std;

ofstream fout("fenrir.out");

#define cout fout

int main()
{
    int i,j;
    cout<<"99\n";
    for(i=1;i<=9;++i)
        for(j=10;j<=20;++j)
            cout<<i<<' '<<j<<'\n';
    return 0;
}
