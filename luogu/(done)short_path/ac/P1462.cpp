// P1462 通往奥格瑞玛的道路
// https://www.luogu.org/problemnew/show/P1462

#include <string.h>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 10005;
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
int fj[MAXN];
int n, m, b;

bool SPFA(int start, int n, int mid) {
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
      if (dist[v] > dist[u] + E[u][i].cost && fj[v] <= mid) {
        dist[v] = dist[u] + E[u][i].cost;
        if (!vis[v]) {
          vis[v] = true;
          que.push(v);
          if (++cnt[v] > n) return false;
        }
      }
    }
  }
  return true;
}

bool work(int mid) {
  if (mid < fj[1]) {
    return 0;
  }
  SPFA(1, n, mid);
  return dist[n] < b;
}

int main() {
  scanf("%d%d%d", &n, &m, &b);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &fj[i]);
  }
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    addedge(a, b, c);
    addedge(b, a, c);
  }

  int l = 1, r = INF;
  if (!work(r)) {
    printf("AFK\n");
  } else {
    int c;
    int mid = (l + r) >> 1;
    while (l <= r) {  //终止条件
      c = work(mid);  //使用work函数来判断当前猜测的答案是否可行
      if (c) {        //如果可以的话
        r = mid - 1;  //改变右端点，看看再少一点是不是也可以
        mid = (l + r) >> 1;
      } else {
        l = mid + 1;  //当前答案不可行，需要增大答案
        mid = (l + r) >> 1;
      }
    }

    printf("%d\n", l);
  }
  return 0;
}

// 最短路 + 二分