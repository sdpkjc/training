// POJ-1751 Highways
// https://vjudge.net/problem/POJ-1751

#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 1000;     //最大点数
const int MAXM = 1000000;  //最大边数
vector<int> vx;
vector<int> vy;

int F[MAXN];  //并查集使用
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
      if (w > 1e-5) {
        vx.push_back(u);
        vy.push_back(v);
      }

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

double len(double x, double y, double xx, double yy) {
  return sqrt((xx - x) * (xx - x) + (yy - y) * (yy - y));
}

double xp[MAXN];
double yp[MAXN];

int main() {
  int n;
  scanf("%d", &n);
  tol = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lf%lf", &xp[i], &yp[i]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      double xly = len(xp[i], yp[i], xp[j], yp[j]);
      addedge(i, j, xly * 100);
    }
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    addedge(a, b, 0);
  }
  double ans = Kruskal(n);

  for (int i = 0; i < vx.size(); i++) {
    printf("%d %d\n", vx[i], vy[i]);
  }

  return 0;
}

// 求最小生成树的边，加 0 权边