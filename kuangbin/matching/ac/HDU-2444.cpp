// HDU-2444 The Accomodation of Students
// https://vjudge.net/problem/HDU-2444#author=634579757

#include <string.h>
#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 2005;
vector<int> G[MAXN];
bool vis[MAXN] = {0};
int col[MAXN] = {0};
bool dfs(int node, int color) {
  if (vis[node]) {
    if (col[node] == color)
      return true;
    else
      return false;
  }
  vis[node] = true;
  col[node] = color;
  bool re = true;
  for (int i = 0; i < G[node].size() && re; i++) {
    re = re && dfs(G[node][i], 1 - color);
  }
  return re;
}
void addedge(int u, int v) { G[u].push_back(v); }
int linker[MAXN];
bool used[MAXN];
int uN;
bool dfs(int u) {
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (!used[v]) {
      used[v] = true;
      if (linker[v] == -1 || dfs(linker[v])) {
        linker[v] = u;
        return true;
      }
    }
  }
  return false;
}
int hungary() {
  int res = 0;
  memset(linker, -1, sizeof(linker));
  //点的编号 0∼uN-1
  for (int u = 1; u <= uN; u++) {
    memset(used, false, sizeof(used));
    if (dfs(u)) res++;
  }
  return res;
}
void init() {
  memset(vis, 0, sizeof(vis));
  memset(col, 0, sizeof(col));
  for (int i = 0; i < MAXN; i++) {
    G[i].clear();
  }
}
int main() {
  int n, m;
  while (~scanf("%d%d", &n, &m)) {
    init();
    uN = n;
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      addedge(a, b);
      addedge(b, a);
    }
    int re = true;
    for (int i = 1; i <= n; i++) {
      if (vis[i]) continue;
      if (!dfs(i, 0)) {
        re = false;
        break;
      }
    }
    if (re) {
      int ans = hungary() / 2;
      printf("%d", ans);
    } else {
      printf("No");
    }
    printf("\n");
  }

  return 0;
}

// 图黑白染色 + 二分图匹配，匈牙利或者跑最大流都可以