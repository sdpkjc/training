#include <string.h>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define int long long

const int INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 20005;

struct qnode {
  int v, c;
  qnode(int _v = 0, int _c = 0) : v(_v), c(_c){};
  bool operator<(const qnode &r) const { return c > r.c; }
};

struct Edge {
  int u, v, cost;
  Edge(int _u = 0, int _v = 0, int _cost = 0) : u(_u), v(_v), cost(_cost) {}
};
vector<Edge> E[MAXN];
vector<Edge> Ex;
bool vis[MAXN];
int dist[MAXN];

void Dijkstra(int n, int start) {
  memset(vis, false, sizeof(vis));
  for (int i = 1; i <= n; i++) dist[i] = INF;
  priority_queue<qnode> que;
  while (!que.empty()) que.pop();
  dist[start] = 0;
  que.push(qnode(start, 0));
  qnode tmp;
  while (!que.empty()) {
    tmp = que.top();
    que.pop();
    int u = tmp.v;
    if (vis[u]) continue;
    vis[u] = true;
    for (int i = 0; i < E[u].size(); i++) {
      int v = E[tmp.v][i].v;
      int cost = E[u][i].cost;
      if (!vis[v] && dist[v] > dist[u] + cost) {
        dist[v] = dist[u] + cost;
        que.push(qnode(v, dist[v]));
      }
    }
  }
}
void addedge(int u, int v, int w) { E[u].push_back(Edge(u, v, w)); }

const int MAXM = 1200010;
struct Edgef {
  int to, next, cap, flow;
} edge[MAXM];
int tol;
int head[MAXN];
void init() {
  tol = 2;
  memset(head, -1, sizeof(head));
}
void addedge(int u, int v, int w, int rw) {
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
    for (int i = 0; i < n; i++) {
      cur[i] = head[i];
    }
    int u = s, tail = 0;
    while (cur[s] != -1) {
      if (u == t) {
        int tp = INF;
        for (int i = tail - 1; i >= 0; i--) {
          tp = min(tp, edge[sta[i]].cap - edge[sta[i]].flow);
        }
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
        while (u != s && cur[u] == -1) {
          u = edge[sta[--tail] ^ 1].to;
        }
        cur[u] = edge[cur[u]].next;
      }
    }
  }
  return maxflow;
}

int distA[MAXN];
int distB[MAXN];

signed main() {
  int T;
  scanf("%lld", &T);
  while (T--) {
    init();
    Ex.clear();
    for (int i = 0; i < MAXN; i++) {
      E[i].clear();
    }
    int n, m;
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i < m; i++) {
      int a, b, c;
      scanf("%lld%lld%lld", &a, &b, &c);
      Ex.push_back(Edge(a, b, c));
      addedge(a, b, c);
    }
    int A, B;
    A = 1;
    B = n;
    Dijkstra(n, A);
    memcpy(distA, dist, sizeof(dist));
    for (int i = 0; i < MAXN; i++) {
      E[i].clear();
    }
    for (int i = 0; i < Ex.size(); i++) {
      addedge(Ex[i].v, Ex[i].u, Ex[i].cost);
    }
    Dijkstra(n, B);
    memcpy(distB, dist, sizeof(dist));

    for (int i = 0; i < Ex.size(); i++) {
      if (distA[Ex[i].u] + distB[Ex[i].v] + Ex[i].cost == distA[B]) {
        addedge(Ex[i].u, Ex[i].v, Ex[i].cost, 0);
      }
    }
    int ans = dinic(A, B, n);
    printf("%lld\n", ans);
  }
}