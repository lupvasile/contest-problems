#include <iostream>

using namespace std;

int main()
{
    int nr,dci,cd,uc,d,ok;
    cout<<"nr=";
    cin>>nr;
    d=2;
    dci=0;
    while (d<= nr/2)
    if (nr %d==0)
    cd=d;
    ok=1;
    while (cd==0)
    uc=cd%10;
    cd=cd/10;
    if (uc%2==0)
    ok=0;

    if(ok==1)
    dci=dci+1;

    d=d+1;

    cout<<"dci="<<endl;




    return 0;
}
