#include <string.h>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

long long w[100005], v[100005];
long long dp[100005];

int main() {
  int n, m;
  while (cin >> n >> m) {
    long long MAX = 0;
    for (int i = 1; i <= n; i++) {
      cin >> w[i] >> v[i];
      MAX = max(MAX, v[i]);
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0ll;

    for (int i = 1; i <= n; i++) {
      for (int j = v[i]; j <= m + MAX; j++) {
        dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
      }
    }
    long long cost = 0x3f3f3f3f3f3f3f3fll, L = 0ll;
    for (int i = m + MAX; i >= m; i--) {
      if (dp[i] < cost) {
        cost = dp[i];
        L = i;
      }
    }
    cout << cost << " " << L << endl;
  }

  return 0;
}