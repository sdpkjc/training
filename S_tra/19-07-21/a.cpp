#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
char matrix[1000][1000];
int dp[1000][1000];
int n, m;
int maximalSquare() {
  int res = 0;
  for (int i = 0; i < m; i++) {
    if (matrix[i][0] == '1') {
      dp[i][0] = 1;
      res = 1;
    }
  }
  for (int j = 0; j < n; j++) {
    if (matrix[0][j] == '1') {
      dp[0][j] = 1;
      res = 1;
    }
  }
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      if (matrix[i][j] == '1') {
        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        res = max(dp[i][j], res);
      }
    }
  }
  return res * res;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        dp[i][j] = 0;
        char t;
        cin >> t;
        if (t == '*') {
          matrix[i][j] = '0';
        } else {
          matrix[i][j] = '1';
        }
      }
    }
    cout << maximalSquare() << endl;
  }
  return 0;
}
