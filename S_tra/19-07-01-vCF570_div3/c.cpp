#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define int long long

signed main() {
  int q;
  cin >> q;
  while (q--) {
    int k, n, a, b;
    cin >> k >> n >> a >> b;
    if (k <= n * b) {
      cout << -1;
    } else {
      int x = k - 1 - n * b;
      cout << min(n, x / (a - b));
    }
    cout << endl;
  }

  return 0;
}