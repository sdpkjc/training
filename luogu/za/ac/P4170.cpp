// P4170 [CQOI2007]涂色
// https://www.luogu.org/problem/P4170

#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
using namespace std;

const int MAX_N = 55;

int dp[MAX_N][MAX_N];

int main() {
  string str;
  cin >> str;
  str = " " + str;
  int n = str.length() - 1;
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    dp[i][i] = 1;
  }
  for (int Len = 2; Len <= n; Len++) {
    for (int l = 1; (l + Len - 1) <= n; l++) {
      int r = l + Len - 1;
      for (int i = l; i < r; i++) {
        dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r]);
      }
      if (str[l] == str[r]) {
        dp[l][r] = min(dp[l][r], dp[l + 1][r]);
        dp[l][r] = min(dp[l][r], dp[l][r - 1]);
      }
    }
  }
  cout << dp[1][n] << endl;
  return 0;
}
