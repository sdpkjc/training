// POJ-3259 Wormholes
// https://vjudge.net/problem/POJ-3259

#include <queue>
#include <vector>
using namespace std;

const int MAXN = 1010;
const int INF = 0x3f3f3f3f;
struct Edge {
  int v;
  int cost;
  Edge(int _v = 0, int _cost = 0) : v(_v), cost(_cost) {}
};
vector<Edge> E[MAXN];
void addedge(int u, int v, int w) { E[u].push_back(Edge(v, w)); }
bool vis[MAXN];  //在队列标志
int cnt[MAXN];   //每个点的入队列次数
int dist[MAXN];

bool SPFA(int start, int n) {
  memset(vis, false, sizeof(vis));
  for (int i = 1; i <= n; i++) dist[i] = INF;
  vis[start] = true;
  dist[start] = 0;
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
      if (dist[v] > dist[u] + E[u][i].cost) {
        dist[v] = dist[u] + E[u][i].cost;
        if (!vis[v]) {
          vis[v] = true;
          que.push(v);
          if (++cnt[v] > n) return false;
          // cnt[i] 为入队列次数，用来判定是否存在负环回路
        }
      }
    }
  }
  return true;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    for (int i = 0; i < MAXN; i++) E[i].clear();
    int N, M, W;
    scanf("%d%d%d", &N, &M, &W);
    for (int i = 0; i < M; i++) {
      int S, E, Ti;
      scanf("%d%d%d", &S, &E, &Ti);
      addedge(S, E, Ti);
      addedge(E, S, Ti);
    }
    for (int i = 0; i < W; i++) {
      int S, E, Ti;
      scanf("%d%d%d", &S, &E, &Ti);
      addedge(S, E, -Ti);
    }
    if (!SPFA(1, N)) {
      printf("YES");
    } else {
      printf("NO");
    }
    printf("\n");
  }
  return 0;
}

// 经过虫洞时光倒流，判断负值圈