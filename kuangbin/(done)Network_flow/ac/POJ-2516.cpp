// POJ-2516 Minimum Cost
// https://vjudge.net/problem/POJ-2516

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

const int XX = 60;
int nsp[XX][XX];
int rl[XX][XX];
int cb[XX][XX][XX];
int rcb[XX][XX];
int need[XX];
int support[XX];

int main() {
  while (true) {
    int N, M, K, ans = 0;
    scanf("%d%d%d", &N, &M, &K);
    if (N == 0 && M == 0 && K == 0) break;
    memset(need, 0, sizeof(need));
    memset(support, 0, sizeof(support));

    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= K; j++) {
        scanf("%d", &nsp[i][j]);
        need[j] += nsp[i][j];
      }
    }
    for (int i = 1; i <= M; i++) {
      for (int j = 1; j <= K; j++) {
        scanf("%d", &rl[i][j]);
        support[j] += rl[i][j];
      }
    }
    bool re = true;
    for (int i = 1; i <= K; i++) {
      if (need[i] > support[i]) {
        re = false;
        break;
      }
    }
    for (int k = 1; k <= K; k++) {
      for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
          scanf("%d", &cb[k][i][j]);
        }
      }
    }
    //--------------------------
    if (re) {
      for (int k = 1; k <= K; k++) {
        int S = 0, T = N + M + 1;
        init(T + 10);
        for (int i = 1; i <= N; i++) {
          addedge(i, T, nsp[i][k], 0);
        }
        for (int i = 1; i <= M; i++) {
          addedge(S, i + N, rl[i][k], 0);
        }
        for (int i = 1; i <= N; i++) {
          for (int j = 1; j <= M; j++) {
            addedge(j + N, i, INF, cb[k][i][j]);
          }
        }
        int cost = 0;
        int flow = minCostMaxflow(S, T, cost);
        ans += cost;
      }
      printf("%d\n", ans);
    } else {
      printf("-1\n");
    }
  }
  return 0;
}

// 我的天呐，阅读困难，数据好多啊啊啊啊
// 每种商品分开跑最小费用最大流