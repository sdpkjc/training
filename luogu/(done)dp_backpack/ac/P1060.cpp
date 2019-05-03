// P1060 开心的金明
// https://www.luogu.org/problemnew/show/P1060

#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 200;
int V[MAXN], W[MAXN];
int dp[30005];

int main() {
  memset(dp, 0, sizeof(dp));
  int T, M;
  scanf("%d%d", &T, &M);
  for (int i = 1; i <= M; i++) {
    scanf("%d%d", &V[i], &W[i]);
    W[i] *= V[i];  // xxx
  }
  for (int i = 1; i <= M; i++) {
    for (int j = T; j >= V[i]; j--) {
      dp[j] = max(dp[j], dp[j - V[i]] + W[i]);
    }
  }
  printf("%d\n", dp[T]);
  // dp[i][j] = dp[i - 1][j], dp[i - 1][j - V[i]] + W[i];
  return 0;
}

// 01背包，改一点点