// P1522 牛的旅行 Cow Tours
// https://www.luogu.org/problem/P1522

#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int MAXN = 205;
const int INF = 0x3f3f3f3f;
double dist[MAXN][MAXN];
void floyd(int n) {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[j][k]);
      }
    }
  }
}
double xx[MAXN];
double yy[MAXN];

double len(int a, int b) {
  return sqrt((xx[a] - xx[b]) * (xx[a] - xx[b]) +
              (yy[a] - yy[b]) * (yy[a] - yy[b]));
}

double len1[MAXN];
int main() {
  int N;
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%lf%lf", &xx[i], &yy[i]);
    dist[i][i] = 0;
    len1[i] = 0;
    for (int j = 1; j <= N; j++) {
      if (i != j) dist[i][j] = INF;
    }
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      char c;
      scanf(" %c", &c);
      if (c == '1') {
        dist[i][j] = len(i, j);
      }
    }
  }

  floyd(N);
  double l1 = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (dist[i][j] != INF) {
        len1[i] = max(len1[i], dist[i][j]);
      }
    }
    l1 = max(l1, len1[i]);
  }

  double l2 = INF;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      //   printf("%lf\n", dist[i][j]);
      if (dist[i][j] == INF) {
        l2 = min(len1[i] + len(i, j) + len1[j], l2);
      }
    }
  }
  double ans = max(l1, l2);
  printf("%.6f\n", ans);
}