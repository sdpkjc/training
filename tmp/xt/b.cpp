// Building Shops
// https://vjudge.net/contest/300475#problem/B

#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

#define int long long

const int INF = 0x3f3f3f3f3f3f3f3f;

struct classr {
  int x, c, i;
  bool operator<(const classr& t) const { return x < t.x; }
} arr[4000];

int dp[4000][3];
int sumx[4000][4000];
signed main() {
  int n;
  while (~scanf("%lld", &n)) {
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++) {
      scanf("%lld%lld", &arr[i].x, &arr[i].c);
      arr[i].i = i;
    }
    sort(arr + 1, arr + n + 1);

    for (int i = 1; i <= n; i++) {
      sumx[i][i] = 0;
      for (int j = 2; j <= n; j++) {
        sumx[i][j] = sumx[i][j - 1] + (arr[j].x - arr[i].x);
      }
    }
    dp[1][1] = arr[1].c;
    dp[1][0] = INF;
    for (int i = 2; i <= n; i++) {
      dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]) + arr[i].c;
      for (int j = i - 1; j >= 1; j--) {
        int sum = sumx[j][i - 1] - sumx[j][j];
        dp[i][0] = min(dp[i][0], dp[j][1] + arr[i].x - arr[j].x + sum);
      }
    }

    int ans = min(dp[n][0], dp[n][1]);
    printf("%lld\n", ans);
  }

  return 0;
}