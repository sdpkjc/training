// HDU-3081 Marriage Match II
// https://vjudge.net/problem/HDU-3081

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
int dist[MAXN][MAXN];

void floyd(int n) {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = (dist[i][j] || (dist[i][k] && dist[k][j]));
      }
    }
  }
}

int n, m, f;
int S, T;

void bulid(int mid) {
  // girl 1 -> n
  // children n + 1 -> n + n;
  for (int i = 1; i <= n; i++) {
    for (int j = n + 1; j <= n + n; j++) {
      if (dist[i][j]) {
        addedge(i, j, 1);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    addedge(S, i, mid);
  }
  for (int i = n + 1; i <= n + n; i++) {
    addedge(i, T, mid);
  }
}

bool check(int mid) {
  init();
  bulid(mid);
  int ans = dinic(S, T, 3 * n);
  if (ans == mid * n) return true;
  return false;
}

int main() {
  int xT;
  scanf("%d", &xT);
  while (xT--) {
    init();
    memset(dist, 0, sizeof(dist));
    scanf("%d%d%d", &n, &m, &f);
    S = 0, T = n + n + 1;
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      dist[a][b + n] = 1;
    }
    for (int i = 0; i < f; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      dist[a][b] = 1;
      dist[b][a] = 1;
    }
    floyd(2 * n);
    int l = 0, r = n + 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (check(mid))
        l = mid + 1;
      else
        r = mid;
    }
    printf("%d\n", r - 1);
  }
  return 0;
}

// 最大流 + 传递闭包 + 二分
// 所有的女生可以选择和自己或和其朋友没吵过架的男生
// 二分图匹配计数