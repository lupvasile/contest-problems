#include <iostream>
#include <thread>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <tr1/unordered_map>
using namespace std;
using namespace tr1;

ifstream fin("date.in");
ofstream fout("date.out");
int t;
#define cout fout
#define MAX 20

class clasa
{
private:

    int n;
    int a[MAX][MAX];
    int s[MAX];
    unordered_map<int, vector<int> > M;
    vector <int> ok;
    vector<int> v;
    int to_int(vector<int> v)
    {
        int nr = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            nr = nr * 3 + v[i];
        }
        return nr;
    }

    vector<int> calc(vector<int> ok, int t)
    {
        int h = to_int(ok);
        if(M[h].size())
            return M[h];
        int i, j, k;
        int s1 = 1;
        for(i = 1 ; i <= n && ok[i] != 1 ; i++)
        {}
        if(i == n + 1)
        {
            for(i = 1 ; i <= n ; i++)
                ok[i] = min(ok[i], 1);
            return calc(ok, t + 1);
        }
        vector <int> v(n + 3);
        for(j = 1 ; j <= n ; j++)
        {
            v[j] = 1000;
        }

        for(j = i + 1 ; j <= n ; j++)
        {
            if(ok[j] == 1)
            {
                s1++;
                if(a[i][j] == 1)
                {
                    ok[i] = 2;
                    ok[j] = 0;
                    v[j] = min(v[j], (n >> t) + 1);
                }
                else
                {
                    ok[i] = 0;
                    ok[j] = 2;
                    v[i] = min(v[i], (n >> t) + 1);
                }
                vector <int> v2 = calc(ok, t);
                ok[i] = ok[j] = 1;
                for(k = 1 ; k <= n ; k++)
                    if(v2[k] < v[k])
                        v[k] = v2[k];
            }
        }
        if(s1 == 1)
            v[i] = 1;
        return M[to_int(ok)] = v;
    }
public:
    void initialize()
    {
        int i,j;
        ok.resize(20);
        fin >> n;
        M.clear();
        for(i = 1 ; i <= n ; i++)
        {
            for(j = 1 ; j <= n ; j++)
            {
                if(j == 1)
                {
                    s[j] = 0;
                }
                fin >> a[i][j];
                s[j] += a[i][j];
            }
        }

        for(i = 1 ; i <= n ; i++)
        {
            ok[i] = 1;
        }
    }
    void bback(int k)
    {
        v = calc(ok, 1);
    }

    void afis()
    {
        int i;
        for(i = 1 ; i <= n ; i++)
        {
            cout << v[i] << " ";
            if(s[i] == 0)
                cout << "1\n";
            else
                cout << n / 2 + 1 << "\n";
        }
    }

} th[300];



thread luna[260];

int main()
{
    int i,j,k;

    fin>>t;

    for(i=1; i<=t; ++i) th[i].initialize();

    for(i=1; i<=t; ++i)
        luna[i]=thread (&clasa::bback,&th[i],1);
    for(i=1; i<=t; ++i)
        if(luna[i].joinable())
        {
            luna[i].join();
            cout<<"Case #"<<i<<":\n";
            th[i].afis();
        }
    cout.flush();
    return 0;
}
