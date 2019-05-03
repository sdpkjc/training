// POJ-2502 Subway
// https://vjudge.net/problem/POJ-2502

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
      int cost = E[u][i].cost;
      if (!vis[v] && dist[v] > dist[u] + cost) {
        dist[v] = dist[u] + cost;
        que.push(qnode(v, dist[v]));
      }
    }
  }
}
void addedge(int u, int v, double w) { E[u].push_back(Edge(v, w)); }

double xx[300];
double yy[300];

double len(int a, int b) {
  return sqrt((xx[a] - xx[b]) * (xx[a] - xx[b]) +
              (yy[a] - yy[b]) * (yy[a] - yy[b]));
}

int main() {
  int cnt = 1;
  scanf("%lf%lf", &xx[cnt], &yy[cnt]);
  cnt++;
  scanf("%lf%lf", &xx[cnt], &yy[cnt]);
  cnt++;
  while (~scanf("%lf%lf", &xx[cnt], &yy[cnt])) {
    vector<int> subway;
    subway.push_back(cnt);
    cnt++;
    while (xx[cnt - 1] != -1 && yy[cnt - 1] != -1) {
      scanf("%lf%lf", &xx[cnt], &yy[cnt]);
      subway.push_back(cnt);
      cnt++;
    }
    cnt--;
    for (int i = 0; i < subway.size() - 2; i++) {
      addedge(subway[i], subway[i + 1],
              len(subway[i], subway[i + 1]) / 40 * 60);
      addedge(subway[i + 1], subway[i],
              len(subway[i], subway[i + 1]) / 40 * 60);
    }
  }
  for (int i = 1; i <= cnt; i++) {
    for (int j = 1; j <= cnt; j++) {
      if (i == j) continue;
      addedge(i, j, len(i, j) / 10 * 60);
    }
  }
  Dijkstra(cnt, 1);
  printf("%d\n", int(dist[2] / 1000 + 0.5));
}

// 水题，连边麻烦一点，输入也麻烦
// 地铁只能一站一站的走
// 结果要输出整数，竟然要四舍五入！！！