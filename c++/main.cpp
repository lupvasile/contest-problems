#include <fstream>
#include <algorithm>
using namespace std;

ifstream fi("genetic.in");
ofstream fo("genetic.out");
int N,i,j,k;
int V[100];
int size=40;
int P[40][100];
int PP[40][100];
int nrgen=100,g;
double F[40],FF[40];
double fmid,fitmax;
int pmax;
int ind,pas,poz;
int ind1,ind2,st,dr;

int modul(int a)
{
    if (a>=0)
        return a;
    return -a;
}

double fitness(int X[],int N)
{
    int s1,s2,stot;
    int i;
    s1=s2=stot=0;
    for (i=0;i<N;i++)
    {
        if (X[i]==0)
            s1+=V[i];
        else
            s2+=V[i];
        stot+=V[i];
    }
    return 1-(double)modul(s1-s2)/stot;
}
int main()
{
    fi>>N;
    for (i=0;i<N;i++)
        fi>>V[i];
    // se construieste populatia initiala
    for (i=0;i<size;i++)
        for (j=0;j<N;j++)
            P[i][j]=rand()%2;
    for (g=1;g<=nrgen;g++)
    {
        // se calculeaza fitness-ul pentru fiecare individ
        for (i=0;i<size;i++)
            F[i]=FF[i]=fitness(P[i],N);
        sort(FF,FF+N);
        fmid=FF[(size-1)>>1];
        // indivizii cu fitness mai mare sau egal ca fmid sunt depusi in PP
        k=0;
        for (ind=0;ind<size;ind++)
            if (F[ind]>=fmid)
            {
                for (i=0;i<N;i++)
                    PP[k][i]=P[ind][i];
                k++;
                if (k>=(size>>1))
                    break;
            }
        // mutatii
        for (pas=0;pas<(size>>2);pas++)
        {
            ind=rand()%(size>>1);
            for (i=0;i<N;i++)
                PP[k][i]=PP[ind][i];
            poz=rand()%N;
            PP[k][poz]=1-PP[k][poz];
            k++;
        }
        // crossover
        for (pas=0;pas<(size>>2);pas++)
        {
            ind1=rand()%(size>>1);
            ind2=rand()%(size>>1);
            st=rand()%N;
            dr=rand()%N;
            if (st>dr)
                swap(st,dr);
            for (i=0;i<N;i++)
                PP[k][i]=PP[ind1][i];
            for (i=st;i<=dr;i++)
                PP[k][i]=PP[ind2][i];
            k++;
        }
        // PP devine generatie curenta
        for (i=0;i<size;i++)
            for (j=0;j<N;j++)
                P[i][j]=PP[i][j];
    }
    fitmax=0;
    pmax=-1;
    for (i=0;i<size;i++)
    {
        F[i]=fitness(P[i],N);
        if (F[i]>fitmax)
        {
            fitmax=F[i];
            pmax=i;
        }
    }
    fo<<fitmax<<"\n";
    for (i=0;i<N;i++)
        fo<<P[pmax][i]<<" ";
    fi.close();
    fo.close();
    return 0;
}
