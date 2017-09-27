#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int i,nr,start,n,m,j;
double pos,px,py,sx,sy,nx,ny;
string s;
#define val(x) ((x-1)*10)
struct eee{int x,y;
bool operator!=(eee asdf) const
{
    return asdf.x!=x || asdf.y!=y;
    }
} v[10000][10000];
eee DOWN={-10,-10},ORG={300,300};
double angle=0.2;

int TARGETX=400;
int TARGETY=200;

void print()
{
    int i,j;
    cout << "MOVE ";
    for (int i = 1; i <= n; i++)
        for(j=1;j<=m;++j)
    {
        if (v[i][j] != DOWN)
            cout << i << ' ' << j<<' '<<v[i][j].x<<' '<<v[i][j].y<< ' ';

    }
    cout <<endl;
    cin >> s;
    cerr<<s<<'\n';
    if(s!="ERROR") return;
        cin >> s;
    cerr<<s<<'\n';
    getline(cin,s);
    cerr<<s<<'\n';
}
int dist(int x,int y,int a,int b)
{
    x=(x-1)*10;
    y=(y-1)*10;
    return max(abs(x-a),abs(y-b))-70;

    if (abs(x - a) < 10 && abs(y - a) < 10)
        return 1;
    return 0;
}

void mmove(int x,int y,int par)
{

    int i,j;
    for(i=1;i<=n;++i)
    for(j=1;j<=m;++j)
    if((i+j)%2==par && dist(i,j,px,py)<=60) v[i][j]={0,0};
    else v[i][j]=DOWN;

    print();

    for(i=1;i<=n;++i)
    for(j=1;j<=m;++j)
    if((i+j)%2==par && dist(i,j,px,py)<=60) v[i][j]={x,y};

    print();

}

void rrotate(int x,int y,int par)
{
    int i,j;
    cout << "GET_POSITION " << endl;
        cin >> px >> py;
    cerr<<px<<' '<<py;
    for(i=1;i<=n;++i)
    for(j=1;j<=m;++j)
    if( (i+j)%2==par && dist(i,j,px,py)<=60) v[i][j]={0,0};
    else v[i][j]=DOWN;

  print();

     for(i=1;i<=n;++i)
    for(j=1;j<=m;++j)
     if( (i+j)%2==par && dist(i,j,px,py)<=60)
     {
         if(val(i)<px && val(j)<py) v[i][j]={5,-5};
         if(val(i)>px && val(j)<py) v[i][j]={5,5};
         if(val(i)>px && val(j)>py) v[i][j]={-5,5};
         if(val(i)<px && val(j)>py) v[i][j]={-5,-5};

     }

    print();
}

void goto_pos(int x, int y)
{


    TARGETX = x;
    TARGETY = y;
int movex,movey;

    cout << "GET_POSITION " << endl;
        cin >> px >> py;


    if (px < TARGETX) movex = 1;
    else movex = -1;
    while (true)
    {

        cout << "GET_POSITION " << endl;
        cin >> px >> py;

        cerr<<px<<' '<<py<<'\n';

        if(movex<0 && px<=TARGETX)  break;
        if(movex>0 && px>=TARGETX)  break;
         mmove(movex,0,start);



        start^=1;

    }

    if (py < TARGETY) movey = 1;
    else movey = -1;
    while (true)
    {

        cout << "GET_POSITION " << endl;
        double x, y;
        cin >> px >> py;

        if(movey<0 && py<=TARGETY)  break;
        if(movey>0 && py>=TARGETY)  break;

        mmove(0,movey,start);

        start^=1;

    }
}

int main()
{
    cout << "GET_NUMBER" << endl;
    cin >>n>>m;
    for(i=1;i<=n;++i) for(j=1;j<=m;++j) v[i][j]=DOWN;
    start=0;


   goto_pos(120,150);

   for(i=1;i<=80;++i)
   {
    rrotate(0,0,i%2);
   }

    goto_pos(130,75);

    cout << "EXIT" << endl;

    return 0;
}
