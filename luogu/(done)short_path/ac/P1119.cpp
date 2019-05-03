// P1119 灾后重建
// https://www.luogu.org/problemnew/show/P1119

#include <string.h>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 405;
int ti[MAXN];
int dist[MAXN][MAXN];
void floyd(int n, int now) {
  for (int k = 0; k < n; k++) {
    if (ti[k] == now) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[j][k]);
        }
      }
    }
  }
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  memset(dist, 0x3f, sizeof(dist));
  for (int i = 0; i < n; i++) {
    scanf("%d", &ti[i]);
    dist[i][i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    dist[a][b] = c;
    dist[b][a] = c;
  }

  int q;
  scanf("%d", &q);
  int now = 0;
  for (int i = 0; i < q; i++) {
    int x, y, t;
    scanf("%d%d%d", &x, &y, &t);
    for (; now <= t; now++) {
      floyd(n, now);
    }
    int ans = dist[x][y];

    if (ans != 0x3f3f3f3f && ti[x] <= t && ti[y] <= t) {
      printf("%d\n", ans);
    } else {
      printf("-1\n");
    }
  }

  return 0;
}

// Floyd 好题
// 在去学学 Floyd
// https://www.cnblogs.com/GumpYan/p/5540549.html