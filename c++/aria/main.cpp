# include <cassert>
# include <cstdio>
# include <cmath>

const char *FIN = "aria.in", *FOU = "aria.out";
const int MAX = 100005;

struct punct {
    double x, y;
} vec[MAX];

int N;
double sol;

int main (void) {
    assert (freopen (FIN, "r", stdin));
 //   assert (freopen (FOU, "w", stdout));

    assert (scanf ("%d", &N) == 1);
    assert (1 <= N && N <= 100000);
    for (int i = 0; i < N; ++i) {
        assert (scanf ("%lf %lf", &vec[i].x, &vec[i].y) == 2);
        assert (-10000000 <= vec[i].x && vec[i].x <= 10000000);
        assert (-10000000 <= vec[i].y && vec[i].y <= 10000000);
    }
    vec[N] = vec[0];
    for (int i = 0; i<N; ++i)
        sol += (vec[i].x * vec[i + 1].y - vec[i + 1].x * vec[i].y);
    printf ("%lf",  (sol / 2.0));
}
