/*
 * Autor: Tiberiu Savin
 * Complexitate: O(N^2 * M)
 */
#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

#define NMAX 600
#define INF 0x3f3f3f3f

int N, M, K;
int F[NMAX][NMAX];
int C[NMAX][NMAX];
int d[NMAX];
int viz[NMAX];
int TT[NMAX];
vector<pair<int, int> > G[NMAX];
int sol;
int source, dest;
int cd[NMAX];
int cd2[NMAX];

int BF() {
  memset(d, 0, sizeof(d));
  memset(viz, 0, sizeof(viz));
  for (int i = 1; i <= N + M + 1; i++) {
    d[i] = INF;
    TT[i] = INF;
  }
  d[0] = 0;
  cd[0] = 1;
  cd[1] = 0;
  cd2[0] = 0;

  while (true) {
    for (int i = 1; i <= cd[0]; i++) {
      int nod = cd[i];
      memset(viz, 0, sizeof(viz));
      for (int j = 0; j < G[nod].size(); j++) {
        int vecin = G[nod][j].first;
        int cost = G[nod][j].second;

        if (C[nod][vecin] > F[nod][vecin] && d[vecin] > d[nod] + cost) {
          d[vecin] = d[nod] + cost;
          TT[vecin] = nod;
          if (!viz[nod]) {
            cd2[0]++;
            cd2[cd2[0]] = vecin;
            viz[vecin] = 1;
          }
        }
      }
    }

    if (cd2[0] == 0) {
      break;
    }

    for (int i = 0; i <= cd2[0]; i++) {
      cd[i] = cd2[i];
    }

    cd2[0] = 0;
  }

  return d[dest];
}

int max_flow(int limit) {
  int cst = 0, c = 0, ret = 0;
  memset(F, 0, sizeof(F));
  while (true) {
    c = BF();
    if (limit == 0 && c == INF) {
      break;
    }

    cst = cst + c;
    if (cst < ret) {
      ret = cst;
    }

    int nod = dest;
    while (nod != source) {
      F[TT[nod]][nod]++;
      F[nod][TT[nod]]--;
      nod = TT[nod];
    }

    if (cst == limit && limit != 0) {
      break;
    }
  }

  return ret;
}

int main() {
  freopen("terenuri3d.in", "r", stdin);
  //freopen("terenuri3d.out", "w", stdout);

  scanf("%d %d %d ", &N, &M, &K);
  source = 0;
  dest = N + M + 1;

  for (int i = 1; i <= K; i++) {
    int x, y, z;
    scanf("%d %d %d ", &x, &y, &z);
    y += N;
    C[x][y] = 1;
    G[x].push_back(make_pair(y, -z));
    G[y].push_back(make_pair(x, z));
  }

  for (int i = 1; i <= N; i++) {
    C[source][i] = 1;
    G[source].push_back(make_pair(i, 0));
    G[i].push_back(make_pair(source, 0));
  }

  for (int i = 1; i <= M; i++) {
    C[N + i][dest] = 1;
    G[dest].push_back(make_pair(N + i, 0));
    G[N + i].push_back(make_pair(dest, 0));
  }

  int cst = 0;
  cst = max_flow(0);
  printf("%d\n", -cst);

  cst = max_flow(cst);

  int cnt = 0;
  for (int i = 1; i <= N; i++) {
    cnt = cnt + F[0][i];
  }

  printf("%d\n", cnt);
  for (int i = 1; i <= N; i++) {
    for (int j = N; j <= N + M; j++) {
      if (F[i][j] == 1) {
        printf("%d %d\n", i, j - N);
      }
    }
  }

  return 0;
}
