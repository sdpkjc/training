#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

signed main() {
  int n, k;
  cin >> n >> k;
  string str;
  cin >> str;
  set<string> SET;
  SET.insert(str);
  int ans = 0;
  if (k == SET.size()) {
    cout << ans << endl;
  } else {
    for (int i = 0; i < str.length(); i++) {
      SET.insert(str.substr(i, 1));
      ans++;
      if (k == SET.size()) {
        cout << ans << endl;
        break;
      }
    }
    while (k == SET.size()) {
    }
  }

  return 0;
}