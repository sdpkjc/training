// P4445 [AHOI2018初中组]报名签到
// https://www.luogu.org/problem/P4445

#include <iostream>
using namespace std;
int x;

bool f(int n) {
  int a = n / 10000;
  int b = n / 1000 % 10;
  int c = n / 100 % 10;
  int d = n / 10 % 10;
  int e = n / 1 % 10;
  int a1 = a * 100 + b * 10 + c;
  int a2 = b * 100 + c * 10 + d;
  int a3 = c * 100 + d * 10 + e;
  if (a1 % x == 0 && a2 % x == 0 && a3 % x == 0) {
    return true;
  }
  return false;
}

int main() {
  cin >> x;
  bool flag = true;
  for (int i = 10000; i <= 30000; i++) {
    if (f(i)) {
      cout << i << endl;
      flag = false;
    }
  }
  if (flag) cout << "No" << endl;
  return 0;
}