// POJ-1679 The Unique MST
// https://vjudge.net/problem/POJ-1679

#include <string.h>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

const int MAXN = 110;
const int INF = 0x3f3f3f3f;
bool vis[MAXN];
int lowc[MAXN];
int pre[MAXN];
int Max[MAXN][MAXN];
// Max[i][j] 表示在最小生成树中从 i 到 j 的路径中的最大边权
bool used[MAXN][MAXN];
int Prim(int cost[][MAXN], int n) {
  int ans = 0;
  memset(vis, false, sizeof(vis));
  memset(Max, 0, sizeof(Max));
  memset(used, false, sizeof(used));
  vis[0] = true;
  pre[0] = -1;
  for (int i = 1; i < n; i++) {
    lowc[i] = cost[0][i];
    pre[i] = 0;
  }
  lowc[0] = 0;
  for (int i = 1; i < n; i++) {
    int minc = INF;
    int p = -1;

    for (int j = 0; j < n; j++)
      if (!vis[j] && minc > lowc[j]) {
        minc = lowc[j];
        p = j;
      }
    if (minc == INF) return -1;
    ans += minc;
    vis[p] = true;
    used[p][pre[p]] = used[pre[p]][p] = true;
    for (int j = 0; j < n; j++) {
      if (vis[j] && j != p)
        Max[j][p] = Max[p][j] = max(Max[j][pre[p]], lowc[p]);
      if (!vis[j] && lowc[j] > cost[p][j]) {
        lowc[j] = cost[p][j];
        pre[j] = p;
      }
    }
  }
  return ans;
}

int smst(int cost[][MAXN],int n,int ans)
{
    int Min=INF;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(cost[i][j]!=INF && !used[i][j])
            {
                Min=min(Min,ans+cost[i][j]-Max[i][j]);
            }
    if(Min==INF)return -1;//不存在
    return Min;
}

int costx[MAXN][MAXN];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    memset(costx, 0x3f, sizeof(costx));
    int n, m;
    scanf("%d%d", &n, &m);
    int sum = 0;
    for (int i = 0; i < n; i++) costx[i][i] = 0;
    for (int i = 0; i < m; i++) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      a--;
      b--;
      costx[a][b] = c;
      costx[b][a] = c;
    }
    int ans = Prim(costx, n);
    int ansMST = smst(costx, n,ans);

    if (ans == ansMST) {
      printf("Not Unique!\n");
    } else {
      printf("%d\n", ans);
    }
  }
  return 0;
}

// 次小生成树，不知道为什么最小生成树计数不行
// kuangbin 题解：https://www.cnblogs.com/kuangbin/p/3147329.html