// P1967 货车运输
// https://www.luogu.org/problem/P1967

#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX_N = 100005;
const int MAX_M = 1000005;
int find(int x);
struct edge {
  int v, next, w;
} E[MAX_M];
int p[MAX_N], eid;

void init() {
  memset(p, -1, sizeof(p));
  eid = 0;
}

void insert(int u, int v, int w) {
  E[eid].v = v;
  E[eid].next = p[u];
  E[eid].w = w;
  p[u] = eid++;
}

int d[MAX_N], fa[MAX_N][21], w[MAX_N][21];

void dfs(int u) {
  for (int i = p[u]; i + 1; i = E[i].next) {
    if (d[E[i].v] == -1) {
      d[E[i].v] = d[u] + 1;
      fa[E[i].v][0] = u;
      w[E[i].v][0] = E[i].w;
      dfs(E[i].v);
    }
  }
}
int lca(int x, int y) {
  if (find(x) != find(y)) return -1;
  int re = 0x3f3f3f3f;
  if (d[x] > d[y]) {
    swap(x, y);
  }

  for (int j = 20; j >= 0; j--) {
    if (d[fa[y][j]] >= d[x]) {
      re = min(re, w[y][j]);
      y = fa[y][j];
    }
  }
  if (x == y) {
    return re;
  }
  for (int j = 20; j >= 0; j--) {
    if (fa[x][j] != fa[y][j]) {
      re = min(re, w[x][j]);
      re = min(re, w[y][j]);
      x = fa[x][j];
      y = fa[y][j];
    }
  }
  re = min(re, w[x][0]);
  re = min(re, w[y][0]);
  return re;
}

const int MAXN = 100005;   //最大点数
const int MAXM = 1000005;  //最大边数
int F[MAXN];               //并查集使用
struct Edge {
  int u, v, w;
} edge[MAXM];  //存储边的信息，包括起点/终点/权值
int tol;       //边数，加边前赋值为 0
void addedge(int u, int v, int w) {
  edge[tol].u = u;
  edge[tol].v = v;
  edge[tol++].w = w;
}  //排序函数，讲边按照权值从小到大排序
bool cmp(Edge a, Edge b) { return a.w > b.w; }
int find(int x) {
  if (F[x] == -1)
    return x;
  else
    return F[x] = find(F[x]);
}  //传入点数，返回最小生成树的权值，如果不连通返回 -1
int Kruskal(int n) {
  memset(F, -1, sizeof(F));
  sort(edge, edge + tol, cmp);
  int cnt = 0;  //计算加入的边数

  int ans = 0;
  for (int i = 0; i < tol; i++) {
    int u = edge[i].u;
    int v = edge[i].v;
    int w = edge[i].w;
    int t1 = find(u);
    int t2 = find(v);
    if (t1 != t2) {
      ans += w;
      F[t1] = t2;
      cnt++;
      insert(u, v, w);
      insert(v, u, w);
    }
    if (cnt == n - 1) break;
  }
  if (cnt < n - 1)
    return -1;  //不连通
  else
    return ans;
}

int main() {
  int n, m;
  init();
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    addedge(u, v, w);
    addedge(v, u, w);
  }
  Kruskal(n);
  memset(d, -1, sizeof(d));
  for (int i = 1; i <= n; i++) {
    if (d[i] == -1) {
      d[i] = 1;
      dfs(i);
      fa[i][0] = i;
      w[i][0] = 0x3f3f3f3f;
    }
  }
  for (int level = 1; level <= 20; level++) {
    for (int i = 1; i <= n; i++) {
      fa[i][level] = fa[fa[i][level - 1]][level - 1];
      w[i][level] = min(w[i][level - 1], w[fa[i][level - 1]][level - 1]);
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << lca(a, b) << endl;
  }

  return 0;
}