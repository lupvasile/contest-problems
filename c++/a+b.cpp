#include<iostream>
#include<fstream>
using namespace std;
ifstream f("adunare.in");
ofstream g("adunare.out");
int a,b;
int main()
{
f>>a;
f>>b;
g<<a+b;
g.close();

    return 0;
}
