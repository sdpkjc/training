// P1880 [NOI1995]石子合并
// https://www.luogu.org/problemnew/show/P1880

#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 400;
int n;
int dp[MAXN][MAXN];
int sum[MAXN];
int a[MAXN];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sum[i] = sum[i - 1] + a[i];
  }
  for (int i = n + 1; i <= n + n; i++) {
    a[i] = a[i - n];
    sum[i] = sum[i - 1] + a[i];
  }
  n += n;
  for (int len = 1; len <= n; len++) {
    for (int i = 1; i <= n - len + 1; i++) {
      for (int j = 1; j < len; j++) {
        dp[i][i + len - 1] =
            max(dp[i][i + len - 1], dp[i][i + j - 1] + dp[i + j][i + len - 1] +
                                        sum[i + len - 1] - sum[i - 1]);
      }
    }
  }
  int ans1 = 0;
  for (int i = 1; i <= n / 2; i++) {
    ans1 = max(ans1, dp[i][i + n / 2 - 1]);
  }

  memset(dp, 0x3f, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    dp[i][i] = 0;
  }
  for (int len = 1; len <= n; len++) {
    for (int i = 1; i <= n - len + 1; i++) {
      for (int j = 1; j < len; j++) {
        dp[i][i + len - 1] =
            min(dp[i][i + len - 1], dp[i][i + j - 1] + dp[i + j][i + len - 1] +
                                        sum[i + len - 1] - sum[i - 1]);
      }
    }
  }
  int ans2 = 0x3f3f3f3f;
  for (int i = 1; i <= n / 2; i++) {
    ans2 = min(ans2, dp[i][i + n / 2 - 1]);
  }
  printf("%d\n%d\n", ans2, ans1);
  return 0;
}

// 环状区间dp，复制成两段