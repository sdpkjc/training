// HDU-2819 Swap
// https://vjudge.net/problem/HDU-2819

#include <string.h>
#include <cstdio>
#include <vector>
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
  while (~scanf("%d", &uN)) {
    vN = uN;
    memset(g, 0, sizeof(g));
    for (int i = 1; i <= uN; i++) {
      for (int j = 1; j <= uN; j++) {
        scanf("%d", &g[i][j]);
      }
    }
    if (uN > hungary()) {
      printf("-1\n");
    } else {
      vector<int> a;
      vector<int> b;

      for (int i = 1; i <= uN; i++) {
        if (i != linker[i]) {
          for (int j = 1; j <= vN; j++) {
            if (i == linker[j]) {
              a.push_back(i);
              b.push_back(j);
              int t = linker[j];
              linker[j] = linker[i];
              linker[i] = t;
            }
          }
        }
      }
      printf("%d\n", (int)a.size());
      for (int i = 0; i < a.size(); i++) {
        printf("C %d %d\n", a[i], b[i]);
      }
    }
  }
  return 0;
}

// 相当于输出匹配，特判，两种方案，C