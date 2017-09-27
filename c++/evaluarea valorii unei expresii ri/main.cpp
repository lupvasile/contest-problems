#include <iostream>
#include <fstream>

using namespace std;

ifstream f("evaluare.in");
ofstream g("evaluare.out");

char s[100000];
int i;
int termen();
int factor();
int eval()
{
    int r=termen();
    while (s[i]=='+' || s[i]=='-')
    {
        switch (s[i])
         {
             case '+':++i,r+=termen();break;
             case '-':++i,r-=termen();break;
         }
    }
    return r;
}
int termen()
{
    int r=factor();
    while (s[i]=='*' || s[i]=='/')
    {
        switch (s[i])
         {
             case '*':++i,r*=factor();break;
             case '/':++i,r/=factor();break;
         }
    }
    return r;

}
int factor()
{
    int r=0;
    if (s[i]=='(')
        {
            ++i;
            r=eval();
            ++i;
        }
    else while(s[i]>='0' && s[i]<='9')
            {
                r=r*10+s[i]-'0';
                ++i;
            }
            return r;
}
int main()
{
    f>>s;
    g<<eval();
    return 0;
}
