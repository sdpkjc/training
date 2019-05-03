// POJ-1797 Heavy Transportation
// https://vjudge.net/problem/POJ-1797

#include <string.h>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 1010;
#define typec int
const typec INF = 0x3f3f3f3f;

int xcost[MAXN][MAXN];
int dist[MAXN];
bool vis[MAXN];
void Dijkstra(typec cost[][MAXN], typec lowcost[], int n, int beg) {
  for (int i = 0; i < n; i++) {
    lowcost[i] = 0;
    vis[i] = false;
  }
  lowcost[beg] = INF;
  for (int j = 0; j < n; j++) {
    int k = -1;
    int Min = 0;
    for (int i = 0; i < n; i++) {
      if (!vis[i] && lowcost[i] > Min) {
        Min = lowcost[i];
        k = i;
      }
    }
    if (k == -1) break;
    vis[k] = true;
    for (int i = 0; i < n; i++) {
      if (!vis[i] && min(lowcost[k], cost[k][i]) > lowcost[i]) {
        lowcost[i] = min(lowcost[k], cost[k][i]);
      }
    }
  }
}

int main() {
  int T, CNT = 1;
  scanf("%d", &T);
  while (CNT <= T) {
    memset(xcost, 0, sizeof(xcost));
    memset(dist, 0, sizeof(dist));

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
      int a, b, w;
      scanf("%d%d%d", &a, &b, &w);
      a--;
      b--;
      xcost[a][b] = xcost[b][a] = max(w, xcost[a][b]);
    }
    Dijkstra(xcost, dist, n, 0);
    printf("Scenario #%d:\n%d\n\n", CNT++, dist[n - 1]);
  }
  return 0;
}

//求 1 - n 中所有路径中最大边权的最小值