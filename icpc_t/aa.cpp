#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
      int t;
      cin >> t;
      a.push_back(t);
    }
    for (int i = 0; i < n; i++) {
      int t;
      cin >> t;
      b.push_back(t);
    }
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    int ans = 0;
    int l = 0;
    for (int i = 0; i < n; i++) {
      int t = b[i];
      int x = lower_bound(a.begin() + l, a.end(), k - t) - a.begin();
      if (x < n) {
        // cout << i << endl;
        ans++;
      }
      l = x + 1;
    }
    cout << ans << endl;
  }
  return 0;
}