#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

ifstream f("dir.in");
ofstream g("dir.out");

string s,q;
vector <string> v,cale;
int i,j;
//#define cout g

int main()
{
    f>>s;
    for(i=0;i<s.length();++i)
    {
        if(s[i]>='A' && s[i]<='Z')
        {
            j=s.find('(',i);
            v.push_back(s.substr(i,j-i));
            i=j;
        }
        if(s[i]>='a' && s[i]<='z')
        {
            if(v.size())q="\\",cale.push_back(v[0]);
            else q="",cale.push_back("");
            j=cale.size()-1;
            while (isdigit(s[i]) || islower(s[i])) q+=s[i],++i;
            for(int i=1;i<v.size();++i) cale[j]+="\\"+v[i];
            cale[j]+=q;
        }
        if (s[i]==')') v.pop_back();
    }
    sort(cale.begin(),cale.end());
    cout<<cale.size()<<'\n';
    for(i=0;i<cale.size();++i) g<<cale[i];
    return 0;
}