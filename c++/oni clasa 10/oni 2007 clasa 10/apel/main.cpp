#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

ifstream f("apel.in");
ofstream g("apel.out");

#define cout g
#define nmax 252

char functia[nmax],s[nmax],para[27][10];//in para is variabilele
char ff[nmax],fff[27][nmax];//in fff sunt functiile
int aritate[30],ii;
char ss[nmax];
char c;
int x,pos,i;
int termen();
int factor();
int evalueaza()
{
    int r=termen();
    while (ss[ii]=='+' || ss[ii]=='-')
    {
        switch (ss[ii])
         {
             case '+':++ii,r+=termen();break;
             case '-':++ii,r-=termen();break;
         }
    }
    return r;
}
int termen()
{
    int r=factor();
    while (ss[ii]=='*' || ss[ii]=='/')
    {
        switch (ss[ii])
         {
             case '*':++ii,r*=factor();break;
             case '/':++ii,r/=factor();break;
         }
    }
    return r;

}
int factor()
{
    int r=0;
    if (ss[ii]=='(')
        {
            ++ii;
            r=evalueaza();
            ++ii;
        }
    else while(ss[ii]>='0' && ss[ii]<='9')
            {
                r=r*10+ss[ii]-'0';
                ++ii;
            }
            return r;
}
string fa_string(int a)
{
    string t="";
    if (a==0) return "0";
    while (a){
        t=t+(char)(a%10+'0');
    a/=10;
    }
    reverse(t.begin(),t.end());
    return t;
}
int eval(const char s[],int f)
{
    int para[30];
    memset(para,0,sizeof para);
    int p=2,p1;
    for(i=1;i<aritate[f];++i)
    {
        if (s[p]>='A' && s[p]<='Z')
        {
            string t;
            t="";
            for(;s[p]!=',';++p) t+=s[p];
            para[i-1]=eval(t.data(),t[0]-'A');
        }
        else while (s[p]>='0' && s[p]<='9')
        {
            para[i-1]=para[i-1]*10+s[p]-'0';
            ++p;
        }
        ++p;
    }
    if (s[p]>='A' && s[p]<='Z')
        {
            string t;
            t="";
            for(;s[p]!=')';++p) t+=s[p];
            t+=')';
            para[i-1]=eval(t.data(),t[0]-'A');
        }
        else while (s[p]>='0' && s[p]<='9')
        {
            para[i-1]=para[i-1]*10+s[p]-'0';
            ++p;
        }
    /*if (s[p+1]!='=') {cout<<s<<'\n';return 10;}
    else return 0;*/
    p=strchr(fff[f],'=')-fff[f];
    ++p;
    string t;
    t="";
    for(;fff[f][p]!='\0';++p)
    {
        if(fff[f][p]>='a' && fff[f][p]<='z') t+=fa_string(para[fff[f][p]-'a']);
        else t+=fff[f][p];
    }
    ii=0;
    strcpy(ss,t.data());
    cout<<ss<<' ';
    int gg=evalueaza();
    cout<<gg<<'\n';
    return gg;
}

int main()
{
    f>>functia;
    f>>s;
    while (s[0]>='a' && s[0]<='z')
    {
        strcpy(para[s[0]-'a'],s+2);
        f>>s;
    }
    for(i=0;functia[i]!=NULL;++i)
    {
        if (functia[i]>='a' && functia[i]<='z')
        {
            strcat(ff,para[functia[i]-'a']);
            pos=strlen(ff);
        }
        else ff[pos++]=functia[i],ff[pos]='\0';
    }
    strcpy(functia,ff);
    while (s[0]>='A' && s[0]<='Z' && f.good())
    {
        strcpy(fff[s[0]-'A'],s);
        for(i=0;s[i]!='=';++i) if (s[i]==',') ++aritate[s[0]-'A'];
        ++aritate[s[0]-'A'];
        f>>s;
    }
    cout<<eval(functia,functia[0]-'A');
    return 0;
}
