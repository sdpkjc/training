// P1161 开灯
// https://www.luogu.org/problem/P1161

#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    double a;
    int t;
    cin >> a >> t;
    for (int j = 1; j <= t; j++) ans ^= int(a * j);
  }
  cout << ans << endl;
  return 0;
}