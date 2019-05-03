// ***_TLE_***
// POJ-3159 Candies
// https://vjudge.net/problem/POJ-3159

#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 30005;
const int INF = 0x3f3f3f3f;

int Scan() {  //输入外挂
  int res = 0, flag = 0;
  char ch;
  if ((ch = getchar()) == '-')
    flag = 1;
  else if (ch >= '0' && ch <= '9')
    res = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9') res = res * 10 + (ch - '0');
  return flag ? -res : res;
}

void Out(int a) {  //输出外挂
  if (a < 0) {
    putchar('-');
    a = -a;
  }
  if (a >= 10) Out(a / 10);
  putchar(a % 10 + '0');
}

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
  int n, m;

  n = Scan();
  m = Scan();
  // scanf("%d%d", &n, &m);

  for (int i = 0; i < m; i++) {
    int a, b, c;
    a = Scan();
    b = Scan();
    c = Scan();
    // scanf("%d%d%d", &a, &b, &c);

    addedge(a, b, c);
  }
  SPFA(1, n);
  Out(dist[n]);
  // printf("%d\n", dist[n]);
}

// SPFA输入输出挂依然 TLE，卡SPFA。。。