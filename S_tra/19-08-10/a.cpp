#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  double ans = 0;

  for (int i = 2; i < 20; i++) {
    double pow = 1;
    for (int j = 0; j < i; j++) {
      pow *= n;
    }
    ans += ((double)(14 * i) / pow);
  }
  ans += ((double)1 / 6);
  cout << ans << endl;

  return 0;
}