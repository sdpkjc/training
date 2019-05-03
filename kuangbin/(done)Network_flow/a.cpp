#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 2010;     //点数的最大值
const int MAXM = 1200010;  //边数的最大值
const int INF = 0x3f3f3f3f;
struct Edge {
  int to, next, cap, flow;
} edge[MAXM];  //注意是 MAXM
int tol;
int head[MAXN];
void init() {
  tol = 2;
  memset(head, -1, sizeof(head));
}
void addedge(int u, int v, int w, int rw = 0) {
  edge[tol].to = v;
  edge[tol].cap = w;
  edge[tol].flow = 0;

  edge[tol].next = head[u];
  head[u] = tol++;

  edge[tol].to = u;
  edge[tol].cap = rw;
  edge[tol].flow = 0;

  edge[tol].next = head[v];
  head[v] = tol++;
}
int Q[MAXN];
int dep[MAXN], cur[MAXN], sta[MAXN];
bool bfs(int s, int t, int n) {
  int front = 0, tail = 0;
  memset(dep, -1, sizeof(dep[0]) * (n + 1));
  dep[s] = 0;
  Q[tail++] = s;

  while (front < tail) {
    int u = Q[front++];
    for (int i = head[u]; i != -1; i = edge[i].next) {
      int v = edge[i].to;
      if (edge[i].cap > edge[i].flow && dep[v] == -1) {
        dep[v] = dep[u] + 1;
        if (v == t) return true;
        Q[tail++] = v;
      }
    }
  }
  return false;
}
int dinic(int s, int t, int n) {
  int maxflow = 0;
  while (bfs(s, t, n)) {
    for (int i = 0; i < n; i++) cur[i] = head[i];
    int u = s, tail = 0;
    while (cur[s] != -1) {
      if (u == t) {
        int tp = INF;
        for (int i = tail - 1; i >= 0; i--)
          tp = min(tp, edge[sta[i]].cap - edge[sta[i]].flow);
        maxflow += tp;
        for (int i = tail - 1; i >= 0; i--) {
          edge[sta[i]].flow += tp;
          edge[sta[i] ^ 1].flow -= tp;
          if (edge[sta[i]].cap - edge[sta[i]].flow == 0) tail = i;
        }
        u = edge[sta[tail] ^ 1].to;
      } else if (cur[u] != -1 && edge[cur[u]].cap > edge[cur[u]].flow &&
                 dep[u] + 1 == dep[edge[cur[u]].to]) {
        sta[tail++] = cur[u];
        u = edge[cur[u]].to;
      } else {
        while (u != s && cur[u] == -1) u = edge[sta[--tail] ^ 1].to;
        cur[u] = edge[cur[u]].next;
      }
    }
  }
  return maxflow;
}
char mapx[MAXN][MAXN];
char xmapx[MAXN][MAXN];

int n, m, d;

int dex(int i, int j) { return i * (m + 2) + j; }

int main() {
  int cT;
  scanf("%d", &cT);
  for (int Case = 1; Case <= cT; Case++) {
    init();
    scanf("%d%d", &n, &d);

    for (int i = 1; i <= n; i++) {
      scanf("%s", mapx[i] + 1);
    }
    m = strlen(mapx[1] + 1);
    for (int i = 1; i <= n; i++) {
      scanf("%s", xmapx[i] + 1);
    }
    int S = (n + 5) * (m + 5) * 2;
    int T = S + 1;
    int suff = (n + 5) * (m + 5);
    for (int i = 0; i <= n + 1; i++) {
      for (int j = 0; j <= m + 1; j++) {
        if (i == 0 || j == 0 || i == n + 1 || j == m + 1) {
          addedge(dex(i, j), T, INF);
          mapx[i][j] = '1';
        }
      }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (mapx[i][j] != '0') {
          addedge(dex(i, j), dex(i, j) + suff, mapx[i][j] - '0');
        }
        if (xmapx[i][j] == 'L') {
          cnt++;
          addedge(S, dex(i, j), 1);
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (mapx[i][j] != '0')
          for (int k = 0; k <= n + 1; k++) {
            for (int mm = 0; mm <= m + 1; mm++) {
              int su = abs(i - k) + abs(j - mm);
              if (mapx[k][mm] != '0') {
                if (su > 0 && su <= d) {
                  addedge(dex(i, j) + suff, dex(k, mm), INF);
                }
              }
            }
          }
      }
    }
    int ans = cnt - dinic(S, T, T + 10);
    if (ans == 0) {
      printf("Case #%d: no lizard was left behind.", Case);
    } else if (ans == 1) {
      printf("Case #%d: %d lizard was left behind.", Case, ans);
    } else {
      printf("Case #%d: %d lizards were left behind.", Case, ans);
    }
    printf("\n");
  }
  return 0;
}

// 拆点，输出神坑