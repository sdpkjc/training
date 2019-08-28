#include <limits.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
#define int long long
signed main() {
  int n, k;
  cin >> n >> k;
  double a = 1;
  double b = -(2 * n + 3);
  double c = n * n + n - 2 * k;
  double ans = (-b - sqrt(b * b - 4 * a * c)) / 2 * a;

  cout << (int)ans << endl;
  return 0;
}