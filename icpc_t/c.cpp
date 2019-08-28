#include <string.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int arr[105];
int dp[105][105][105];
int main() {
  int n, l, r;
  while (cin >> n >> l >> r) {
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
      dp[i][i][1] = 0;
      arr[i] += arr[i - 1];
    }
    for (int len = 2; len <= n; len++) {
      for (int i = 1; i + len - 1 <= n; i++) {
        int j = i + len - 1;
        for (int k = 2; k <= min(len, r); k++) {
          for (int c = i + k - 2; c < j; c++) {
            dp[i][j][k] = min(dp[i][j][k], dp[i][c][k - 1] + dp[c + 1][j][1]);
          }
        }

        for (int k = l - 1; k <= r - 1; k++) {
          for (int c = i + k - 1; c < j; c++) {
            dp[i][j][1] = min(dp[i][j][1], dp[i][c][k] + dp[c + 1][j][1] +
                                               arr[j] - arr[i - 1]);
          }
        }
      }
    }
    if (dp[1][n][1] != 0x3f3f3f3f)
      cout << dp[1][n][1] << endl;
    else
      cout << 0 << endl;
  }

  return 0;
}