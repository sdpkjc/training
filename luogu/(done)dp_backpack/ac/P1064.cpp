// P1064 金明的预算方案
// https://www.luogu.org/problemnew/show/P1064

#include <algorithm>
#include <cstdio>
using namespace std;

int V[100][5];
int W[100][5];
int dp[32005];

int main() {
  int N, m;
  scanf("%d%d", &N, &m);
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (c == 0) {
      V[i][0] = a;
      W[i][0] = a * b;
    } else {
      if (V[c][1] == 0) {
        V[c][1] = a;
        W[c][1] = a * b;
      } else {
        V[c][2] = a;
        W[c][2] = a * b;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = N; j >= 0; j--) {
      if (j >= V[i][0]) dp[j] = max(dp[j], dp[j - V[i][0]] + W[i][0]);
      if (j >= V[i][0] + V[i][1])
        dp[j] = max(dp[j], dp[j - V[i][0] - V[i][1]] + W[i][0] + W[i][1]);

      if (j >= V[i][0] + V[i][2])
        dp[j] = max(dp[j], dp[j - V[i][0] - V[i][2]] + W[i][0] + W[i][2]);

      if (j >= V[i][0] + V[i][1] + V[i][2])
        dp[j] = max(dp[j], dp[j - V[i][0] - V[i][1] - V[i][2]] + W[i][0] +
                               W[i][1] + W[i][2]);
    }
  }

  printf("%d\n", dp[N]);
  return 0;
}

// 有依赖的背包，分组背包，枚举分组