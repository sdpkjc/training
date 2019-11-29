/* * 使用优先队列优化 Dijkstra 算法
 * 复杂度 O(ElogE)
 * 注意对
 * vector<Edge>E[MAXN] 进行初始化后加边
 */

#include <string.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 100010;

struct qnode {
  int v, c;
  qnode(int _v = 0, int _c = 0) : v(_v), c(_c){};
  bool operator<(const qnode& r) const { return c > r.c; }
};

struct Edge {
  int v, cost;
  Edge(int _v = 0, int _cost = 0) : v(_v), cost(_cost) {}
};
vector<Edge> E[MAXN];
bool vis[MAXN];
int dist[MAXN];

//点的编号从 1 开始

void Dijkstra(int n, const vector<int>& start) {
  memset(vis, false, sizeof(vis));
  for (int i = 1; i <= n; i++) dist[i] = INF;
  priority_queue<qnode> que;
  while (!que.empty()) que.pop();
  for (int i = 0; i < start.size(); i++) {
    int ss = start[i];
    dist[ss] = 0;
    que.push(qnode(ss, 0));
  }
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
  int T;
  scanf("%d", &T);

  while (T--) {
    vector<int> A, B;
    int Vin, Ein, Sin, Kin, Cin;
    scanf("%d%d%d%d%d", &Vin, &Ein, &Sin, &Kin, &Cin);
    for (int i = 0; i <= Vin + 10; i++) {
      E[i].clear();
    }
    for (int i = 0; i < Kin; i++) {
      int tk;
      scanf("%d", &tk);
      B.push_back(tk);
    }
    for (int i = 0; i < Ein; i++) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      addedge(a, b, c);
      addedge(b, a, c);
    }
    A.push_back(Sin);
    Dijkstra(Vin, A);
    int ans1 = 0;
    for (int i = 1; i <= Vin; i++) {
      ans1 = max(ans1, dist[i]);
    }
    Dijkstra(Vin, B);
    int ans2 = 0;
    for (int i = 1; i <= Vin; i++) {
      ans2 = max(ans2, dist[i]);
    }
    if (ans1 <= ans2 * Cin) {
      printf("%d", ans1);
    } else {
      printf("%d", ans2);
    }
    putchar('\n');
  }
  return 0;
}