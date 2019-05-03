// HDU-4725 The Shortest Path in Nya Graph
// https://vjudge.net/problem/HDU-4725

#include <string.h>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 300005;

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
int arr[MAXN];
int flag[MAXN];
int main() {
  int T;
  scanf("%d", &T);
  for (int Case = 1; Case <= T; Case++) {
    int N, M, C;
    scanf("%d%d%d", &N, &M, &C);
    memset(flag, 0, sizeof(flag));
    for (int i = 1; i <= N * 3; i++) {
      E[i].clear();
    }
    for (int i = 1; i <= N; i++) {
      scanf("%d", &arr[i]);
      flag[arr[i]]++;

      addedge(i, arr[i] + N + 1 + 1, 0);
      addedge(i, arr[i] + N + 1 - 1, 0);

      addedge(arr[i] + N + 1, i, C);
    }

    for (int i = 0; i < M; i++) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      addedge(a, b, c);
      addedge(b, a, c);
    }
    Dijkstra(N * 3, 1);
    printf("Case #%d: ", Case);
    if (dist[N] == INF) {
      printf("%d\n", -1);
    } else {
      printf("%d\n", dist[N]);
    }
  }
}

// 建图困难一些的最短路问题，如果完全按题意建图会超时
// 将层抽象成虚点，点到相邻层的虚点连一条 0
// 边权的虚边，虚点到当前层的点连一条 C 边权的边