// POJ-3026 Borg Maze
// https://vjudge.net/problem/POJ-3026

#include <string.h>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

const int MAXN = 1100;     //最大点数
const int MAXM = 1000000;  //最大边数
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

int mapx[MAXN][MAXN];

int dirx[10] = {0, 1, 0, -1};
int diry[10] = {1, 0, -1, 0};

int n, m;
void bfs(int x, int y) {
  bool vis[MAXN][MAXN];
  memset(vis, false, sizeof(vis));
  queue<pair<pair<int, int>, int> > Q;
  Q.push(make_pair(make_pair(x, y), 0));
  vis[x][y] = true;
  while (!Q.empty()) {
    int xt = Q.front().first.first;
    int yt = Q.front().first.second;
    int times = Q.front().second;
    Q.pop();
    if (mapx[x][y] != mapx[xt][yt] && mapx[xt][yt] != 0) {
      addedge(mapx[x][y], mapx[xt][yt], times);
    }
    for (int i = 0; i < 4; i++) {
      int tx = xt + dirx[i];
      int ty = yt + diry[i];

      if (tx >= 0 && ty >= 0 && tx < n && ty < m && !vis[tx][ty]) {
        if (mapx[tx][ty] != -1) {
          Q.push(make_pair(make_pair(tx, ty), times + 1));
          vis[tx][ty] = true;
        }
      }
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  char str[100];
  while (T--) {
    tol = 0;
    memset(mapx, -1, sizeof(mapx));
    int cnt = 0;
    scanf("%d%d", &n, &m);
    gets(str);
    for (int i = 0; i < m; i++) {
      gets(str);
      for (int j = 0; j < n; j++) {
        if (str[j] == 'A' || str[j] == 'S') {
          mapx[i][j] = ++cnt;
        } else if (str[j] == ' ') {
          mapx[i][j] = 0;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mapx[i][j] > 0) {
          bfs(i, j);
        }
      }
    }
    int ans = Kruskal(cnt);
    printf("%d\n", ans);
  }
  return 0;
}

// BFS + Kruskal
// 用无权图最短路权值加边
// 一开始 MAXN 和 MAXM 开小了，wa...wa...wa...