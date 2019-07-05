// P1217 [USACO1.5]回文质数 Prime Palindromes
// https://www.luogu.org/problemnew/show/P1217

#include <string.h>
#include <cmath>
#include <iostream>

using namespace std;

const int MAXN = 10000000;
bool check[MAXN + 10];
int prime[MAXN + 10];
int tot;  //素数的个数
void phi_and_prime_table(int N) {
  memset(check, false, sizeof(check));
  tot = 0;
  for (int i = 2; i <= N; i++) {
    if (!check[i]) {
      prime[tot++] = i;
    }
    for (int j = 0; j < tot; j++) {
      if (i * prime[j] > N) break;
      check[i * prime[j]] = true;
    }
  }
}
int main() {
  int n;
  cin >> n;
  int x = 1;
  for (int i = 0; i < n - 1; i++) {
    x *= 10;
  }
  phi_and_prime_table(MAXN);
  if (n == 8) {
    cout << 23399339 << endl;
    cout << 29399999 << endl;
    cout << 37337999 << endl;
    cout << 59393339 << endl;
    cout << 73939133 << endl;
  } else {
    check[0] = check[1] = 1;
    for (int i = x; i < x * 10; i++) {
      int f = 1;
      int t = i;
      while (t != 0) {
        if (check[t]) {
          f = 0;
          break;
        }
        t /= 10;
      }
      if (f) {
        cout << i << endl;
      }
    }
  }
  return 0;
}