#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 7;
const int mod = 998244353;
ll a[maxn];
int main() {
  int n, k;
  while (~scanf("%d %d", &n, &k)) {
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    sort(a, a + n);
    ll temp = k, cnt = 1, ans = 0, dif = 0;
    for (int i = 1; i < n && temp; i++) {
      if (a[i] != a[i - 1]) {
        ll peek = a[i] - a[i - 1];
        if (temp >= peek * cnt) {
          temp -= peek * cnt;
          ans += peek;
        } else {
          ans += temp / cnt;
          dif += temp % cnt;
          temp = 0;
          break;
        }
      }
      cnt++;
    }
    ans += temp / cnt;
    dif += temp % cnt;
    // cout << ans << " " << dif<<" "<<cnt << endl;
    a[0] += ans;
    for (int i = 1; i < cnt; i++) {
      a[i] = a[0];
      if (i + dif >= cnt) a[i]++;
    }
    /*for (int i = 0; i < n; i++)
            cout << a[i] << " ";
    cout << endl;*/
    temp = k, cnt = 1, ans = 0, dif = 0;
    for (int i = n - 2; i >= 0 && temp; i--) {
      if (a[i] != a[i + 1]) {
        ll peek = a[i + 1] - a[i];
        if (temp >= peek * cnt) {
          temp -= peek * cnt;
          ans += peek;
        } else {
          ans += temp / cnt;
          dif += temp % cnt;
          temp = 0;
          break;
        }
      }
      cnt++;
    }
    ans += temp / cnt;
    dif += temp % cnt;
    a[n - 1] -= ans;
    for (int i = n - cnt; i < n - 1; i++) {
      a[i] = a[n - 1];
      if (i + cnt - dif < n) a[i]--;
    }
    cout << a[n - 1] - a[0] << endl;
  }
}