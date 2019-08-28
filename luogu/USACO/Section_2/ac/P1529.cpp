// P1529 回家 Bessie Come Home
// https://www.luogu.org/problem/P1529

#include <string.h>
#include <iostream>
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

int ys(char a) {
  if (a >= 'a' && a <= 'z') {
    return a - 'a' + 1;
  }
  //   if (a >= 'A' && a <= 'A') {
  //   }
  return a - 'A' + 26 + 1;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char a, b;
    int c;
    cin >> a >> b >> c;
    addedge(ys(a), ys(b), c);
    addedge(ys(b), ys(a), c);
  }
  Dijkstra(1000, ys('Z'));
  int ans = 0x3f3f3f3f;
  char aa;
  for (char c = 'A'; c < 'Z'; c++) {
    // ans = min(ans, dist[ys(c)]);
    if (dist[ys(c)] < ans) {
      aa = c;
      ans = dist[ys(c)];
    }
  }
  cout << aa << " " << ans << endl;

  return 0;
}