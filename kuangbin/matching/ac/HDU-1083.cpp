// HDU-1083 Courses
// https://vjudge.net/problem/HDU-1083

#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 5010;    //点数的最大值
const int MAXM = 500010;  //边数的最大值
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

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    init();
    int p, n;
    scanf("%d%d", &p, &n);
    uN = n;
    for (int i = 1; i <= p; i++) {
      int cn;
      scanf("%d", &cn);
      for (int j = 0; j < cn; j++) {
        int tmp;
        scanf("%d", &tmp);
        addedge(tmp, i);
      }
    }
    int ans = hungary();
    printf("%s\n", ans == p ? "YES" : "NO");
  }
  return 0;
}

// 水