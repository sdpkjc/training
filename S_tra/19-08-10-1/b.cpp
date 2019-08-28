#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int n, m, p;
    cin >> n >> m >> p;
    int ans = 0;
    for (int i = 1; i <= p; i++) {
      if (p % i == 0) {
        int a = i;
        int b = p / i;
        if (a == b) {
          ans += ((n / a));
        } else {
          ans += ((n / a) * (m / b));
        }
      }
    }
    cout << ans + (n * m / p) << endl;
  }
  return 0;
}