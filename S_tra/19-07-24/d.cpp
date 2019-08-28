#include <iostream>
using namespace std;
#define int long long
const int p = 998244353;
int n;
int qmi(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = res * a % p;
    b >>= 1;
    a = a * a % p;
  }
  return res;
}
int inv(int x) { return qmi(x, p - 2); }
signed main() {
  while (cin >> n) {
    cout << ((n * n - 1) * inv(9)) % p << endl;
  }
  return 0;
}