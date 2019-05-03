// POJ-3660 Cow Contest
// https://vjudge.net/problem/POJ-3660

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAXN = 105;
int dist[MAXN][MAXN];

void floyd(int n) {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = (dist[i][j] || (dist[i][k] && dist[k][j]));
      }
    }
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  memset(dist, 0, sizeof(dist));
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    dist[a][b] = 1;
  }
  floyd(n);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      if (dist[i][j] || dist[j][i]) cnt++;
    }
    if (cnt >= n - 1) {
      ans++;
    }
  }
  printf("%d\n", ans);

  return 0;
}

// 传递闭包