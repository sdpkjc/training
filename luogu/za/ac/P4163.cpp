// P4163 [SCOI2007]排列
// https://www.luogu.org/problem/P4163

#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long long dp[2000][2000];
int main() {
  int T;
  cin >> T;
  while (T--) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    string s;
    int d;
    long long ans = 0;
    cin >> s >> d;
    for (int i = 0; i < (1 << s.length()); i++) {
      for (int j = 0; j < d; j++) {
        for (int k = 0; k < s.length(); k++) {
          if (!(i & (1 << k))) {
            dp[(i | (1 << k))][(j * 10 + s[k] - '0') % d] += dp[i][j];
          }
        }
      }
    }
    ans = dp[(1 << s.length()) - 1][0];
    int cnt[10] = {0};
    for (int i = 0; i < s.length(); i++) {
      cnt[s[i] - '0']++;
    }
    for (int i = 0; i < 10; i++) {
      if (cnt[i] == 0) cnt[i] = 1;
      long long jc = 1;
      for (int j = 1; j <= cnt[i]; j++) {
        jc *= j;
      }
      ans /= jc;
    }
    cout << ans << endl;
  }
  return 0;
}