#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 30000;
bool flag[MAX_N + 1];
int primes[MAX_N];
int nPrimes;
int simple_euler(int N) {
  memset(flag, true, (N + 1) * sizeof(bool));
  nPrimes = 0;
  for (int f = 2; f <= N / 2; f++) {
    if (flag[f]) {
      primes[nPrimes++] = f;
    }
    for (int u = 0; u < nPrimes; u++) {
      int p = primes[u];
      if (p * f > N) break;
      flag[p * f] = false;
      if (f % p == 0) break;
    }
  }

  for (int i = N / 2 + 1; i <= N; i++) {
    if (flag[i]) {
      primes[nPrimes++] = i;
    }
  }
  return nPrimes;
}

bool ispr(int n) {
  if (n < 2) return false;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  int n;
  cin >> n;
  simple_euler(n);

  for (int i = 0; i < nPrimes; i++) {
    for (int j = i; j < nPrimes; j++) {
      for (int k = j; k < nPrimes; k++) {
        if (primes[i] + primes[j] + primes[k] == n) {
          cout << primes[i] << " " << primes[j] << " " << primes[k] << endl;
          return 0;
        }
      }
    }
  }
  return 0;
}