#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

ifstream f("antenna.in");
ofstream g("");

struct punct
{
    double x,y;
};
typedef pair <double,double> type_event;

punct p[510];
struct {double x,y;} p_sol;
double n,k,i;
vector <type_event> sweep;
vector <type_event>::iterator it;
double pi=acos(-1.0),r_sol;
bool check(double r)
{
    double mare,mic,dist;
    double diff_x,diff_y;

    for(int i=1; i<=n; ++i)
    {
        sweep.clear();
        for(int j=1; j<=n; ++j)
        {
            if(j==i) continue;

            diff_x=p[j].x-p[i].x;
            diff_y=p[j].y-p[i].x;

            dist=sqrt(diff_x*diff_x + diff_y*diff_y);
            if(dist>2*r) continue;

            mare=atan2(diff_y,diff_x);//mare ii unghiu j-i-paralela la ox
            mic=acos(dist/(2*r)); //mic ii unghiu j-i-centru

            sweep.push_back(type_event(mare-mic,1));
            sweep.push_back(type_event(mare+mic,-1));
            sweep.push_back(type_event(mare-mic+2*pi,1));
            sweep.push_back(type_event(mare+mic+2*pi,-1));
        }

        sort(sweep.begin(),sweep.end());

        double nr=1;
        for(it=sweep.begin(); it!=sweep.end(); ++it)
        {
            nr+=it ->second;
            if(nr>=k)
            {
                r_sol=r;
                p_sol.x=p[i].x+r*cos(it->first);
                p_sol.y=p[i].y+r*sin(it->first);
                return true;
            }
        }

    }
    return false;
}

int main()
{
    f>>n>>k;
    for(int i=1; i<=n; ++i) f>>p[i].x>>p[i].y;
    double hi=20000,lo=0,r;
    for(int it=1; it<=30; ++it)
    {
        r=(hi+lo)/2;
        if(check(r)) hi=r;
        else lo=r;
    }
    cout<<k;
    cout<<"\n";
    cout<<fixed<<r_sol<<"\n"<<p_sol.x<<" "<<p_sol.y;
    return 0;
}
/*
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

struct point { double x, y; };
typedef pair<double,int> par;

int n, k;
point p[5000];

double solution_r;
point solution;

const double pi = acos( -1.0 );

vector<par> sweep;
int check( double r ) {
   for( int i = 0; i < n; ++i ) {

      sweep.clear();
      for( int j = 0; j < n; ++j ) {
         if( i == j ) continue;

         double dx = p[j].x-p[i].x;
         double dy = p[j].y-p[i].y;
         double a = sqrt( dx*dx + dy*dy );
         if( a > 2*r ) continue;

         double alfa = atan2( dy, dx );
         double beta = acos( a/(2*r) );

         sweep.push_back( par( alfa-beta, +1) );
         sweep.push_back( par( alfa+beta, -1) );
         sweep.push_back( par( alfa-beta+2*pi, +1) );
         sweep.push_back( par( alfa+beta+2*pi, -1) );
      }
      sort( sweep.begin(), sweep.end() );

      int cnt = 1;
      for( vector<par>::iterator it = sweep.begin(); it != sweep.end(); ++it ) {
         cnt += it->second;
         if( cnt >= k ) {
            solution_r = r;
            solution.x = p[i].x + r*cos(it->first);
            solution.y = p[i].y + r*sin(it->first);
            return 1;
         }
      }
   }
   return 0;
}
FILE *f;
int main( void ) {
    f=freopen("antenna.in","r",stdin);
   scanf( "%d%d", &n, &k );
   for( int i = 0; i < n; ++i ) scanf( "%lf%lf", &p[i].x, &p[i].y );

   double lo = 0, hi = 20000;
   for( int iter = 0; iter < 30; ++iter ) {
      double r = (lo+hi)/2;
      if( check( r ) ) hi = r; else lo = r;
   }

   printf( "%.4lf\n%.4lf %.4lf\n", solution_r, solution.x, solution.y );

   return 0;
}*/
