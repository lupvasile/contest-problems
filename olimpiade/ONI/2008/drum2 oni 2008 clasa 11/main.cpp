//bilute 100p
//autor: login
# include <iostream>
# include <fstream>
# include <queue>
# include <vector>
# include <algorithm>
# include <iomanip>
# include <cassert>
# define DIM 100003
# define fs first
# define sc second
# define mp make_pair
# define pb push_back
using namespace std;
int n, m, pb, v[DIM], a[4*DIM], p[DIM], down[DIM], up[DIM], r[DIM];
vector< pair<int,pair<int,int> > >Q;
priority_queue< pair<int,int> >T;

void read ()
{
	ifstream fin ("apm.in");
	fin>>n>>m>>pb;

	assert(n>0 && n<=100000);
	assert(m>0 && m<=100000);
	assert(pb>0 && pb<=n);

	for(int i=1;i<=n;++i)
	{
		fin>>v[i];

		assert(v[i]>0 && v[i]<200000);
	}
	for(int i=1;i<=m;++i)
	{
		int b, t;
		fin>>b>>t;

		assert(b>0 && b<=n);
		assert(t>0 && t<200000);

		Q.pb(mp(t, mp(b, i)));
	}
}

void upd(int k, int st, int dr, int p, int v)
{
	if (st==dr)
	{
		a[k]=v;
		return;
	}

	int mij = (st+dr)/2;
	if (p<=mij)
		upd(2*k, st, mij, p, v);
	else
		upd(2*k+1, mij+1, dr, p, v);

	a[k]=a[2*k]+a[2*k+1];
}

int querySum(int k, int st, int dr, int i, int j)
{
	if (st==dr)
		return a[k];

	int mij=(st+dr)/2, x=0, y=0;
	if (i<=mij)x = querySum(2*k, st, mij, i, j);
	if (j>mij)y = querySum(2*k+1, mij+1, dr, i, j);

	return x+y;
}

int queryPoz(int k, int st, int dr, int s)
{
	if (st==dr)
	{
		if (a[k])
			return st;
		return 0;
	}

	int mij=(st+dr)/2;

	if (a[2*k]<s)return queryPoz(2*k+1, mij+1, dr, s-a[2*k]);
	return queryPoz(2*k, st, mij, s);
}

void solve ()
{
	sort(Q.begin(),Q.end());
	for(int i=1;i<=n;++i)
	{
		upd(1, 1, n, i, 1);
		p[i]=1;
	}

	T.push(mp(0, pb));
	p[pb]=0;
	upd(1, 1, n, pb, 0);

	int q = 0, t, k, sp, bst, bdr;
	while(q<m)
	{
		t = -T.top().fs;

		while(q<m && Q[q].fs<t)
		{
			r[Q[q].sc.sc] = p[Q[q].sc.fs];
			++q;
		}

		while(T.size() && -T.top().fs == t)
		{
			k = T.top().sc;
			T.pop();

			sp = querySum(1, 1, n, 1, k);
			bst = queryPoz(1, 1, n, sp);
			bdr = queryPoz(1, 1, n, sp+1);

			if(bst)
			{
				up[++up[0]]=bst;
				p[bst] = 0;
				upd(1, 1, n, bst, 0);
			}
			if (bdr)
			{
				up[++up[0]]=bdr;
				p[bdr] = 0;
				upd(1, 1, n, bdr, 0);
			}
			down[++down[0]] = k;
		}

		while(down[0])
		{
			upd(1, 1, n, down[down[0]], 1);
			p[down[down[0]]]=1; // 1 = pamant
			--down[0];
		}

		while(up[0])
		{
			T.push(mp(-t-v[up[up[0]]], up[up[0]]));
			--up[0];
		}
		cerr<<t<<' ';
	}
}

int main()
{
	read();
	solve();

	freopen("bilute.out", "w", stdout);
	for(int i=1;i<=m;++i)
		printf("%d\n", r[i]);

	return 0;
}
