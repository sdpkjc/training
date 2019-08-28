// P3205 [HNOI2010]合唱队
// https://www.luogu.org/problem/P3205

#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
using namespace std;

const int MAX_N = 1005;
const int MOD = 19650827;

int dp[MAX_N][MAX_N][3];
int arr[MAX_N];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  //   memset(dp, 0x3f, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    dp[i][i][0] = 1;
  }
  for (int Len = 2; Len <= n; Len++) {
    for (int l = 1; (l + Len - 1) <= n; l++) {
      int r = l + Len - 1;
      dp[l][r][0] = (dp[l + 1][r][0] * (arr[l] < arr[l + 1]) +
                     dp[l + 1][r][1] * (arr[l] < arr[r])) %
                    MOD;
      dp[l][r][1] = (dp[l][r - 1][0] * (arr[r] > arr[l]) +
                     dp[l][r - 1][1] * (arr[r] > arr[r - 1])) %
                    MOD;
    }
  }
  cout << (dp[1][n][0] + dp[1][n][1]) % MOD << endl;
  return 0;
}

// 注意初始化