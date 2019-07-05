#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int cntf(int num) {
  int re = 0;
  while (num != 0) {
    re += (num % 10);
    num /= 10;
  }
  return re;
}

int main() {
  for (int i = 1; i <= 50; i++) {
    cout << i << " " << cntf(i) << " " << cntf(2 * i) << endl;
  }
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    // a = (a + 8) % 9 + 1;
    // b = (b + 8) % 9 + 1;
    int ans = -1;
    for (int i = 1; i < 1e7; i++) {
      int p = cntf(i);
      //   p = (i + 8) % 9;
      int pp = cntf(2 * i);
      //   p = (2 * i + 8) % 9;
      if (a * p == b * pp) {
        ans = i;
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}