// POJ-1062 昂贵的聘礼
// https://vjudge.net/problem/POJ-1062

#include <string.h>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

int M, N;

const int MAXN = 1010;
const int INF = 0x3f3f3f3f;
struct Edge {
  int v;
  int cost;
  Edge(int _v = 0, int _cost = 0) : v(_v), cost(_cost) {}
};
vector<Edge> E[MAXN];
void addedge(int u, int v, int w) { E[u].push_back(Edge(v, w)); }

long long degree[MAXN];
bool vis[MAXN];  //在队列标志
int cnt[MAXN];   //每个点的入队列次数
long long dist[MAXN];

bool SPFA(int start, int n, int a, int b) {
  memset(vis, false, sizeof(vis));
  memset(dist, 0x3f, sizeof(dist));

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
      if (degree[v] < a || degree[v] > b) {
        continue;
      }
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
  scanf("%d%d", &M, &N);
  for (int i = 0; i <= N; i++) {
    E[i].clear();
  }

  long long mind = 100000, maxd = 0;
  for (int i = 1; i <= N; i++) {
    int w, X;
    scanf("%d%lld%d", &w, &degree[i], &X);

    mind = min(mind, degree[i]);
    maxd = max(maxd, degree[i]);
    addedge(0, i, w);
    for (int j = 0; j < X; j++) {
      int T, V;
      scanf("%d%d", &T, &V);
      addedge(T, i, V);
    }
  }
  long long ans = E[0][0].cost;
  for (int i = degree[1] - M; i <= degree[1]; i++) {
    SPFA(0, N, i, i + M);
    ans = min(ans, dist[1]);
  }
  cout << ans << endl;
}
