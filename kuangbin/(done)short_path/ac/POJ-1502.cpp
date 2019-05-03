// POJ-1502 MPI Maelstrom
// https://vjudge.net/problem/POJ-1502

#include <string.h>
#include <cstdio>
#include <queue>
#include <vector>
// #include <sstream>
// #include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1000;

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
  int n;
  scanf("%d", &n);
  char str[100];
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i - 1; j++) {
      //   string s;
      //   cin >> s;
      //   if (s[0] == 'x') continue;
      //   stringstream ss;
      //   ss << s;
      //   ss >> tmp;
      scanf("%s", str);
      if (str[0] == 'x') continue;
      int tmp = atoi(str);
      addedge(i, j, tmp);
      addedge(j, i, tmp);
    }
  }
  Dijkstra(n, 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dist[i]);
  }
  printf("%d\n", ans);
  return 0;
}

// 从 1 出发最短路中的最长路