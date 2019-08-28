// P1664 每日打卡心情好
// https://www.luogu.org/problem/P1664

#include <iostream>
using namespace std;

int add(int n) {
  if (n <= 0) {
    return 0;
  }
  if (n < 3) {
    return 1;
  }
  if (n < 7) {
    return 2;
  }
  if (n < 30) {
    return 3;
  }
  if (n < 120) {
    return 4;
  }
  if (n < 365) {
    return 5;
  }
  return 6;
}
int sub(int n) {
  if (n <= 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  if (n >= 11) return 1024;
  int re = 1;
  for (int i = 0; i < n - 1; i++) {
    re *= 2;
  }
  return re;
}
int main() {
  int n;
  cin >> n;
  int ans = 0;
  int lx = 0;
  int k = 0;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    if (tmp) {
      lx++;
      lx -= sub(k);
      lx = max(lx, 1);
      ans += add(lx);
      k = 0;
    } else {
      k++;
    }
  }
  cout << ans << endl;
  return 0;
}