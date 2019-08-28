// P1530 分数化小数 Fractions to Decimals
// https://www.luogu.org/problem/P1530

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int ka[1000000], kk[1000000];
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int num(int num) {
  if (num == 0) return 1;
  int re = 0;
  while (num != 0) {
    num /= 10;
    re++;
  }
  return re;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int a, b;
  stringstream ss;
  stringstream ssss;
  int x = 0;
  memset(ka, 0, sizeof(ka));
  cin >> a >> b;
  int c = gcd(a, b);
  a = a / c;
  b = b / c;
  if (a % b == 0)
    cout << a / b << ".0" << endl;
  else {
    ss << a / b << ".";
    a %= b;
    a *= 10;
    int cnt = 0;
    ka[cnt++] = a;
    while (1) {
      ss << a / b;
      kk[cnt - 1] = a / b;
      a %= b;
      if (a == 0) break;
      a *= 10;
      ka[cnt++] = a;
      bool pd = false;
      for (int k = 0; k < cnt - 1; k++)
        if (ka[k] == a) {
          pd = true;
          for (int p = k; p < cnt - 1; p++) {
            ssss << kk[p];
          }
          break;
        } else {
          if (cnt > 1000) break;
        }
      if (pd) break;
    }
    string a, b;
    ss >> a;
    ssss >> b;
    int x = 0;
    for (int i = 0; i < a.length() - b.length(); i++) {
      cout << a[i];
      x++;
      if (x % 76 == 0) cout << endl;
    }
    if (b.length() != 0) {
      cout << "(";
      x++;
      if (x % 76 == 0) cout << endl;

      for (int i = 0; i < b.length(); i++) {
        cout << b[i];
        x++;
        if (x % 76 == 0) cout << endl;
      }
      cout << ")";
      x++;
      if (x % 76 == 0) cout << endl;
    }
  }
}