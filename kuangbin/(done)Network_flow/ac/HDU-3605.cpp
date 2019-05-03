// HDU-3605 Escape
// https://vjudge.net/problem/HDU-3605

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
int st[10000];
int main() {
  int n, m;
  while (~scanf("%d%d", &n, &m)) {
    init();
    memset(st, 0, sizeof(st));
    int S = 0, T = m + (1 << m) + 1;
    // 1 -> 2000
    // 2001 -> 2001 + m
    for (int i = 1; i <= n; i++) {
      int state = 0;
      for (int j = 1; j <= m; j++) {
        int tmp;
        scanf("%d", &tmp);
        state = state << 1 | tmp;
      }
      st[state]++;
    }
    for (int i = 1; i < (1 << m); i++) {
      if (st[i]) {
        addedge(S, i, st[i]);
        int tmp = i;
        for (int j = m; j >= 1; j--) {
          if (tmp & 1) {
            addedge(i, (1 << m) + j, INF);
          }
          tmp >>= 1;
        }
      }
    }
    for (int i = 1; i <= m; i++) {
      int tmp;
      scanf("%d", &tmp);
      addedge(i + (1 << m), T, tmp);
    }
    int ans = dinic(S, T, T + 10);
    if (ans == n) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }

  return 0;
}

// 状态压缩
// n个人压缩每个人有一种状态，一共有 (1<<m) 种状态
// S -> 状态点连接一条权值为有多少人处于此状态的边
// 状态点向与此状态相关的星球连一条权值为INF的边
// 匈牙利算法好像也可以，题解：https://blog.csdn.net/xingdragon/article/details/70821092