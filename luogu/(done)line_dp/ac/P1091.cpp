// P1091 合唱队形
// https://www.luogu.org/problemnew/show/P1091

#include <cstdio>
#include <iostream>
using namespace std;

int dp[105], dpb[105], a[105], n;

int LIS_nn() {
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i] = 1;
    for (int j = 1; j < i; ++j) {
      if (a[j] < a[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    ans = max(ans, dp[i]);
  }
  return ans;
}
int bLIS_nn() {
  int ans = 0;
  for (int i = n; i >= 1; --i) {
    dpb[i] = 1;
    for (int j = n; j > i; --j) {
      if (a[j] < a[i]) {
        dpb[i] = max(dpb[i], dpb[j] + 1);
      }
    }
    ans = max(ans, dpb[i]);
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  LIS_nn();
  bLIS_nn();
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    // printf("%d ", dpb[i]);
    ans = max(ans, dp[i] + dpb[i] - 1);
  }
  //   printf("\n");
  printf("%d\n", n - ans);
  return 0;
}

// 正反两次 LIS