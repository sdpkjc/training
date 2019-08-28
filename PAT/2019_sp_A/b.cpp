#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int main() {
  map<string, int> M;
  map<string, int> Mlb;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string t;
    cin >> t;
    M[t]++;
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    string t;
    cin >> t;
    M[t]++;
    Mlb[t]++;
  }
  int cnt = 0;
  string x = "99999999";
  string ans = "";
  for (auto it = M.begin(); it != M.end(); it++) {
    if (it->second > 1) {
      cnt++;
      string tt = it->first.substr(6, 8);
      if (tt < x) {
        x = tt;
        ans = it->first;
      }
    }
  }
  if (cnt == 0) {
    string xx = "99999999";
    string xans = "";
    for (auto it = Mlb.begin(); it != Mlb.end(); it++) {
      string tt = it->first.substr(6, 8);
      if (tt < xx) {
        xx = tt;
        xans = it->first;
      }
    }
    cout << 0 << endl;
    cout << xans << endl;
  } else {
    cout << cnt << endl;
    cout << ans << endl;
  }

  return 0;
}