// P2801 教主的魔法
// https://www.luogu.org/problem/P2801

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
#define int long long

const int MAXN = 1e6 + 5;
int arr[MAXN];
int n, m, k = 1005;
struct block {
  vector<int> VB;
} B[1005];
int add[MAXN];
void up(int in) {
  B[in].VB.clear();
  for (int j = in * k; j < min(in * k + k, n); j++) {
    B[in].VB.push_back(arr[j] + add[in]);
  }
  add[in] = 0;
  sort(B[in].VB.begin(), B[in].VB.end());
}
int low(int x, int in) {
  return B[in].VB.size()-(lower_bound(B[in].VB.begin(), B[in].VB.end(), x - add[in]) -
         B[in].VB.begin());
}
signed main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i += k) {
    up(i / k);
  }
  for (int i = 0; i < m; i++) {
    char cmd;
    int a, b, c;
    cin >> cmd >> a >> b >> c;
    a--;
    b--;
    if (cmd == 'A') {
      int ll = a / k;
      int rr = b / k;
      int ans = 0;
      if (ll == rr) {
        for (int j = a; j <= b; j++) {
          if (arr[j] - add[ll] >= c) {
            ans++;
          }
        }
      } else {
        for (int j = ll + 1; j <= rr - 1; j++) {
          ans += low(c, j);
        }
        for (int j = a; j < min((ll + 1) * k, n); j++) {
          if (arr[j] - add[ll - 1] >= c) {
            ans++;
          }
        }
        for (int j = rr * k; j <= b; j++) {
          if (arr[j] - add[rr] >= c) {
            ans++;
          }
        }
      }
      cout << ans << endl;
    } else if (cmd == 'M') {
      int ll = a / k;
      int rr = b / k;
      if (ll == rr) {
        for (int j = a; j <= b; j++) {
          arr[j] += c;
        }
      } else {
        for (int j = ll + 1; j <= rr - 1; j++) {
          add[j] += c;
        }
        for (int j = a; j < min((ll + 1) * k, n); j++) {
          arr[j] += c;
        }
        for (int j = rr * k; j <= b; j++) {
          arr[j] += c;
        }
      }
    }
  }
  return 0;
}