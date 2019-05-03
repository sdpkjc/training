// P1164 小A点菜
// https://www.luogu.org/problemnew/show/P1164

#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 200;
int V[MAXN];
int dp[20005];

int main() {
  memset(dp, 0, sizeof(dp));
  int T, M;
  scanf("%d%d", &M, &T);
  for (int i = 1; i <= M; i++) {
    scanf("%d", &V[i]);
  }
  dp[0] = 1;
  for (int i = 1; i <= M; i++) {
    for (int j = T; j >= V[i]; j--) {
      dp[j] = dp[j] + dp[j - V[i]];
    }
  }
  printf("%d\n", dp[T]);
  // dp[i][j] = dp[i - 1][j] + dp[i - 1][j - V[i]];
  return 0;
}

// 01背包，求装法总数