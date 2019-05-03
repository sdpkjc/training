// P1833 樱花
// https://www.luogu.org/problemnew/show/P1833

#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 10005;
int V[MAXN], W[MAXN], m[MAXN];
int dp[5005];

int main() {
  memset(dp, 0, sizeof(dp));
  int T, M;
  int ss, sf, es, ef;
  scanf("%d:%d %d:%d", &ss, &sf, &es, &ef);
  T = (es - ss) * 60 - sf + ef;
  //   printf("%d\n", T);
  scanf("%d", &M);
  for (int i = 1; i <= M; i++) {
    scanf("%d%d%d", &V[i], &W[i], &m[i]);
    if (m[i] == 0) m[i] = T / V[i] + 10;
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

// 混合背包，数据较弱，可以整合为多重背包