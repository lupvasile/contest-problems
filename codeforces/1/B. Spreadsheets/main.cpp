#include <iostream>

using namespace std;

char s[2000];
long long n,pw,i,row,col;
int x;

bool R23C55(char s[])
{
    int i=0;
    while(!isdigit(s[i])) ++i;
    while(isdigit(s[i])) ++i;
    if(s[i]!='\0') return true;
    return false;
}

int main()
{
    cin>>n;
    for(;n;--n)
    {
        cin>>s;
        if(R23C55(s))
        {
            for(row=0,i=1;isdigit(s[i]);++i) row=row*10+s[i]-'0';
            for(col=0,++i;isdigit(s[i]);++i) col=col*10+s[i]-'0';

            for(pw=26;pw<col;pw*=26);
            --col;
            for(pw/=26;pw;pw/=26)
            {
                cout<<(char)('A'+col/pw-1);

            }
            cout<<row<<'\n';
        }
        else
        {
            for(i=0;!isdigit(s[i]);++i);
            pw=1;
            col=0;
            for(--i;i>=0;pw*=26,--i) col+=pw*(s[i]-'A'+1);

            for(i=0;!isdigit(s[i]);++i);
            cout<<"R"<<s+i<<"C"<<col<<'\n';
        }
    }
    return 0;
}
