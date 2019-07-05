// P1508 Likecloud-吃、吃、吃
// https://www.luogu.org/problemnew/show/P1508

#include <algorithm>
#include <cstdio>
using namespace std;

int dp[300][300];
int sc[300][300];
int main() {
  int n, m;
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &sc[i][j]);
    }
  }

  for (int i = 1; i <= m + 1; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] =
          max(dp[i - 1][j], max(dp[i - 1][j - 1], dp[i - 1][j + 1])) + sc[i][j];
    }
  }

  printf("%d\n", dp[m + 1][n / 2 + 1]);

  return 0;
}

// 水