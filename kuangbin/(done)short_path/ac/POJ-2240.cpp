// POJ-2240 Arbitrage
// https://vjudge.net/problem/POJ-2240

#include <string.h>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const int MAXN = 1010;
const int INF = 0x3f3f3f3f;
struct Edge {
  int v;
  double cost;
  Edge(int _v = 0, double _cost = 0) : v(_v), cost(_cost) {}
};
vector<Edge> E[MAXN];
void addedge(int u, int v, double w) { E[u].push_back(Edge(v, w)); }
bool vis[MAXN];  //在队列标志
int cnt[MAXN];   //每个点的入队列次数
double dist[MAXN];

bool SPFA(int start, int n) {
  memset(vis, false, sizeof(vis));
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; i++) dist[i] = 0;
  vis[start] = true;
  dist[start] = 100;
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
      if (dist[v] < dist[u] * E[u][i].cost) {
        dist[v] = dist[u] * E[u][i].cost;
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
  int Case = 1;
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    for (int i = 0; i < MAXN; i++) {
      E[i].clear();
    }
    map<string, int> name;
    for (int i = 1; i <= n; i++) {
      string str;
      cin >> str;
      name[str] = i;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
      string a, b;
      double x;
      cin >> a >> x >> b;
      addedge(name[a], name[b], x);
    }
    cout << "Case " << Case++ << ": ";
    if (!SPFA(1, n)) {
      cout << "Yes";
    } else {
      cout << "No";
    }
    cout << endl;
  }
  return 0;
}

// SPFA 判断正环