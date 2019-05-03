// P1776 宝物筛选
// https://www.luogu.org/problemnew/show/P1776

#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 200;
int V[MAXN], W[MAXN], m[MAXN];
int dp[50005];

int main() {
  memset(dp, 0, sizeof(dp));
  int T, M;
  scanf("%d%d", &M, &T);
  for (int i = 1; i <= M; i++) {
    scanf("%d%d%d", &W[i], &V[i], &m[i]);
  }
  for (int i = 1; i <= M; i++) {
    int tmp = m[i];
    for (int k = 1; k <= tmp; k *= 2) {
      for (int j = T; j >= V[i] * k; j--) {
        dp[j] = max(dp[j], dp[j - V[i] * k] + W[i] * k);
      }
      tmp -= k;
    }
    if (tmp > 0) {
      for (int j = T; j >= V[i] * tmp; j--) {
        dp[j] = max(dp[j], dp[j - V[i] * tmp] + W[i] * tmp);
      }
    }
  }
  printf("%d\n", dp[T]);
  return 0;
}

// 多重背包