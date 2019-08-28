#include <iostream>
using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m) {
    if (n == 0) {
      printf("%.5lf\n", 0.0);
      continue;
    } else if (m == 0) {
      printf("%.5lf\n", 1.0);
      continue;
    }
    int cnt = 0;
    int d = 1;
    while (m > 0) {
      m -= d;
      d *= 2;
      cnt++;
    }

    int cnt2 = 0;
    int d2 = 1;
    while (n > 0) {
      n -= d;
      d2 *= 2;
      cnt2++;
    }
    printf("%.5lf\n", (double)cnt2 / (double)cnt);
  }
  return 0;
}