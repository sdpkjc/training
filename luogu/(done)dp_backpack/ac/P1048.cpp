// P1048 采药
// https://www.luogu.org/problemnew/show/P1048

#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 200;
int V[MAXN], W[MAXN];
int dp[MAXN][2005];

int main() {
  memset(dp, 0, sizeof(dp));
  int T, M;
  scanf("%d%d", &T, &M);
  for (int i = 1; i <= M; i++) {
    scanf("%d%d", &V[i], &W[i]);
  }
  for (int i = 1; i <= M; i++) {
    for (int j = 0; j <= T; j++) {
      if (j < V[i])
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - V[i]] + W[i]);
    }
  }
  printf("%d\n", dp[M][T]);
  // dp[i][j] = dp[i - 1][j], dp[i - 1][j - V[i]] + W[i];
  return 0;
}

// 01背包，未优化