// POJ-1789 Truck History
// https://vjudge.net/problem/POJ-1789

#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 2010;  //最大点数
const int INF = 0x3f3f3f3f;
bool vis[MAXN];
int lowc[MAXN];
int cost[MAXN][MAXN];
//点是 0 n-1
int Prim(int cost[][MAXN], int n) {
  int ans = 0;
  memset(vis, false, sizeof(vis));
  vis[0] = true;
  for (int i = 1; i < n; i++) lowc[i] = cost[0][i];
  for (int i = 1; i < n; i++) {
    int minc = INF;
    int p = -1;
    for (int j = 0; j < n; j++)
      if (!vis[j] && minc > lowc[j]) {
        minc = lowc[j];
        p = j;
      }
    if (minc == INF) return -1;  //原图不连通
    ans += minc;
    vis[p] = true;
    for (int j = 0; j < n; j++) {
      if (!vis[j] && lowc[j] > cost[p][j]) lowc[j] = cost[p][j];
    }
  }
  return ans;
}
char str[MAXN][10];
int len(int a, int b) {
  int ans = 0;
  for (int i = 0; i < 7; i++) {
    if (str[a][i] != str[b][i]) {
      ans++;
    }
  }
  return ans;
}

int main() {
  int n;
  while (~scanf("%d", &n)) {
    if (n == 0) break;
    for (int i = 0; i < n; i++) {
      scanf("%s", str[i]);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        cost[i][j] = len(i, j);
      }
    }
    int ans = Prim(cost, n);
    printf("The highest possible quality is 1/%d.\n", ans);
  }
  return 0;
}

// Kruskal 超时，用 Prim !