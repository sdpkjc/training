// HDU-4370 0 or 1
// https://vjudge.net/problem/HDU-4370

#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 500;
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
  memset(cnt, 0, sizeof(cnt));
  memset(dist, 0x3f, sizeof(dist));
  queue<int> que;
  for (int i = 0; i < E[start].size(); i++) {
    dist[E[start][i].v] = E[start][i].cost;
  }
  for (int i = 1; i <= n; i++) {
    if (i != start) {
      vis[i] = true;
      cnt[i]++;
      que.push(i);
    }
  }
  dist[start] = INF;
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
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 0; i < MAXN; i++) {
      E[i].clear();
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        int tmp;
        scanf("%d", &tmp);
        addedge(i, j, tmp);
      }
    }
    SPFA(1, n);
    int a = dist[n];
    int b1 = dist[1];
    SPFA(n, n);
    int b2 = dist[n];
    printf("%d\n", min(a, b1 + b2));
  }
  return 0;
}

// 蜜汁转换，蜜汁SPFA，不会，暂时放弃
// bin巨题解：https://www.cnblogs.com/kuangbin/archive/2012/08/17/2644557.html