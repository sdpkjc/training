// P1652 圆
// https://www.luogu.org/problem/P1652

#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int x[100], y[100], r[100];
int xx, yy, xxx, yyy;

bool f(int tx, int ty, int i) {
  double len = sqrt((tx - x[i]) * (tx - x[i]) + (ty - y[i]) * (ty - y[i]));
  if (len <= r[i]) {
    return true;
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> y[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> r[i];
  }

  cin >> xx >> yy >> xxx >> yyy;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int cnt = f(xx, yy, i) + f(xxx, yyy, i);
    if (cnt == 1) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}