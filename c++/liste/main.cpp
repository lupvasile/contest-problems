# include <cstring>
# include <iostream>
# include <fstream>
# include <vector>
# include <bitset>
using namespace std;

# define INF 0x3f3f3f3f
# define MAXN 50010
typedef vector< pair<int, int> > :: iterator iter;

class heap{
private:
    pair<int, int> a[MAXN];
    int sz = 0;
    # define father(x) (x >> 1)
    # define left_son(x) (x << 1)
    # define right_son(x) ((x << 1) + 1)
public:
    heap() {};

    void insert(pair<int, int> x) {
        a[sz] = x;
        int k = sz;
        sz++;

        while ((k > 0) && (a[k] < a[father(k)])) {
            swap(a[k], a[father(k)]);
            k = father(k);
        }
    }

    pair<int, int> top() {
        if (sz > 0) {
            return a[0];
        }
        return make_pair(0, 0);
    }

    void pop() {
        sz--;
        a[0] = a[sz];
        int k = 0;
        while (right_son(k) < sz && (a[k] > a[left_son(k)] || a[k] > a[right_son(k)])) {
            if (a[left_son(k)] > a[right_son(k)]) {
                swap(a[k], a[right_son(k)]);
                k = right_son(k);
            } else {
                swap(a[k] , a[left_son(k)]);
                k = left_son(k);
            }
        }
        if (left_son(k) < sz && a[k] > a[left_son(k)]) {
            swap(a[k] , a[left_son(k)]);
        }
    }

    bool empty() {
        if (sz == 0) {
            return true;
        }
        return false;
    }

    int size() {
        return sz;
    }
};

// <parsing>
FILE *fin = fopen("dijkstra.in", "r");
const int maxb = 8192;
char buf[maxb];
int ptr = maxb - 1;

int getInt() {
    while (buf[ptr] < '0' || '9' < buf[ptr]) {
        if (++ptr >= maxb) {
            fread(buf, maxb, 1, fin);
            ptr = 0;
        }
    }
    int nr = 0;
    while ('0' <= buf[ptr] && buf[ptr] <= '9') {
        nr = nr * 10 + buf[ptr] - '0';
        if (++ptr >= maxb) {
            fread(buf, maxb, 1, fin);
            ptr = 0;
        }
    }
    return nr;
}

// </parsing>
FILE *g = fopen("dijkstra.out", "w");

int n, m;
vector<pair<int, int> > G[MAXN];
int dist[MAXN];
heap coada;
bitset<MAXN> viznod;

void dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    coada.insert(make_pair(0, 1));

    while (!coada.empty()) {
        pair<int, int> nd = coada.top();
        coada.pop();

        if (viznod[nd.second] == true) {
            continue;
        }
        viznod[nd.second] = true;

        for (iter it = G[nd.second].begin(); it != G[nd.second].end(); it++) {
            if (dist[it->first] > dist[nd.second] + it->second) {
                dist[it->first] = dist[nd.second] + it->second;
                coada.insert(make_pair(dist[it->first], it->first));
            }
        }
    }
}

int main()
{
    n = getInt();
    m = getInt();
    for (int i = 1; i <= m; i++) {
        int x, y, cost;
        x = getInt();
        y = getInt();
        cost = getInt();
        G[x].push_back(make_pair(y, cost));
    }

    dijkstra();

    for (int i = 2; i <= n; i++) {
        if (dist[i] == INF) {
            fprintf(g, "0 ");
        } else {
            fprintf(g, "%d ", dist[i]);
        }
    }

    fclose(fin);
    fclose(g);
    return 0;
}
