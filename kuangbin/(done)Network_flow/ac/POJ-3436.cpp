// POJ-3436 ACM Computer Factory
// https://vjudge.net/problem/POJ-3436

#include <string.h>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 100010;  //点数的最大值
const int MAXM = 400010;  //边数的最大值
const int INF = 0x3f3f3f3f;
struct Edge {
  int to, next, cap, flow;
} edge[MAXM];  //注意是 MAXM
vector<pair<int, Edge> > backup;
int tol;
int head[MAXN];
int gap[MAXN], dep[MAXN], pre[MAXN], cur[MAXN];
void init() {
  tol = 0;
  memset(head, -1, sizeof(head));
}  //加边，单向图三个参数，双向图四个参数
void addedge(int u, int v, int w, int rw = 0) {
  edge[tol].to = v;
  edge[tol].cap = w;
  edge[tol].next = head[u];

  edge[tol].flow = 0;
  head[u] = tol++;

  edge[tol].to = u;
  edge[tol].cap = rw;
  edge[tol].next = head[v];

  edge[tol].flow = 0;
  head[v] = tol++;
}
//输入参数：起点、终点、点的总数
//点的编号没有影响，只要输入点的总数
int sap(int start, int end, int N) {
  memset(gap, 0, sizeof(gap));
  memset(dep, 0, sizeof(dep));
  memcpy(cur, head, sizeof(head));
  int u = start;
  pre[u] = -1;
  gap[0] = N;
  int ans = 0;
  while (dep[start] < N) {
    if (u == end) {
      int Min = INF;
      for (int i = pre[u]; i != -1; i = pre[edge[i ^ 1].to])
        if (Min > edge[i].cap - edge[i].flow) Min = edge[i].cap - edge[i].flow;
      for (int i = pre[u]; i != -1; i = pre[edge[i ^ 1].to]) {
        edge[i].flow += Min;
        edge[i ^ 1].flow -= Min;
      }
      u = start;
      ans += Min;
      continue;
    }
    bool flag = false;
    int v;
    for (int i = cur[u]; i != -1; i = edge[i].next) {
      v = edge[i].to;
      if (edge[i].cap - edge[i].flow && dep[v] + 1 == dep[u]) {
        flag = true;
        cur[u] = pre[v] = i;
        break;
      }
    }
    if (flag) {
      u = v;
      continue;
    }
    int Min = N;
    for (int i = head[u]; i != -1; i = edge[i].next)
      if (edge[i].cap - edge[i].flow && dep[edge[i].to] < Min) {
        Min = dep[edge[i].to];
        cur[u] = i;
      }
    gap[dep[u]]--;
    if (!gap[dep[u]]) return ans;
    dep[u] = Min + 1;
    gap[dep[u]]++;
    if (u != start) u = edge[pre[u] ^ 1].to;
  }
  return ans;
}
int P, N;
struct node {
  int in[20];
  int w;
} da[200];

bool ok(int a, int b) {
  for (int i = 1; i <= P; i++) {
    if (da[a].in[i] + da[b].in[i] == 1) {
      return false;
    }
  }
  return true;
}
bool check_s(int i) {
  for (int k = 1; k <= P; ++k) {
    if (da[i].in[k] == 1) return false;
  }
  return true;
}
bool check_tt(int i) {
  for (int k = 1; k <= P; ++k) {
    if (da[i].in[k] == 0) return false;
  }
  return true;
}
int main() {
  while (~scanf("%d%d", &P, &N)) {
    init();
    backup.clear();
    memset(da, 0, sizeof(da));
    int S = 0, T = 2 * N + 10;
    // 1->N,N+1->2N
    for (int i = 1; i <= N; i++) {
      scanf("%d", &da[i].w);
      for (int j = 1; j <= P; j++) {
        scanf("%d", &da[i].in[j]);
      }
      for (int j = 1; j <= P; j++) {
        scanf("%d", &da[i + N].in[j]);
      }
      addedge(i, i + N, da[i].w);
      if (check_s(i)) addedge(S, i, INF);
      if (check_tt(i + N)) addedge(i + N, T, INF);
    }
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (i == j) continue;
        if (ok(i + N, j)) {
          addedge(i + N, j, INF);
        }
      }
    }
    int ans = sap(S, T, T + 10);
    printf("%d", ans);
    int sum = 0;
    for (int u = N + 1; u <= (N << 1); ++u) {
      for (int i = head[u]; i != -1; i = edge[i].next) {
        Edge& e = edge[i];
        int v = e.to;
        if (v != u - N && v != T && e.flow > 0) {
          sum++;
          Edge tmp;
          tmp.to = v;
          tmp.flow = e.flow;
          backup.push_back(make_pair(u - N, tmp));
        }
      }
    }
    printf(" %d\n", sum);
    for (int i = 0; i < backup.size(); i++) {
      printf("%d %d %d\n", backup[i].first, backup[i].second.to,
             backup[i].second.flow);
    }
  }

  return 0;
}

// 题面难懂，迷之bug
// 拆点，输出边集