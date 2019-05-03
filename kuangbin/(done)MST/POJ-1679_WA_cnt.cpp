#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int mod = 31011;
int fa[108], tot = 0, cnt = 0, sum, ans = 1;
struct Edge {
  int u, v, w;
} e[11080];
struct Seg {
  int l, r, cont;
} s[11080];
bool cmp(const Edge &a, const Edge &b) { return a.w < b.w; }
int findx(int x) { return x == fa[x] ? x : findx(fa[x]); }  //普通版
int findy(int y) {
  return fa[y] = (y == fa[y] ? y : findy(fa[y]));
}  //压缩路径版
void dfs(int pos, int now, int k) {
  if (now == s[pos].r + 1) {
    if (k == s[pos].cont) ++sum;
    return;
  }
  int u = findx(e[now].u), v = findx(e[now].v);
  if (u != v) {
    fa[u] = v;
    dfs(pos, now + 1, k + 1);
    fa[u] = u;
    fa[v] = v;
  }
  dfs(pos, now + 1, k);
}

const int MAXN = 110;    //最大点数
const int MAXM = 10000;  //最大边数
int F[MAXN];             //并查集使用
Edge edge[MAXM];         //存储边的信息，包括起点/终点/权值
int tol;                 //边数，加边前赋值为 0
void addedge(int u, int v, int w) {
  edge[tol].u = u;
  edge[tol].v = v;
  edge[tol++].w = w;
}
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
    }
    if (cnt == n - 1) break;
  }
  if (cnt < n - 1)
    return -1;  //不连通
  else
    return ans;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    memset(s, 0, sizeof(s));
    tot = 0;
    cnt = 0;
    ans = 1;
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
      scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
      addedge(e[i].u, e[i].v, e[i].w);
    }
    for (int i = 1; i <= n; ++i) fa[i] = i;
    sort(e + 1, e + m + 1, cmp);
    for (int i = 1; i <= m; ++i) {
      if (e[i].w != e[i - 1].w) {
        s[++tot].l = i;
        s[tot - 1].r = i - 1;
      }
      int u = findy(e[i].u), v = findy(e[i].v);
      if (u != v) {
        fa[u] = v;
        ++s[tot].cont;
        ++cnt;
      }
    }
    s[tot].r = m;
    if (cnt != n - 1) {
      puts("0");
      return 0;
    }
    for (int i = 1; i <= n; ++i) fa[i] = i;
    for (int i = 1; i <= tot; ++i) {
      sum = 0;
      dfs(i, s[i].l, 0);
      ans = (ans * sum) % mod;
      for (int j = s[i].l; j <= s[i].r; ++j) {
        int u = findy(e[j].u), v = findy(e[j].v);
        fa[u] = v;
      }
    }
    if (ans == 1) {
      int x = Kruskal(n);
      printf("%d", n);
    } else {
      printf("Not Unique!");
    }
    printf("\n");
  }
}