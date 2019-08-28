// P1613 跑路
// https://www.luogu.org/problem/P1613

#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;
int dis[60][60], n, m;
bool G[60][60][65];

void init() {
  memset(G, false, sizeof(G));
  memset(dis, 10, sizeof(dis));
}
void work() {
  for (int k = 1; k <= 64; k++)
    for (int i = 1; i <= n; i++)
      for (int t = 1; t <= n; t++)
        for (int j = 1; j <= n; j++)
          if (G[i][t][k - 1] && G[t][j][k - 1]) {
            G[i][j][k] = true;
            dis[i][j] = 1;
          }
}
void floyd() {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
}
int main() {
  init();
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    dis[x][y] = 1;
    G[x][y][0] = true;
  }
  work();
  floyd();
  cout << dis[1][n] << endl;
  return 0;
}