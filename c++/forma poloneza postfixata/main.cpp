#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");
char c,oper[100],polon[100];
float stiva[100];
int lp,lo,a,b,ls,i;
bool prioritate_mica(char c)
    {
    if(c=='+' || c=='-') if (oper[lo]=='*' || oper[lo]=='/') return true;
    return false;
    }
int main()
    {
    while (f>>c)
        {
        if(c>='0' && c<='9')
            {
            lp++;
            polon[lp]=c;
            }
        else if (c=='(')
            {
            lo++;
            oper[lo]=c;
            }
        else if (c==')')
            {
            while (oper[lo]!='(')
                {
                lp++;
                polon[lp]=oper[lo];
                lo--;
                }
            lo--;
            }
        else
            {
            while (prioritate_mica(c))
                {
                lp++;
                polon[lp]=oper[lo];
                lo--;
                }
            lo++;
            oper[lo]=c;
            }
        }
    while(lo>0)
        {
        lp++;
        polon[lp]=oper[lo];
        lo--;
        }
    //cout<<polon+1;
    //cout<<polon+1<<'\n';
    ls=0;
    for(i=1; i<=lp; i++)
        if (polon[i]>='0' && polon[i]<='9')
            {
            ls++;
            stiva[ls]=polon[i]-'0';
            }
        else
            {
            a=stiva[ls];
            b=stiva[ls-1];
            ls--;
            switch (polon[i])
                {
                case '+':
                    stiva[ls]=a+b;
                    break;
                case '-':
                    stiva[ls]=a-b;
                    break;
                case '*':
                    stiva[ls]=a*b;
                    break;
                case '/':
                    stiva[ls]=a/b;
                    break;
                }
            }
    cout<<stiva[ls];
    return 0;
    }
