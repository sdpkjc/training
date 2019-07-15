#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a, a1, a2;
  int b, b1, b2;
  int c, c1, c2;
  cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;

  a = n / a1 * a2;
  if (n % a1 != 0) {
    a += a2;
  }

  b = n / b1 * b2;
  if (n % b1 != 0) {
    b += b2;
  }

  c = n / c1 * c2;
  if (n % c1 != 0) {
    c += c2;
  }

  cout << min(a, min(b, c)) << endl;
  return 0;
}