#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;

int count(int n, int x) {
  int cnt = 0, k;
  for (int i = 1; k = n / i; i *= 10) {
    // 高位的数字。
    int high = k / 10;
    if (x == 0) {
      if (high) {
        high--;
      } else {
        break;
      }
    }
    cnt += high * i;
    // 当前位的数字。
    int cur = k % 10;
    if (cur > x) {
      cnt += i;
    } else if (cur == x) {
      // n - k * i 为低位的数字。
      cnt += n - k * i + 1;
    }
  }
  return cnt;
}

int f(int n, int d) { return n - count(n, d); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n, d;
    cin >> d >> n;
    int l = 0, r = n;
    while (r - l > 2) {
      int lm = l + (r - l) / 3;
      int rm = r - (r - l) / 3;
      int la = f(lm, d);
      int ra = f(rm, d);
      if (la > ra) {
        l = lm;
      } else {
        r = rm;
      }
    }
    // cout << l << endl;
    while ((l + 1 - count(l + 1, d)) == 0 && l + 1 <= n) {
      l++;
    }
    if (f(l, d) == 0) {
      cout << l << endl;
    } else {
      cout << d << endl;
    }
  }
  return 0;
}