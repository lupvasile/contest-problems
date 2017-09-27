#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

ifstream f("ed.in");
ofstream g("ed.out");

#define cout g

char s[50010];
int n,i,nr;
struct elem
    {
    char c;
    elem *prev,*next;
    };
elem *start,*finish,*p,*p2,*p3;

void aaa()
{
    for(elem *p=start->next;p!=finish;p=p->next)
            cout<<p->c;
        cout<<'\n';
}

int main()
    {
    f>>s;
    start=new elem;
    finish=new elem;
    p=start;
    for(i=0; s[i]; ++i)
        {
        p->next=new elem;
        p->next->prev=p;
        p=p->next;
        p->c=s[i];
        }
    p->next=finish;
    finish->prev=p;
    p=finish;
    f>>n;
    for(; n; --n)
        {
        f>>s;
        switch(s[0])
            {
            case 'L':
                if(p!=start->next) p=p->prev;
                break;
            case 'R':
                if(p!=finish) p=p->next;
                break;
            case 'B':
                {
                    if(p!=start->next)
                    {
                        p2=p->prev->prev;
                        p2->next=p;
                        p->prev=p2;
                    }
                    break;
                }
            case 'I':
                {
                p2=p;
                p=p->prev;
                p3=p;
                for(i=1; s[i]; ++i)
                    {
                    p->next=new elem;
                    p->next->prev=p;
                    p=p->next;
                    p->c=s[i];
                    }
                p->next=p2;
                p2->prev=p;
                p=p3->next;
                break;
                }
            case 'D':
                {
                nr=atoi(s+1);
                p2=p->prev;
                for(i=1;i<=nr && p!=finish;++i) p=p->next;
                p2->next=p;
                p->prev=p2;
                break;
                }
            }
        }
    aaa();
    return 0;
    }
