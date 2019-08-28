// P1150 Peter的烟
// https://www.luogu.org/problem/P1150

#include <iostream>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  long long ans = n;
  while (n >= k) {
    int t = n / k;
    ans += t;
    n = n % k;
    n += t;
  }
  cout << ans << endl;
  return 0;
}