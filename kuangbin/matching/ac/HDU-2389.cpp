// HDU-2389 Rain on your Parade
// https://vjudge.net/problem/HDU-2389

#include <string.h>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
const int MAXN = 10000;
const int INF = 0x3f3f3f3f;
vector<int> G[MAXN];
int uN;
int Mx[MAXN], My[MAXN];
int dx[MAXN], dy[MAXN];
int dis;
bool used[MAXN];
bool SearchP() {
  queue<int> Q;
  dis = INF;
  memset(dx, -1, sizeof(dx));
  memset(dy, -1, sizeof(dy));
  for (int i = 1; i <= uN; i++) {
    if (Mx[i] == -1) {
      Q.push(i);
      dx[i] = 0;
    }
  }
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    if (dx[u] > dis) break;
    int sz = G[u].size();
    for (int i = 0; i < sz; i++) {
      int v = G[u][i];
      if (dy[v] == -1) {
        dy[v] = dx[u] + 1;
        if (My[v] == -1) {
          dis = dy[v];
        } else {
          dx[My[v]] = dy[v] + 1;
          Q.push(My[v]);
        }
      }
    }
  }
  return dis != INF;
}

bool DFS(int u) {
  int sz = G[u].size();
  for (int i = 0; i < sz; i++) {
    int v = G[u][i];
    if (!used[v] && dy[v] == dx[u] + 1) {
      used[v] = true;
      if (!used[v] && dy[v] == dis) continue;
      if (My[v] == -1 || DFS(My[v])) {
        My[v] = u;
        Mx[u] = v;
        return true;
      }
    }
  }
  return false;
}

int MaxMatch() {
  int res = 0;
  memset(Mx, -1, sizeof(Mx));
  memset(My, -1, sizeof(My));
  while (SearchP()) {
    memset(used, false, sizeof(used));
    for (int i = 1; i <= uN; i++) {
      if (Mx[i] == -1 && DFS(i)) {
        res++;
      }
    }
  }
  return res;
}

double spe[MAXN], xp[MAXN], yp[MAXN];
double xs[MAXN], ys[MAXN];

bool connet(double x1, double y1, double x2, double y2, double t, double s) {
  double len = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
  if (len <= t * s) return true;
  return false;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int Case = 1; Case <= T; Case++) {
    // for (int i = 0; i < MAXN; i++) G[i].clear();
    printf("Scenario #%d:\n", Case);
    int t, m;
    int n;
    scanf("%d%d", &t, &m);  // m ren
    for (int i = 1; i <= m; i++) {
      scanf("%lf%lf%lf", &xp[i], &yp[i], &spe[i]);
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%lf%lf", &xs[i], &ys[i]);
    }
    uN = m;
    for (int i = 1; i <= m; i++) {
      G[i].clear();
      for (int j = 1; j <= n; j++) {
        if (connet(xp[i], yp[i], xs[j], ys[j], t, spe[i])) {
          G[i].push_back(j);
        }
      }
    }
    int ans = MaxMatch();
    printf("%d\n\n", ans);
  }
  return 0;
}

// dinic 和 hungary 都超时，KM 算法上场