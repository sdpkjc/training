// P1280 尼克的任务
// https://www.luogu.org/problemnew/show/P1280

#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 10005;
int n, k;
vector<int> G[MAXN];
int dp[MAXN];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    G[a].push_back(b);
  }
  for (int i = n; i >= 1; i--) {
    if (G[i].size() == 0)
      dp[i] = dp[i + 1] + 1;
    else {
      for (int j = 0; j < G[i].size(); j++) {
        dp[i] = max(dp[i], dp[i + G[i][j]]);
      }
    }
  }
  printf("%d\n", dp[1]);
  return 0;
}

// dp[i] 为 i -> n 的最大空闲时间
// 反向dp