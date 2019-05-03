// P1265 公路修建
// https://www.luogu.org/problemnew/show/P1265

#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 5005;
bool vis[MAXN];
double lowc[MAXN];
//点是 0 n-1
double len(double x, double y, double xx, double yy) {
  return sqrt((xx - x) * (xx - x) + (yy - y) * (yy - y));
}

double xp[MAXN];
double yp[MAXN];
double Prim(int n) {
  double ans = 0;
  memset(vis, false, sizeof(vis));
  vis[0] = true;
  for (int i = 1; i < n; i++) {
    lowc[i] = len(xp[0], yp[0], xp[i], yp[i]);
  }
  for (int i = 1; i < n; i++) {
    double minc = INF;
    int p = -1;
    for (int j = 0; j < n; j++)
      if (!vis[j] && minc > lowc[j]) {
        minc = lowc[j];
        p = j;
      }
    if (minc == INF) return -1;  //原图不连通
    ans += minc;
    vis[p] = true;
    for (int j = 0; j < n; j++) {
      if (!vis[j] && lowc[j] > len(xp[p], yp[p], xp[j], yp[j]))
        lowc[j] = len(xp[p], yp[p], xp[j], yp[j]);
    }
  }
  return ans;
}

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%lf%lf", &xp[i], &yp[i]);
  }

  double ans = Prim(n);
  //   ans = vd[vd.size() - s];
  printf("%.2f\n", ans);

  return 0;
}

// Prim 算法实时计算边长