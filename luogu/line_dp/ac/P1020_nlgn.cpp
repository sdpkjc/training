// P1020 导弹拦截 nlgn
// https://www.luogu.org/problemnew/show/P1020

#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int a[100005];
int dp[100005];
int dpb[100005];

int n;
bool com(int a, int b) { return a > b; }
int LIS_nlgn() {
  int len = 1;
  dp[1] = a[1];
  for (int i = 2; i <= n; ++i) {
    if (dp[len] >= a[i]) {
      dp[++len] = a[i];
    } else {
      int pos = upper_bound(dp + 1, dp + len, a[i], com) - dp;
      dp[pos] = a[i];
    }
  }
  return len;
}
int bLIS_nlgn() {
  int len = 1;
  dpb[1] = a[1];
  for (int i = 2; i <= n; ++i) {
    if (dpb[len] < a[i]) {
      dpb[++len] = a[i];
    } else {
      int pos = lower_bound(dpb + 1, dpb + len, a[i]) - dpb;
      dpb[pos] = a[i];
    }
  }
  return len;
}

int main() {
  n = 0;
  while (~scanf("%d", &a[++n])) {
  }
  n--;

  int ans1 = LIS_nlgn();
  printf("%d\n", ans1);
  int ans2 = bLIS_nlgn();
  printf("%d\n", ans2);

  return 0;
}

// 最长上升子序列
// 先求 最长不上升子序列 3 2 2 1
// 再求 最长上升子序    1 2 3 4
// Dilworth定理：偏序集的最少反链划分数等于最长链的长度