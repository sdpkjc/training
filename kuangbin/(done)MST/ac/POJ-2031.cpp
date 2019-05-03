// POJ-2031 Building a Space Station
// https://vjudge.net/problem/POJ-2031

#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

const int MAXN = 110;    //最大点数
const int MAXM = 10000;  //最大边数
int F[MAXN];             //并查集使用
struct Edge {
  int u, v;
  double w;
} edge[MAXM];  //存储边的信息，包括起点/终点/权值
int tol;       //边数，加边前赋值为 0
void addedge(int u, int v, double w) {
  edge[tol].u = u;
  edge[tol].v = v;
  edge[tol++].w = w;
}
//排序函数，讲边按照权值从小到大排序
bool cmp(Edge a, Edge b) { return a.w < b.w; }
int find(int x) {
  if (F[x] == -1)
    return x;
  else
    return F[x] = find(F[x]);
}
//传入点数，返回最小生成树的权值，如果不连通返回 -1
double Kruskal(int n) {
  memset(F, -1, sizeof(F));
  sort(edge, edge + tol, cmp);
  int cnt = 0;  //计算加入的边数
  double ans = 0;
  for (int i = 0; i < tol; i++) {
    int u = edge[i].u;
    int v = edge[i].v;
    double w = edge[i].w;
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

double len(double x, double y, double z, double xx, double yy, double zz) {
  return sqrt((xx - x) * (xx - x) + (yy - y) * (yy - y) + (zz - z) * (zz - z));
}
double cirlen(double x, double y, double z, double r, double xx, double yy,
              double zz, double rr) {
  double ll = len(x, y, z, xx, yy, zz);
  if (ll - r - rr < 1e-5) {
    return 0;
  } else {
    return ll - r - rr;
  }
}
double xp[MAXN];
double yp[MAXN];
double zp[MAXN];
double rp[MAXN];

int main() {
  int n;
  while (~scanf("%d", &n)) {
    if (n == 0) break;
    tol = 0;
    for (int i = 0; i < n; i++) {
      scanf("%lf%lf%lf%lf", &xp[i], &yp[i], &zp[i], &rp[i]);
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        addedge(i, j,
                cirlen(xp[i], yp[i], zp[i], rp[i], xp[j], yp[j], zp[j], rp[j]));
      }
    }
    double ans = Kruskal(n);
    printf("%.3f\n", ans);
  }
  return 0;
}

// 浮点数的最小生成树，球之间的距离，距离小于零，就建一条权为 0 的边
// POJ尴尬精度 %f
