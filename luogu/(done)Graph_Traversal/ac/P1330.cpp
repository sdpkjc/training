// P1330-封锁阳光大学
// https://www.luogu.org/problemnew/show/P1330

#include <string.h>
#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 200005;
vector<int> G[MAXN];
bool vis[MAXN] = {0};
int col[MAXN] = {0};
int sum[2];
bool dfs(int node, int color) {
  if (vis[node]) {
    if (col[node] == color)
      return true;
    else
      return false;
  }
  vis[node] = true;
  col[node] = color;
  sum[color]++;
  bool re = true;
  for (int i = 0; i < G[node].size() && re; i++) {
    re = re && dfs(G[node][i], 1 - color);
  }
  return re;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    if (!dfs(i, 0)) {
      printf("Impossible");
      return 0;
    }
    ans += min(sum[0], sum[1]);
    sum[0] = sum[1] = 0;
  }
  printf("%d", ans);
  printf("\n");

  return 0;
}

// 图黑白染色