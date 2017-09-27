#include<iostream>
#include<fstream>
#include <math.h>
using namespace std;
ifstream f("lgput.in");
ofstream g("lgput.out");
int n,p;
int main()
{
f>>n>>p;
g<<pow(n,p) % 1999999973;
g.close();

    return 0;
}
