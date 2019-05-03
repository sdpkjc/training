// POJ-2195 Going Home
// https://vjudge.net/problem/POJ-2195

#include <string.h>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

const int MAXN = 10000;
const int MAXM = 100000;
const int INF = 0x3f3f3f3f;
struct Edge {
  int to, next, cap, flow, cost;
} edge[MAXM];
int head[MAXN], tol;
int pre[MAXN], dis[MAXN];
bool vis[MAXN];
int N;  //节点总个数，节点编号从 0∼N-1
void init(int n) {
  N = n;
  tol = 0;
  memset(head, -1, sizeof(head));
}
void addedge(int u, int v, int cap, int cost) {
  edge[tol].to = v;
  edge[tol].cap = cap;
  edge[tol].cost = cost;
  edge[tol].flow = 0;
  edge[tol].next = head[u];
  head[u] = tol++;
  edge[tol].to = u;
  edge[tol].cap = 0;
  edge[tol].cost = -cost;
  edge[tol].flow = 0;
  edge[tol].next = head[v];
  head[v] = tol++;
}
bool spfa(int s, int t) {
  queue<int> q;
  for (int i = 0; i < N; i++) {
    dis[i] = INF;
    vis[i] = false;
    pre[i] = -1;
  }
  dis[s] = 0;
  vis[s] = true;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = false;
    for (int i = head[u]; i != -1; i = edge[i].next) {
      int v = edge[i].to;
      if (edge[i].cap > edge[i].flow && dis[v] > dis[u] + edge[i].cost) {
        dis[v] = dis[u] + edge[i].cost;
        pre[v] = i;
        if (!vis[v]) {
          vis[v] = true;
          q.push(v);
        }
      }
    }
  }
  if (pre[t] == -1)
    return false;
  else
    return true;
}
//返回的是最大流，cost 存的是最小费用
int minCostMaxflow(int s, int t, int &cost) {
  int flow = 0;
  cost = 0;
  while (spfa(s, t)) {
    int Min = INF;
    for (int i = pre[t]; i != -1; i = pre[edge[i ^ 1].to]) {
      if (Min > edge[i].cap - edge[i].flow) Min = edge[i].cap - edge[i].flow;
    }
    for (int i = pre[t]; i != -1; i = pre[edge[i ^ 1].to]) {
      edge[i].flow += Min;
      edge[i ^ 1].flow -= Min;
      cost += edge[i].cost * Min;
    }
    flow += Min;
  }
  return flow;
}

int n, m;
int mapx[200][200];
char chx[200][200];

int dirx[10] = {0, 1, 0, -1};
int diry[10] = {1, 0, -1, 0};

bool visq[200][200];
void bfs(int nn, int mm) {
  memset(visq, false, sizeof(vis));
  queue<pair<pair<int, int>, int> > Qx;
  Qx.push(make_pair(make_pair(nn, mm), 0));
  visq[nn][mm] = true;
  while (!Qx.empty()) {
    int nnn = Qx.front().first.first;
    int mmm = Qx.front().first.second;
    int we = Qx.front().second;
    Qx.pop();
    if (chx[nnn][mmm] == 'H') {
      addedge(mapx[nn][mm], mapx[nnn][mmm], 1, we);
    }
    for (int i = 0; i < 4; i++) {
      int tn = nnn + dirx[i];
      int tm = mmm + diry[i];
      int tw = we + 1;
      if (tn >= 1 && tm >= 1 && tn <= n && tm <= m && !visq[tn][tm]) {
        Qx.push(make_pair(make_pair(tn, tm), tw));
        visq[tn][tm] = true;
      }
    }
  }
}

int main() {
  while (true) {
    scanf("%d%d", &n, &m);
    if (n == 0 && m == 0) break;
    memset(chx, 0, sizeof(chx));
    memset(mapx, 0, sizeof(mapx));
    init(10000);
    int cnt = 1;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        char tmp;
        scanf(" %c", &tmp);
        chx[i][j] = tmp;
        if (tmp == '.')
          mapx[i][j] = 0;
        else if (tmp == 'm') {
          mapx[i][j] = cnt++;
        } else if (tmp == 'H') {
          mapx[i][j] = cnt++;
        }
      }
    }
    int S = 0, T = cnt + 10;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (chx[i][j] == 'm') {
          addedge(S, mapx[i][j], 1, 0);
          bfs(i, j);
        } else if (chx[i][j] == 'H') {
          addedge(mapx[i][j], T, 1, 0);
        }
      }
    }
    int cost = 0;
    int flow = minCostMaxflow(S, T, cost);
    printf("%d\n", cost);
  }

  return 0;
}

// BFS 建图最短路，跑 SPFA 最小费用最大流