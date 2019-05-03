// POJ-3159 Candies
// https://vjudge.net/problem/POJ-3159

#include <string.h>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

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
const int INF = 0x3f3f3f3f;
const int MAXN = 30005;

struct qnode {
  int v, c;
  qnode(int _v = 0, int _c = 0) : v(_v), c(_c){};
  bool operator<(const qnode &r) const { return c > r.c; }
};

struct Edge {
  int v, cost;
  Edge(int _v = 0, int _cost = 0) : v(_v), cost(_cost) {}
};
vector<Edge> E[MAXN];
bool vis[MAXN];
int dist[MAXN];

//点的编号从 1 开始

void Dijkstra(int n, int start) {
  memset(vis, false, sizeof(vis));
  for (int i = 1; i <= n; i++) dist[i] = INF;
  priority_queue<qnode> que;
  while (!que.empty()) que.pop();
  dist[start] = 0;
  que.push(qnode(start, 0));
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
  int n, m;
  n = Scan();
  m = Scan();
  //   scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    a = Scan();
    b = Scan();
    c = Scan();
    // scanf("%d%d%d", &a, &b, &c);
    addedge(a, b, c);
  }
  Dijkstra(n, 1);
  Out(dist[n]);
  // printf("%d\n", dist[n]);
}

// 伪装的差分约束系统（裸的最短路），输入输出TLE，上输入输出挂