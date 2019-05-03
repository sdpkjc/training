// POJ-2253 Frogger
// https://vjudge.net/problem/POJ-2253

#include <string.h>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1000010;

struct qnode {
  int v;
  double c;
  qnode(int _v = 0, double _c = 0) : v(_v), c(_c){};
  bool operator<(const qnode &r) const { return c > r.c; }
};

struct Edge {
  int v;
  double cost;
  Edge(int _v = 0, double _cost = 0) : v(_v), cost(_cost) {}
};
vector<Edge> E[MAXN];
bool vis[MAXN];
double dist[MAXN];

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
      double cost = E[u][i].cost;
      if (!vis[v] && dist[v] > max(dist[u], cost)) {
        dist[v] = max(dist[u], cost);
        que.push(qnode(v, dist[v]));
      }
    }
  }
}
void addedge(int u, int v, double w) { E[u].push_back(Edge(v, w)); }

double tone_x[MAXN], tone_y[MAXN];

double len(int a, int b) {
  return sqrt((tone_x[a] - tone_x[b]) * (tone_x[a] - tone_x[b]) +
              (tone_y[a] - tone_y[b]) * (tone_y[a] - tone_y[b]));
}

int main() {
  int N;
  int CNT = 1;
  while (~scanf("%d", &N)) {
    if (N == 0) break;
    for (int i = 0; i < MAXN; i++) {
      E[i].clear();
    }
    for (int i = 1; i <= N; i++) {
      scanf("%lf%lf", &tone_x[i], &tone_y[i]);
    }
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (i == j) continue;
        addedge(i, j, len(i, j));
      }
    }
    Dijkstra(N, 1);
    printf("Scenario #%d\n", CNT++);
    printf("Frog Distance = %.3lf\n\n", dist[2]);
  }
}

// 最短路变形，大坑：POJ选择C++才能过？？？