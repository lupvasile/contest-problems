#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
#include <memory.h>
using namespace std;

const char iname[] = "gaz.in";
const char oname[] = "gaz.out";

const int MAX_N = 2005;
const int INF   = 0x3f3f3f3f;

typedef long long i64;

i64 bst[MAX_N], G[MAX_N], S[MAX_N];

int main(void) {
    FILE *fi = fopen(iname, "r");
    FILE *fo = fopen(oname, "w");
    i64 L, P, D, C, N, SG = 0;

    assert(fscanf(fi, "%lld %lld %lld %lld", &L, &P, &D, &C) == 4);
    assert(1 <= L && L <= 1000);
    assert(1 <= P && P <= 5000);
    assert(1 <= D && D <= 5000);
    assert(1 <= C && C <= 5000);
    assert(fscanf(fi, "%lld", &N) == 1);
    assert(1 <= N && N <= 2000);
    for (int i = 1; i <= N; ++ i) {
        assert(fscanf(fi, "%lld", &G[i]) == 1);
        assert(1 <= G[i] && G[i] <= 1000);
        SG += G[i];
    }

    memset(bst, INF, sizeof bst);

    bst[0] = 0;
    for (int i = 1; i <= N; ++ i) {
        int count = 0, sum = G[i];
        for (int j = i - 1; j >= 0; -- j) {
            bst[i] = min(bst[i], bst[j] + count * C + P);
            sum += G[j];
            count += max(0LL, sum - G[j] - L);
        }
    }
    printf(/*fopen(oname, "w"),*/ "%lld\n", bst[N] + SG * D);
    // printf("%lld\n", bst[N] + SG * D);
    fclose(fi), fclose(fo);
    return 0;
}
