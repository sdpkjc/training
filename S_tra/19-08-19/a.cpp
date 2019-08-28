#include <iostream>
using namespace std;

typedef long long ll;

ll arr[205];
ll gs[10] = {0, 0, 0, 0};
ll ss[10] = {10, 20, 50, 100, 0};
ll ssx[10] = {100, 50, 20, 10, 0};
//  10  20 50 100
ll tmp[10] = {0, 0, 0, 0};

ll f(ll c) {
  tmp[3] = tmp[2] = tmp[1] = tmp[0] = 0;
  ll re = 0;
  re += (c / 100);
  tmp[3] = (c / 100);
  c -= (c / 100 * 100);
  re += (c / 50);
  tmp[2] = (c / 50);
  c -= (c / 50 * 50);

  re += (c / 20);
  tmp[1] = (c / 20);
  c -= (c / 20 * 20);

  re += (c / 10);
  tmp[0] = (c / 10);
  c -= (c / 10 * 10);

  if (c != 0) return 0x3f3f3f3f3f3f3f3f;

  return re;
}
ll sumx() {
  ll re = 0;
  for (int i = 0; i < 4; i++) {
    re += (gs[i] * ss[i]);
  }
  return re;
}
ll dfs(ll c, int i) {
  // cout << c << " " << i << endl;
  if (i < 0) {
    if (c == 0)
      return 0;
    else
      return -1;
  }
  if (c == 0) return 0;
  ll re = 0x3f3f3f3f3f3f3fll;
  if (gs[i] != 0) {
    ll t = min(gs[i], c / ss[i]);
    ll d = c - ss[i] * t;
    gs[i] -= t;
    ll x = dfs(d, i - 1);
    if (x != -1) {
      if (re > x + t) {
        re = x + t;
      }
    }
    gs[i] += t;

    t = min(gs[i] - 1, c / ss[i]);
    d = c - ss[i] * t;
    gs[i] -= t;
    x = dfs(d, i - 1);
    if (x != -1) {
      if (re > x + t) {
        re = x + t;
      }
    }
    gs[i] += t;
  } else {
    ll x = dfs(c, i - 1);
    if (x != -1) re = dfs(c, i - 1);
  }
  if (re != 0x3f3f3f3f3f3f3fll) {
    return re;
  } else {
    return -1;
  }
}

int main() {
  // gs[0] = 1;
  // gs[1] = 1;
  // cout << dfs(30, 3) << endl;
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < 5; i++) {
      gs[i] = 0;
    }
    for (int i = n; i >= 1; i--) {
      cin >> arr[i];
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
      ll cnt = 0x3f3f3f3f3f3f3f3fll;
      int jj = -1;
      ll suma = sumx();
      ll tx = min(suma, arr[i]);
      ll tmpx[4] = {0};
      if (dfs(arr[i], 3) != -1) {
        continue;
      }
      for (int j = 4; j >= 0; j--) {
        if (tx >= ssx[j]) {
          ll xx = dfs(tx - ssx[j], 3);
          if (xx != -1) {
            ll cnt2 = f(arr[i] - (tx - ssx[j]));
            if (cnt2 != -1) {
              if (cnt > xx + cnt2) {
                jj = j;
                cnt = xx + cnt2;
                for (int kxx = 0; kxx < 4; kxx++) {
                  tmpx[kxx] = tmp[kxx];
                }
              }
            }
          }
        }
      }

      if (cnt >= 0x3f3f3f3f3f3f3f3fll) {
        flag = false;
        break;
      }
      for (int j = 0; j < 4; j++) {
        gs[j] += tmpx[j];
      }
      // for (int i = 0; i < 4; i++) {
      //   cout << gs[i] << " ";
      // }
      // cout << endl;
    }
    if (flag) {
      ll ans = 0;
      for (int i = 0; i < 4; i++) {
        // cout << gs[i] << " ";
        ans += gs[i];
      }
      // cout << endl;
      cout << ans << endl;
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}