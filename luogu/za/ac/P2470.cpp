// P2470 [SCOI2007]压缩
// https://www.luogu.org/problem/P2470

#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
using namespace std;

const int MAX_N = 55;

int dp[MAX_N][MAX_N][3];

bool check(string s) {
  for (int i = 0; i < s.length() / 2; i++) {
    if (s[i] != s[i + s.length() / 2]) return false;
  }
  return true;
}

int main() {
  string str;
  cin >> str;
  str = " " + str;
  int n = str.length() - 1;
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    dp[i][i][0] = dp[i][i][1] = 1;
  }
  for (int Len = 2; Len <= n; Len++) {
    for (int l = 1; (l + Len - 1) <= n; l++) {
      int r = l + Len - 1;
      for (int k = l; k <= r; k++) {
        dp[l][r][0] = min(dp[l][r][0], dp[l][k][0] + r - k);
      }
      if (Len % 2 == 0 && check(str.substr(l, Len))) {
        dp[l][r][0] = min(dp[l][r][0], dp[l][r - Len / 2][0] + 1);
      }
      dp[l][r][1] = dp[l][r][0];
      for (int k = l; k <= r; k++) {
        dp[l][r][1] = min(dp[l][r][1], dp[l][k][1] + dp[k + 1][r][1] + 1);
      }
    }
  }
  cout << dp[1][n][1] << endl;
  return 0;
}

// dp[l][r][0/1] 表示[l,r]区间 没有M 或 可以有M 时的最小长度