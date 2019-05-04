// P1282 多米诺骨牌
// https://www.luogu.org/problemnew/show/P1282

#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 2005;
int n;
int a[MAXN];
int b[MAXN];
int dp[MAXN][MAXN * 6];

int main() {
  int sum = 0;

  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i], &b[i]);
    sum += a[i];
    sum += b[i];
  }
  memset(dp, 0x3f, sizeof(dp));
  dp[1][a[1]] = 0;
  dp[1][b[1]] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= sum; j++) {
      if (j >= a[i]) dp[i][j] = min(dp[i][j], dp[i - 1][j - a[i]]);
      if (j >= b[i]) dp[i][j] = min(dp[i][j], dp[i - 1][j - b[i]] + 1);
    }
  }
  int mind = 0x3f3f3f3f;
  for (int i = 0; i <= sum; i++) {
    if (dp[n][i] != 0x3f3f3f3f) {
      mind = min(mind, abs(i - (sum - i)));
    }
  }
  int ans = 0x3f3f3f3f;
  for (int i = 0; i <= sum; i++) {
    if (mind == abs(i - (sum - i))) {
      if (dp[n][i] != 0x3f3f3f3f) {
        ans = min(ans, dp[n][i]);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}

// 不太好想，dp[i][j] -> 前 i 个骰子，上下差 j 个点数需要旋转的次数