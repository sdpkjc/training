// P2330 [SCOI2005]繁忙的都市
// https://www.luogu.org/problemnew/show/P2330

#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 310;     //最大点数
const int MAXM = 100005;  //最大边数
int F[MAXN];              //并查集使用
struct Edge {
  int u, v, w;
} edge[MAXM];  //存储边的信息，包括起点/终点/权值
int tol;       //边数，加边前赋值为 0
void addedge(int u, int v, int w) {
  edge[tol].u = u;
  edge[tol].v = v;
  edge[tol++].w = w;
}  //排序函数，讲边按照权值从小到大排序
bool cmp(Edge a, Edge b) { return a.w < b.w; }
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
      ans = max(ans, w);
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
  int n, m;
  scanf("%d%d", &n, &m);
  tol = 0;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    addedge(a, b, c);
  }
  int ans = Kruskal(n);
  printf("%d %d\n", n - 1, ans);
}

// 一棵最小生成树必定是一棵最小瓶颈生成树