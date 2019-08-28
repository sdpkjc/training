// P1634 禽兽的传染病
// https://www.luogu.org/problem/P1634

#include <iostream>
using namespace std;

int main() {
  long long a, b;
  cin >> a >> b;
  long long ans = 1;
  for (int i = 0; i < b; i++) {
    long long ll = ans * a;
    ans += ll;
  }
  cout << ans << endl;

  return 0;
}