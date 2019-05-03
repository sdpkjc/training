// P1346 电车
// https://www.luogu.org/problemnew/show/P1346

#include <string.h>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1000010;

struct qnode {
  int v, c;
  qnode(int _v = 0, int _c = 0) : v(_v), c(_c){};
  bool operator<(const qnode &r) const { return c > r.c; }
};

struct Edge {
  int v, cost;
  Edge(int _v = 0, int _cost = 0) : v(_v), cost(_cost) {}
};
vector<Edge> E[MAXN];
bool vis[MAXN];
int dist[MAXN];

//点的编号从 1 开始

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
void addedge(int u, int v, int w) { E[u].push_back(Edge(v, w)); }

int main() {
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);
  for (int i = 1; i <= n; i++) {
    int m;
    scanf("%d", &m);
    for (int j = 0; j < m; j++) {
      int v;
      int w = 1;
      scanf("%d", &v);
      if (j == 0) w = 0;
      addedge(i, v, w);
    }
  }
  Dijkstra(n, a);
  if (dist[b] == INF) {
    printf("-1\n");
  } else {
    printf("%d\n", dist[b]);
  }
}

// POJ-1847 Tram