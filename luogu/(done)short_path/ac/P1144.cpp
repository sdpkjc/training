// P1144 最短路计数
// https://www.luogu.org/problemnew/show/P1144

#include <string.h>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1000010;
const int MOD = 100003;
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
int cnt[MAXN];

//点的编号从 1 开始

void Dijkstra(int n, int start) {
  memset(vis, false, sizeof(vis));
  for (int i = 1; i <= n; i++) {
    dist[i] = INF;
    cnt[i] = 0;
  }
  priority_queue<qnode> que;
  while (!que.empty()) que.pop();
  dist[start] = 0;
  cnt[start] = 1;
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
        cnt[v] = cnt[u] % MOD;
        que.push(qnode(v, dist[v]));
      } else if (!vis[v] && dist[v] == dist[u] + cost) {
        dist[v] = dist[u] + cost;
        cnt[v] = (cnt[v] + cnt[u]) % MOD;
        que.push(qnode(v, dist[v]));
      }
    }
  }
}
void addedge(int u, int v, int w) { E[u].push_back(Edge(v, w)); }

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    addedge(a, b, 1);
    addedge(b, a, 1);
  }
  Dijkstra(n, 1);
  for (int i = 1; i <= n; i++) {
    printf("%d\n", cnt[i] % MOD);
  }
}

// 改一下 Dij 的更新操作
// BFS || SPFA 都可以