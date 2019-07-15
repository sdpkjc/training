#include <iostream>
using namespace std;

int main() {
  int x, n;
  cin >> x >> n;
  x--;
  unsigned long long ans = 0;
  for (int i = 0; i < n; i++, x++) {
    x %= 7;
    if (x != 5 && x != 6) ans += 250;
  }
  cout << ans << endl;
  return 0;
}