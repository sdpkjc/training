// P1075 质因数分解
// https://www.luogu.org/problem/P1075

#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

bool isp(int num) {
  int sq = sqrt(num);
  for (int i = 2; i <= sq; i++) {
    if (num % i == 0) return false;
  }
  return true;
}

int main() {
  int n;
  cin >> n;

  int sq = sqrt(n);
  for (int i = 2; i <= sq; i++) {
    if (n % i == 0 && isp(i) && isp(n / i)) {
      cout << n / i << endl;
      return 0;
    }
  }

  return 0;
}