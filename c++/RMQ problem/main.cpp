#include <iostream>

using namespace std;

#define nmax 250010
#define logmax 20

double rmq[logmax][nmax];
int n,lg[logmax],m;

int main()
{
	int i,k,x,y,diff,log;
	cin>>n;
	for(i=1;i<=n;++i)
		cin>>rmq[0][i];

	for(i=2;i<=n;++i) lg[i]=1+lg[i>>1];

	for(k=1;k<=lg[n];++k)
		for(i=1;i+(1<<k)-1<=n;++i)
			rmq[k][i]=min(rmq[k-1][i],rmq[k-1][i+(1<<(k-1))]);

	cin>>m;
	for(;m;--m)
	{
		cin>>x>>y;
		++x;

		diff=y-x+1;
		log=lg[diff];

		cout<<fixed<<min(rmq[log][x],rmq[log][y-(1<<log)+1])<<'\n';
	}

    return 0;
}
