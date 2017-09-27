#include <bits/stdc++.h>

using namespace std;

#ifdef INFOARENA
#define cout fout
#endif // INFOARENA

ifstream fin("text5.in");
ofstream fout("text5.out");

#define nmax 1000010
#define inf 0x3f3f3f3f
int n,ap[1000],st,dp[2][nmax],res[nmax],nnext[nmax];
char v[nmax];
pair<int,int> stiva[nmax];

int get_nr(int pos,int step)
{
	int n=0;
	for(;step;--step,++pos) n=n*10+v[pos];
	return n;
}

void make_dp(int start,int step)
{
	int i,n;
	for(i=0;i<1000;++i) ap[i]=0;
    st=0;
	for(i=start;i>0;i-=step)
	{
		n=get_nr(i,step);
		if(!ap[n]) ap[n]=i;
		dp[step-2][i]=ap[n]+step;
		while(st && stiva[st].first<dp[step-2][i])
		{
			dp[step-2][i]=max(dp[step-2][i],stiva[st].second);
			--st;
		}
		stiva[++st]={i,dp[step-2][i]};
	}
}

int main()
{
	int i;
	fin>>n;
	fin>>v+1;

	for(i=1;i<=n;++i) v[i]-='0';

	make_dp(n-1,2);
	make_dp(n-2,2);
	make_dp(n-2,3);
	make_dp(n-3,3);
	make_dp(n-4,3);



	res[n]=-inf;res[n-1]=1;res[n-2]=1;res[0]=-inf;

	for(i=n-3;i>0;--i)
				if(res[dp[0][i]]<res[dp[1][i]])
				{
					res[i]=res[dp[1][i]]+1;
					nnext[i]=dp[1][i];
				}
				else
				{
					res[i]=res[dp[0][i]]+1;
					nnext[i]=dp[0][i];
				}


	cout<<res[1]<<'\n';

	for(i=1;i<n && i;i=nnext[i])
	{
	    cout<<i<<' ';
	    if(res[dp[0][i]]<res[dp[1][i]]) cout<<"3\n";
	    else cout<<"2\n";
	}

    //for(i=1;i<=n;++i)
      //  cout<<i<<' '<<dp[0][i]<<'\n';
    return 0;
}
