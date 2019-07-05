#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define int long long

signed main() {
  int n, A, B;
  scanf("%lld%lld%lld", &n, &A, &B);
  if (B != 1) {
    set<pair<int, int> > SET;
    for (int i = 0; i < n; i++) {
      int l, r;
      scanf("%lld%lld", &l, &r);
      for (int j = l; j <= r; j++) {
        int t = j;
        int x = ((t + (t / B)) % A);
        int y = (t % B);
        SET.insert(make_pair(x, y));
      }
    }
    printf("%lld\n", (int)SET.size());
  } else {
    vector<pair<int, int> > vp;
    int ans = -1;
    if (A % 2ll == 0ll) {
      ans = A / 2ll;
      for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%lld%lld", &l, &r);
        if (r - l + 1 >= A / 2) {
          vp.push_back(make_pair(0, A / 2 - 1));
        } else {
          int xl = 2 * l % A / 2, xr = 2 * r % A / 2;
          if (A / 2 - xl + 1 + 1 >= r - l + 1) {
            vp.push_back(make_pair(xl, xr));
          } else {
            vp.push_back(make_pair(xl, A / 2 - 1));
            vp.push_back(make_pair(0, xr));
          }
        }
      }

      sort(vp.begin(), vp.end());
      int mb = vp[0].first, me = vp[0].second;
      for (int i = 1; i < vp.size(); i++) {
        if (vp[i].first > vp[i - 1].second) {
          ans -= (vp[i].first - vp[i - 1].second - 1);
        }
        if (mb > vp[i].first) {
          mb = vp[i].first;
        }
        if (me < vp[i].second) {
          me = vp[i].second;
        }
      }
      ans -= (mb - 0);
      ans -= (A / 2 - 1 - me);
      printf("%lld\n", ans);
    } else {
      ans = A;
      for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%lld%lld", &l, &r);
        if (r - l + 1 >= A) {
          vp.push_back(make_pair(0, A - 1));
        } else {
          int xl = l % A;
          int xr = r % A;
          if (A - xl + 1 + 1 >= r - l + 1) {
            vp.push_back(make_pair(xl, xr));
          } else {
            vp.push_back(make_pair(xl, A - 1));
            vp.push_back(make_pair(0, xr));
          }
        }
      }

      sort(vp.begin(), vp.end());
      int mb = vp[0].first, me = vp[0].second;
      for (int i = 1; i < vp.size(); i++) {
        if (vp[i].first > vp[i - 1].second) {
          ans -= (vp[i].first - vp[i - 1].second - 1);
        }
        if (mb > vp[i].first) {
          mb = vp[i].first;
        }
        if (me < vp[i].second) {
          me = vp[i].second;
        }
      }
      ans -= (mb - 0);
      ans -= (A - 1 - me);
      printf("%lld\n", ans);
    }
  }
  return 0;
}