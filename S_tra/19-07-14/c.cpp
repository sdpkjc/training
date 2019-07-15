#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int cs[30], ct[30], cp[30];
int dp[110][110];
int main() {
  int T;
  cin >> T;
  while (T--) {
    string s, t, p;
    cin >> s >> t >> p;
    memset(cs, 0, sizeof(cs));
    memset(ct, 0, sizeof(ct));
    memset(cp, 0, sizeof(cp));
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < s.length(); i++) {
      cs[s[i] - 'a']++;
    }
    for (int i = 0; i < t.length(); i++) {
      ct[t[i] - 'a']++;
    }
    for (int i = 0; i < p.length(); i++) {
      cp[p[i] - 'a']++;
    }
    bool flag = true;
    for (int i = 0; i < 30; i++) {
      if (cs[i] <= ct[i] && cs[i] + cp[i] >= ct[i]) {
      } else {
        flag = false;
      }
    }

    for (int i = 1; i <= s.length(); ++i) {
      for (int j = 1; j <= t.length(); ++j) {
        if (s[i - 1] == t[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    if (dp[s.length()][t.length()] != s.length()) {
      flag = false;
    }
    if (flag) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << endl;
  }
  return 0;
}