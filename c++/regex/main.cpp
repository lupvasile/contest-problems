#include <iostream>
#include <string>

using namespace std;

string a;
int main()
{
   cin>>a;
   if(a.find("Yardi")!=string::npos) cout<<"YES";
   else cout<<"NO";
    return 0;
}
