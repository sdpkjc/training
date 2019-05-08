// HDU-1281 棋盘游戏
// https://vjudge.net/problem/HDU-1281

#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 510;
int uN, vN;  // u,v 的数目，使用前面必须赋值
int g[MAXN][MAXN];
int linker[MAXN];
bool used[MAXN];
bool dfs(int u) {
  for (int v = 1; v <= vN; v++) {
    if (g[u][v] && !used[v]) {
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
  for (int u = 1; u <= uN; u++) {
    memset(used, false, sizeof(used));
    if (dfs(u)) res++;
  }
  return res;
}

int main() {
  int n, m, k;
  int cnt = 1;
  while (~scanf("%d%d%d", &n, &m, &k)) {
    memset(g, 0, sizeof(g));
    uN = n;
    vN = m;
    for (int i = 0; i < k; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      g[a][b] = 1;
    }

    int ans2 = hungary();
    int ans1 = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (g[i][j] == 1) {
          g[i][j] = 0;
          int tmp = hungary();
          if (tmp != ans2) {
            ans1++;
          }
          g[i][j] = 1;
        }
      }
    }
    printf("Board %d have %d important blanks for %d chessmen.\n", cnt++, ans1,
           ans2);
  }
}

// xy匹配，枚举关键点