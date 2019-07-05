// P1217 [USACO1.5]回文质数 Prime Palindromes
// https://www.luogu.org/problemnew/show/P1217

#include <string.h>
#include <cmath>
#include <iostream>

using namespace std;

bool hw(string s) {
  string ss(s.rbegin(), s.rend());
  return s == ss;
}
string fb(int num) {
  int B = 10;
  string re = "";
  if (num == 0) return "0";
  while (num != 0) {
    int x = num % B;
    string cx = "x";
    if (x < 10) {
      cx[0] = x + '0';
    } else {
      cx[0] = x - 10 + 'A';
    }
    re = cx + re;
    num /= B;
  }
  return re;
}
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
  int a, b;
  cin >> a >> b;
  phi_and_prime_table(MAXN);
  for (int i = a; i <= b; i++) {
    if (i > 10000000) break;
    // cout << i << " " << prime[i] << " " << phi[i] << " " << check[i] << endl;
    if (!check[i] && hw(fb(i))) {
      cout << i << endl;
    }
  }
  return 0;
}