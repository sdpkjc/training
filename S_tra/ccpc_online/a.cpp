#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 100105;
struct qnode {
  int v;
  ll c;
  qnode(int _v = 0, ll _c = 0) : v(_v), c(_c){};
  bool operator<(const qnode& r) const { return c > r.c; }
};
struct Edge {
  int v;
  ll cost;
  Edge(int _v = 0, ll _cost = 0) : v(_v), cost(_cost) {}
};
vector<Edge> E[MAXN];
void addedge(int u, int v, ll w) { E[u].push_back(Edge(v, w)); }

int qarr[MAXN];

int n, m, q;
ll qans[MAXN];
int maxq;
void Dijkstra() {
  priority_queue<qnode> que;
  while (!que.empty()) que.pop();
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < E[i].size(); j++) {
      que.push(qnode(E[i][j].v, E[i][j].cost));
    }
  }
  qnode tmp;
  int cnt = 1;
  while (!que.empty()) {
    tmp = que.top();
    que.pop();
    int u = tmp.v;
    ll c = tmp.c;
    qans[cnt++] = c;
    if (cnt > maxq) {
      return;
    }
    for (int i = 0; i < E[u].size(); i++) {
      int v = E[u][i].v;
      ll cost = E[u][i].cost;
      que.push(qnode(v, c + cost));
      if (que.size() > n + maxq + m + 10) {
        break;
      }
    }
  }
  while (!que.empty()) {
    tmp = que.top();
    que.pop();
    int u = tmp.v;
    ll c = tmp.c;
    qans[cnt++] = c;
    if (cnt > maxq) {
      return;
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n + 10; i++) {
      E[i].clear();
    }
    for (int i = 0; i < m; i++) {
      int a, b;
      ll w;
      scanf("%d%d%lld", &a, &b, &w);
      addedge(a, b, w);
    }
    maxq = 0;
    for (int i = 0; i < q; i++) {
      scanf("%d", &qarr[i]);
      maxq = max(qarr[i], maxq);
    }
    Dijkstra();

    for (int i = 0; i < q; i++) {
      printf("%lld\n", qans[qarr[i]]);
    }
  }

  return 0;
}