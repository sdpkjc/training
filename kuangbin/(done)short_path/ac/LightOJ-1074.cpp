// LightOJ-1074 Extended Traffic
// https://vjudge.net/problem/LightOJ-1074

#include <string.h>
#include <cstdio>
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
          if (++cnt[v] > n) {
            dist[v] = -INF;
          } else {
            que.push(v);
          }
          // cnt[i] 为入队列次数，用来判定是否存在负环回路
        }
      }
    }
  }
  return true;
}
int arr[MAXN];

int main() {
  int T;
  scanf("%d", &T);
  for (int Case = 1; Case <= T; Case++) {
    for (int i = 0; i < MAXN; i++) {
      E[i].clear();
    }
    printf("Case %d:\n", Case);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &arr[i]);
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      addedge(a, b, (arr[b] - arr[a]) * (arr[b] - arr[a]) * (arr[b] - arr[a]));
    }
    bool flag = SPFA(1, n);
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
      int x, ans;
      scanf("%d", &x);
      if (dist[x] == INF || dist[x] < 3) {
        printf("?\n");
      } else {
        printf("%d\n", dist[x]);
      }
    }
  }
}

// SPFA 判断**所有负环**