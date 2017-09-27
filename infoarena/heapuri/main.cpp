#include <iostream>
#include <fstream>

using namespace std;

ifstream f("heapuri.in");
ofstream g("heapuri.out");

//#define cout g

int nr_operatii,tip_op,x,nr_int;//nr_int numarul de elemente intrate pana acum
int heap[200010],l_heap,nod[200010];//int nod[x] in ce nod e elementul ce a intrat al x-lea
//in heap ai indicii elementelor
int v[200010];//elementele propriu-zise
void sswitch(int & a,int &b)
{
    int aux=a;
    a=b;
    b=aux;
}
void percolate(int nodd)
{
    while (v[heap[nodd]]<v[heap[nodd/2]]&& nodd/2)
    {
        sswitch(heap[nodd],heap[nodd/2]);
        nod[heap[nodd]]=nodd;
        nod[heap[nodd/2]]=nodd/2;
        nodd/=2;
    }
}
void sift(int nodd)
{
    if(v[heap[nodd]]>v[heap[nodd*2]] && nodd*2<=l_heap)
    {
        sswitch(heap[nodd],heap[nodd*2]);
        nod[heap[nodd]]=nodd;
        nod[heap[nodd*2]]=nodd*2;
        nodd*=2;
        sift(nodd);
    }
    else if (v[heap[nodd]]>v[heap[nodd*2+1]] && nodd*2+1<=l_heap)
    {
        sswitch(heap[nodd],heap[nodd*2+1]);
        nod[heap[nodd]]=nodd;
        nod[heap[nodd*2+1]]=nodd*2+1;
        nodd=nodd*2+1;
        sift(nodd);
    }

}
bool check(int nodd)
{
    bool ok=true;
    if (nodd*2<=l_heap) if (v[heap[nodd]]>v[heap[nodd*2]]) return false;
        else ok=check(nodd*2);
    if(!ok) return ok;
    if (nodd*2+1<=l_heap) if (v[heap[nodd]]>v[heap[nodd*2+1]]) return false;
        else  return check(nodd*2+1);
    return true;
}
void afis_heap()
{
    for(int i=1; i<=l_heap; ++i)
                {
                    cout<<v[heap[i]]<<' ';
                    if((i&(i+1))==0) cout<<'\n';
                }
                cout<<"\n************\n";
}
int main()
{
    f>>nr_operatii;
    for(; nr_operatii; --nr_operatii)
    {
        f>>tip_op;
        if(tip_op>2)
            cout<<v[heap[1]]<<'\n';
        else
        {
            f>>x;
            if(tip_op==1)
            {
                v[++nr_int]=x;
                heap[++l_heap]=nr_int;
                nod[nr_int]=l_heap;
                percolate(l_heap);
            }
            else
            {
                if(x==27) afis_heap();

                heap[nod[x]]=heap[l_heap--];
                nod[heap[nod[x]]]=nod[x];
                percolate(nod[x]);
                if(x==27) afis_heap();
                sift(nod[x]);

               if(x==27) afis_heap();
            }
        }
        if(!check(1))
            cout<<"ASdfasdf"<<'\n';
    }

    return 0;
}
