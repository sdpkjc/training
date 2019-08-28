#include <iostream>
using namespace std;
typedef long long ll;
ll $(int n) {
  int res = 1;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      n /= i;
      res *= i - 1;
      while (n % i == 0) n /= i, res *= i;
    }
  }
  if (n > 1) res *= n - 1;
  return res;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, a, b;
    cin >> n >> a >> b;
    int sum = 0;
    for (int i = a; i <= b; i++) {
      sum += (i * $(n) / 2);
    }
    cout << sum << endl;
  }

  return 0;
}