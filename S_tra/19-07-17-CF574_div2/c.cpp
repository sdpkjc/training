#include <limits.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define int long long
int arrA[100005], arrB[100005];
int dp[100005][2][2];
signed main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arrA[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> arrB[i];
  }

  for (int i = 1; i <= n; i++) {
    dp[i][0][0] = max(dp[i][0][0], dp[i - 1][0][0]);
    dp[i][0][0] = max(dp[i][0][0], dp[i - 1][0][1]);
    dp[i][0][0] = max(dp[i][0][0], dp[i - 1][1][0]);
    dp[i][0][0] = max(dp[i][0][0], dp[i - 1][1][1]);
    dp[i][0][1] = max(dp[i][0][1], dp[i - 1][0][0] + arrA[i]);

    dp[i][0][1] = max(dp[i][0][1], dp[i - 1][1][1] + arrA[i]);
    // dp[i][0][1] = max(dp[i][0][1], dp[i - 1][0][1]);

    dp[i][1][0] = max(dp[i][1][0], dp[i - 1][1][0]);
    dp[i][1][0] = max(dp[i][1][0], dp[i - 1][1][1]);
    dp[i][1][0] = max(dp[i][1][0], dp[i - 1][0][0]);
    dp[i][1][0] = max(dp[i][1][0], dp[i - 1][0][1]);

    dp[i][1][1] = max(dp[i][1][1], dp[i - 1][1][0] + arrB[i]);

    dp[i][1][1] = max(dp[i][1][1], dp[i - 1][0][1] + arrB[i]);

    dp[i][0][0] = max(dp[i][0][0], dp[i][0][0]);
    dp[i][0][0] = max(dp[i][0][0], dp[i][1][1]);
    dp[i][1][0] = max(dp[i][1][0], dp[i][1][0]);
    dp[i][1][0] = max(dp[i][1][0], dp[i][0][1]);
  }

  cout << max(max(dp[n][0][0], dp[n][0][1]), max(dp[n][1][0], dp[n][1][1]))
       << endl;
  return 0;
}