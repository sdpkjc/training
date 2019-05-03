// POJ-2387 Til the Cows Come Home
// https://vjudge.net/problem/POJ-2387

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
  int T, N;
  while (~scanf("%d%d", &T, &N)) {
    for (int i = 0; i < MAXN; i++) {
      E[i].clear();
    }
    for (int i = 0; i < T; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      addedge(u, v, w);
      addedge(v, u, w);
    }
    Dijkstra(N, 1);
    printf("%d\n", dist[N]);
  }
}

// 裸的 dji_set，坑：多组输入！