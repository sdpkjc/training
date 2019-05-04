// HDU-1045 Fire Net
// https://vjudge.net/problem/HDU-1045

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
char mapx[100][100];

int main() {
  int n;
  while (true) {
    scanf("%d", &n);
    if (n == 0) break;
    init();
    int S = 0, T = n + n + 10;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        scanf(" %c", &mapx[i][j]);
      }
    }
    for (int i = 1; i <= n; i++) {
      int cnt = 1;
      for (int j = 1; j <= n; j++) {
        if (mapx[i][j] == 'X') {
          cnt++;
        }
      }
      addedge(S, i, cnt);
    }
    for (int i = 1; i <= n; i++) {
      int cnt = 1;
      for (int j = 1; j <= n; j++) {
        if (mapx[j][i] == 'X') {
          cnt++;
        }
      }
      addedge(i + n, T, cnt);
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (mapx[i][j] == '.') {
          addedge(i, j + n, 1);
        }
      }
    }
    int ans = dinic(S, T, T + 10);
    printf("%d\n", ans);
  }
  return 0;
}

// 每一行或每一列每多一堵墙流量加 1，然后用dinic做二分图匹配