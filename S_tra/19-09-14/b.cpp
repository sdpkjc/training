#include <iostream>
using namespace std;

int A[10000];
int F[10000];
const int MOD = 1e9 + 7;
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long k, n;
    cin >> k >> n;
    long long ans = 0, sum = 0;
    for (int i = 0; i < k; i++) {
      cin >> A[i];
    }
    for (int i = 0; i < k; i++) {
      cin >> F[i];
      sum = (sum + F[i]) % MOD;
    }
    for (int i = 0; i < k && n > 0ll; i++, n--) {
      ans = (ans + A[i]) % MOD;
    }
    if (n > 0) {
      long long x = n / k;
      n = n % k;
      x %= MOD;
      ans = (ans + (sum * x) % MOD) % MOD;
    }
    for (int i = 0; i < k && n > 0ll; i++, n--) {
      ans = (ans + F[i]) % MOD;
    }
    cout << ans << endl;
  }
  return 0;
}