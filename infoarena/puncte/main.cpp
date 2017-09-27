/* mircea pasoi */
#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX_N 100005
#define FIN "puncte.in"
#define FOUT "puncte.out"
#define INF 0x3f3f3f3f
#define sqr(x) ((long long) (x)*(x))
#define x first
#define y second

typedef pair<int, int> point;

int N, M, stk[MAX_N], stk_len, X[MAX_N];
point P[MAX_N]; char buf[256], *p;

// coordonata x la care b e mai bun ca a
inline int meet(point a, point b)
{
    long long x;

    if (a.x == b.x) return a.y < b.y ? INF : 0;
    x = sqr(a.x)+sqr(a.y)-sqr(b.x)-sqr(b.y);
    x = (x + 2*(a.x-b.x)-1) / (2*(a.x-b.x));
    if (x < 0) return 0;
    if (x > INF) return INF;
    return (int) x;
}

int get(void)
{
    int n;

    for (n = 0; *p >= '0' && *p <= '9'; p++)
        n = n*10 + *p-'0';
    for (; *p == ' '; p++);
    return n;
}

int main(void)
{
    int i, x;

    freopen(FIN, "r", stdin);
  //  freopen(FOUT, "w", stdout);

    scanf("%d %d\n", &N, &M);
    for (i = 0; i < N; i++)
    {
        fgets(buf, sizeof(buf), stdin); p = buf;
        P[i].x = get(); P[i].y = get();
    }

    X[0] = 0; X[1] = INF; stk[0] = 0; stk_len = 1;
    for (i = 1; i < N; i++)
    {
        while (stk_len > 0 && (x = meet(P[stk[stk_len-1]], P[i])) <= X[stk_len-1])
            stk_len--;
        stk[stk_len] = i;
        X[stk_len] = x;
        X[++stk_len] = INF;
    }

  //  fprintf(stderr, "%d\n", stk_len);

    for (; M; M--)
    {
        fgets(buf, sizeof(buf), stdin); p = buf;
        x = get();
        i = upper_bound(X, X+stk_len, x)-X-1;
        printf("%lld\n", sqr(x-P[stk[i]].x)+sqr(P[stk[i]].y));
    }

    return 0;
}
