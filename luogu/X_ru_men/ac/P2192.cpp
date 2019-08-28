// P2192 HXY玩卡片
// https://www.luogu.org/problem/P2192

#include <iostream>
using namespace std;

int main() {
  int n;
  int f = 0, z = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a == 5) {
      f++;
    } else {
      z++;
    }
  }
  if (z) {
    if (f < 9) {
      cout << 0;
    } else {
      f = f / 9 * 9;
      for (int i = 0; i < f; i++) {
        cout << 5;
      }
      for (int i = 0; i < z; i++) {
        cout << 0;
      }
    }
  } else {
    cout << -1;
  }
  cout << endl;
  return 0;
}