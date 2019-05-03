// POJ-1860 Currency Exchange
// https://vjudge.net/problem/POJ-1860

#include <queue>
#include <vector>
using namespace std;

int N, M, S;
double V;

const int MAXN = 1010;
const int INF = 10000;
struct Edge {
  int v;
  double cost;
  double c;
  Edge(int _v = 0, double _cost = 0, double _c = 0)
      : v(_v), cost(_cost), c(_c) {}
};
vector<Edge> E[MAXN];
void addedge(int u, int v, double w, double c) {
  E[u].push_back(Edge(v, w, c));
}
bool vis[MAXN];  //在队列标志
int cnt[MAXN];   //每个点的入队列次数
double dist[MAXN];

bool SPFA(int start, int n) {
  memset(vis, false, sizeof(vis));
  for (int i = 1; i <= n; i++) dist[i] = 0;
  vis[start] = true;
  dist[start] = V;
  queue<int> que;
  que.push(start);
  memset(cnt, 0, sizeof(cnt));
  cnt[start] = 1;
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    vis[u] = false;
    for (int i = 0; i < E[u].size(); i++) {
      int v = E[u][i].v;
      if (dist[v] < (dist[u] - E[u][i].c) * E[u][i].cost) {
        dist[v] = (dist[u] - E[u][i].c) * E[u][i].cost;
        if (!vis[v]) {
          vis[v] = true;
          que.push(v);
          if (++cnt[v] > n) return true;
          // cnt[i] 为入队列次数，用来判定是否存在负环回路
        }
      }
    }
  }
  return false;
}

int main() {
  scanf("%d%d%d%lf", &N, &M, &S, &V);
  for (int i = 0; i < M; i++) {
    int a, b;
    double rab, cab, rba, cba;
    scanf("%d%d%lf%lf%lf%lf", &a, &b, &rab, &cab, &rba, &cba);
    addedge(a, b, rab, cab);
    addedge(b, a, rba, cba);
  }

  if (SPFA(S, N)) {
    printf("YES");
  } else {
    printf("NO");
  }
  printf("\n");

  return 0;
}

// 换汇问题，最长路判断正环