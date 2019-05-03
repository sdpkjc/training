// POJ-3268 Silver Cow Party
// https://vjudge.net/problem/POJ-3268

#include <string.h>
#include <queue>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 10000;

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
vector<Edge> Etmp;

bool vis[MAXN];
int dist[MAXN];
int tdist[MAXN];
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
void addedge(int u, int v, int w) { E[u].push_back(Edge(u, v, w)); }

int main() {
  int n, m, x;
  scanf("%d%d%d", &n, &m, &x);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    addedge(a, b, c);
    Etmp.push_back(Edge(a, b, c));
  }
  Dijkstra(n, x);
  for (int i = 1; i <= n; i++) {
    tdist[i] = dist[i];
    E[i].clear();
  }
  for (int i = 0; i < m; i++) {
    addedge(Etmp[i].v, Etmp[i].u, Etmp[i].cost);
  }
  int ans = 0;
  Dijkstra(n, x);
  for (int i = 1; i <= n; i++) {
    tdist[i] += dist[i];
    ans = max(ans, tdist[i]);
  }
  printf("%d\n", ans);

  return 0;
}

// 从 x 向所有点跑一次 dij，将边反向再来一次，求往返距离