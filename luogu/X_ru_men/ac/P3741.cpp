// P3741 honoka的键盘
// https://www.luogu.org/problem/P3741

#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i <= s.length(); i++) {
    string t = s;
    int cnt = 0;
    if (i != s.length()) {
      if (t[i] == 'V')
        t[i] = 'K';
      else
        t[i] = 'V';
    }
    for (int j = 0; j < t.length() - 1; j++) {
      if (t[j] == 'V' && t[j + 1] == 'K') {
        cnt++;
      }
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}