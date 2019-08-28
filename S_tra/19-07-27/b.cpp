/* * 使用优先队列优化 Dijkstra 算法
 * 复杂度 O(ElogE)
 * 注意对
 * vector<Edge>E[MAXN] 进行初始化后加边
 */

#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1000010;
int n, m, s, t, k;
struct qnode {
  int v, c;
  multiset<int, greater<int> > S;
  int f() const {
    int ans = 0;
    int cnt = 0;
    for (auto it = S.begin(); it != S.end(); it++, cnt++) {
      if (cnt >= k) ans += *it;
    }
    return ans;
  }
  qnode(const qnode &t) {
    v = t.v;
    c = t.c;
    S = t.S;
  }
  qnode operator=(const qnode &t) {
    v = t.v;
    c = t.c;
    S = t.S;
    return t;
  }
  qnode(int _v = 0, int _c = 0) : v(_v), c(_c){};
  bool operator<(const qnode &r) const { return f() > r.f(); }
};

struct Edge {
  int v, cost;
  Edge(int _v = 0, int _cost = 0) : v(_v), cost(_cost) {}
};
vector<Edge> E[MAXN];
// bool vis[MAXN];
int dist[MAXN];

//点的编号从 1 开始

void Dijkstra(int n, int start) {
  //   memset(vis, false, sizeof(vis));
  for (int i = 1; i <= n; i++) dist[i] = INF;
  queue<qnode> que;
  dist[start] = 0;
  que.push(qnode(start, 0));
  while (!que.empty()) {
    qnode tmp = que.front();
    que.pop();
    int u = tmp.v;
    for (int i = 0; i < E[u].size(); i++) {
      int v = E[tmp.v][i].v;
      int cost = E[u][i].cost;
      qnode tt = tmp;
      tt.S.insert(cost);
      tt.v = v;
      int fcost = tt.f();
      if (dist[v] > fcost) {
        dist[v] = fcost;
        que.push(tt);
      }
    }
  }
}
void addedge(int u, int v, int w) { E[u].push_back(Edge(v, w)); }

signed main() {
  cin >> n >> m >> s >> t >> k;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    addedge(a, b, c);
    addedge(b, a, c);
  }
  Dijkstra(n, s);
  cout << dist[t] << endl;

  return 0;
}