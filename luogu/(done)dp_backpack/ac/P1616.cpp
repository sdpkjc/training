// P1616 疯狂的采药
// https://www.luogu.org/problemnew/show/P1616

#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 10005;
int V[MAXN], W[MAXN];
int dp[100005];

int main() {
  memset(dp, 0, sizeof(dp));
  int T, M;
  scanf("%d%d", &T, &M);
  for (int i = 1; i <= M; i++) {
    scanf("%d%d", &V[i], &W[i]);
  }
  for (int i = 1; i <= M; i++) {
    for (int j = V[i]; j <= T; j++) {
      dp[j] = max(dp[j], dp[j - V[i]] + W[i]);
    }
  }
  printf("%d\n", dp[T]);
  // dp[i][j] = dp[i - 1][j], dp[i - 1][j - V[i]] + W[i];
  return 0;
}

// 完全背包