#include <iostream>
#include <fstream>
using namespace std;

ofstream fout("date.out");

#define maxx 100000

long long a,b,c,k;

void solve()
{
	long long st(0),dr(maxx),mid;

	while(st<=dr)
	{
		mid=st+(dr-st)/2;
		if(a*mid*mid+b*mid+c>=k) dr=mid-1;
		else st=mid+1;
	}

	cout<<st<<'\n';

}

int main()
{
	int t;
	cin>>t;
	for(;t;--t)
	{
		cin>>a>>b>>c>>k;
		solve();
	}
    return 0;
}
