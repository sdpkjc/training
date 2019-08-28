#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string s, t;
    cin >> t >> s;
    int d = 0, w = 0, h = 0;

    for (int j = 0; j < t.length(); j++) {
      if (s[t[j] - 'a'] == 'd')
        d++;
      else if (s[t[j] - 'a'] == 'w')
        w++;
      else if (s[t[j] - 'a'] == 'h')
        h++;
    }
    cout << "Case #"<<i<<": ";
    if (h * 4 >= t.length()) {
      cout << "Harmful";
    } else if (h * 10 <= t.length()) {
      cout << "Recyclable";
    } else if (d >= 2 * w) {
      cout << "Dry";
    } else {
      cout << "Wet";
    }
    cout << endl;
  }
  return 0;
}