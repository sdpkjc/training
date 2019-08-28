#include <algorithm>
#include <iostream>
using namespace std;
#define int long long
pair<int, int> arr[2000];

signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr + n);
    int s = 0x3f3f3f3f3f3f3f3f;
    s = min(arr[0].second, arr[1].first);
    // for (int i = 0; i < n; i++) {
    // }
    arr[0].first = arr[0].second;
    int sum = 0ll;
    int now = s;
    // cout << s << endl;
    for (int i = 0; i < n; i++) {
      int ne = arr[i].first;
      int len = ne - now;
      int st = len / 2ll;
      if (len % 2ll == 0ll) {
        sum += st;
        now = ne;
      } else {
        if (arr[i].first != arr[i].second) {
          sum += (st + 1ll);
          now = (ne + 1ll);
        } else {
          sum += (st + 1ll);
          now = (ne);
        }
      }
      //   cout << now << " " << st << endl;
    }
    cout << sum << endl;
  }
  return 0;
}