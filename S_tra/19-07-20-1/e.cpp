#include <algorithm>
#include <iostream>
using namespace std;

int dp[100005], a[100005], n;
int LIS_nlgn() {
  int len = 1;
  dp[1] = a[1];
  for (int i = 2; i <= n; ++i) {
    if (a[i] >= dp[len]) {
      dp[++len] = a[i];
    } else {
      int pos = upper_bound(dp, dp + len, a[i]) - dp;
      dp[pos] = a[i];
    }
  }
  return len;
}
int main() {
  cin >> n;
  for (int i = n; i >= 1; i--) {
    cin >> a[i];
  }
  cout << LIS_nlgn() << endl;
  return 0;
}