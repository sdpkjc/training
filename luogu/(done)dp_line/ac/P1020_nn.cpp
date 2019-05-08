// P1020 导弹拦截 nn
// https://www.luogu.org/problemnew/show/P1020

#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int a[100005];
int dp[100005];
int dpb[100005];

int n;

int LIS_nn() {
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i] = 1;
    for (int j = 1; j < i; ++j) {
      if (a[j] >= a[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    ans = max(ans, dp[i]);
  }
  return ans;
}
int bLIS_nn() {
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    dpb[i] = 1;
    for (int j = 1; j < i; ++j) {
      if (a[j] < a[i]) {
        dpb[i] = max(dpb[i], dpb[j] + 1);
      }
    }
    ans = max(ans, dpb[i]);
  }
  return ans;
}
int main() {
  n = 0;
  while (~scanf("%d", &a[++n])) {
  }
  n--;

  int ans1 = LIS_nn();
  printf("%d\n", ans1);
  int ans2 = bLIS_nn();
  printf("%d\n", ans2);

  return 0;
}

// 最长上升子序列
// 先求 最长不上升子序列 3 2 2 1
// 再求 最长上升子序    1 2 3 4
// Dilworth定理：偏序集的最少反链划分数等于最长链的长度