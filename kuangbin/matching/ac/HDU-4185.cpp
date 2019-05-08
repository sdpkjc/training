// HDU-4185 Oil Skimming
// https://vjudge.net/problem/HDU-4185

#include <string.h>
#include <cmath>
#include <cstdio>
using namespace std;

const int MAXN = 5010;     //点数的最大值
const int MAXM = 1000010;  //边数的最大值
struct Edge {
  int to, next;
} edge[MAXM];
int head[MAXN], tot;
void init() {
  tot = 0;
  memset(head, -1, sizeof(head));
}
void addedge(int u, int v) {
  edge[tot].to = v;
  edge[tot].next = head[u];
  head[u] = tot++;
}
int linker[MAXN];
bool used[MAXN];
int uN;
bool dfs(int u) {
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].to;
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
char mapx[MAXN][MAXN];

int dirx[] = {0, 0, 1, -1};
int diry[] = {1, -1, 0, 0};

int main() {
  int T;
  scanf("%d", &T);
  for (int ca = 1; ca <= T; ca++) {
    init();
    memset(mapx, 0, sizeof(mapx));
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        scanf(" %c", &mapx[i][j]);
      }
    }
    uN = (n + 1) * (n + 1);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (mapx[i][j] == '#')
          for (int k = 0; k < 4; k++) {
            int ii = i + dirx[k];
            int jj = j + diry[k];
            if (mapx[ii][jj] == '#') {
              addedge(i * n + j, ii * n + jj);
            }
          }
      }
    }
    int ans = hungary() / 2;
    printf("Case %d: %d\n", ca, ans);
  }
  return 0;
}

// 基本上是裸的图匹配，注意点个数