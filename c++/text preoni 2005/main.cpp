#include <iostream>
#include <fstream>

using namespace std;

ifstream f("text.in");
ofstream g("text.out");

char v_c,c;
int nrcuv,lcuv;
int main()
{
  while (!f.eof())
    {
      f.get(c);
      if (c>='a' && c<='z' || c>='A' && c<='Z')
        {
          ++lcuv;
          if(!(v_c>='a' && v_c<='z' || v_c>='A' && v_c<='Z')) ++nrcuv;
        }
      v_c=c;
    }
    //cout<<nrcuv<<' '<<lcuv;
    g<<lcuv/nrcuv;
  return 0;
}
