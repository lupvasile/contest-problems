#include <bits/stdc++.h>
using namespace std;

#define nmax 200010

int v[nmax],cnt[1000010],SIZE;
long long ans[nmax];
long long res;
struct s_q
{
	int x,y,ind,buc;
	void read(int i)
	{
		scanf("%d%d",&x,&y);
		--x;
		--y;
		ind=i;
		buc=x/SIZE;
	}

	bool operator < (const s_q &o) const
	{
		if(buc==o.buc) return y<o.y;
		return buc<o.buc;
	}
} q[nmax];

void add(int pos)
{
res+=1ll*v[pos]*(cnt[v[pos]]<<1|1);
++cnt[v[pos]];
}

void remove(int pos)
{
--cnt[v[pos]];
res-=1ll*v[pos]*(cnt[v[pos]]<<1|1);
}

int main()
{
	int i,n,m,L(0),R(-1);
	scanf("%d%d",&n,&m);

	for(SIZE=1;SIZE*SIZE<=n;++SIZE);
	--SIZE;

	for(i=0;i<n;++i) scanf("%d",&v[i]);

	for(i=0;i<m;++i) q[i].read(i);

	sort(q,q+m);

	for(i=0;i<m;++i)
	{
		while(L<q[i].x) {
			remove(L);
			++L;
		}
		while(L>q[i].x)
		{
			--L;
			add(L);
		}

		while(R<q[i].y)
		{
			++R;
			add(R);
		}
		while(R>q[i].y)
		{
			remove(R);
			--R;
		}

		ans[q[i].ind]=res;
	}

    for(i=0;i<m;++i) printf("%I64d\n",ans[i]);
	return 0;

}
