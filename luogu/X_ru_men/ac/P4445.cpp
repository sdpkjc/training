// P4445 [AHOI2018初中组]报名签到
// https://www.luogu.org/problem/P4445

#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  long long q, ans = 0;
  cin >> q;
  for (int i = 1; i < n; i++) {
    long long a;
    cin >> a;
    ans += max(q, a);
    q = a;
  }
  cout << ans << endl;
  return 0;
}