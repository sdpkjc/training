// P1220 关路灯
// https://www.luogu.org/problem/P1220

#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
using namespace std;

const int MAX_N = 55;

int n, s;
int dp[MAX_N][MAX_N][3];
int sum[MAX_N];
int pos[MAX_N];
int main() {
  cin >> n >> s;
  for (int i = 1; i <= n; i++) {
    cin >> pos[i] >> sum[i];
  }
  memset(dp, 0x3f, sizeof(dp));
  dp[s][s][0] = dp[s][s][1] = 0;
  for (int i = 1; i <= n; i++) {
    sum[i] += sum[i - 1];
  }

  for (int Len = 2; Len <= n; Len++) {
    for (int l = 1; (l + Len - 1) <= n; l++) {
      int r = l + Len - 1;
      dp[l][r][0] = min(
          dp[l + 1][r][0] + (sum[l] + sum[n] - sum[r]) * (pos[l + 1] - pos[l]),
          dp[l + 1][r][1] + (pos[r] - pos[l]) * (sum[l] + sum[n] - sum[r]));
      dp[l][r][1] =
          min(dp[l][r - 1][0] +
                  (pos[r] - pos[l]) * (sum[l - 1] + sum[n] - sum[r - 1]),
              dp[l][r - 1][1] +
                  (pos[r] - pos[r - 1]) * (sum[l - 1] + sum[n] - sum[r - 1]));
    }
  }
  cout << min(dp[1][n][0], dp[1][n][1]) << endl;
  return 0;
}

// dp[l][r][0/1] 表示关掉[l,r]区间的路灯最终走到最左(0)或最右边(1)最小消耗的电能
// dp[l][r][0] = min(dp[l+1][r][0] + P * T,dp[l+1][r][1] + P * T)
// dp[l][r][1] = min(dp[l+1][r][0] + P * T,dp[l+1][r][1] + P * T)