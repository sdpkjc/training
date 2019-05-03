// POJ-1797 Heavy Transportation
// https://vjudge.net/problem/POJ-1797

#include <string.h>
#include <queue>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 10000;

struct qnode {
  int v, c;
  qnode(int _v = 0, int _c = 0) : v(_v), c(_c){};
  bool operator<(const qnode &r) const { return c < r.c; }
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
  for (int i = 1; i <= n; i++) dist[i] = 0;
  priority_queue<qnode> que;
  while (!que.empty()) que.pop();
  dist[start] = INF;
  que.push(qnode(start, dist[start]));
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
      if (!vis[v] && dist[v] < min(dist[u], cost)) {
        dist[v] = min(dist[u], cost);
        que.push(qnode(v, dist[v]));
      }
    }
  }
}
void addedge(int u, int v, int w) { E[u].push_back(Edge(v, w)); }
int main() {
  int T, CNT = 1;
  scanf("%d", &T);
  while (CNT <= T) {
    for (int i = 0; i < MAXN; i++) {
      E[i].clear();
    }
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
      int a, b, w;
      scanf("%d%d%d", &a, &b, &w);
      addedge(a, b, w);
      addedge(b, a, w);
    }
    Dijkstra(n, 1);
    printf("Scenario #%d:\n%d\n\n", CNT++, dist[n]);
  }
  return 0;
}

//求 1 - n 中所有路径中最大边权的最小值