#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
int isp(int n) {
  if (n < 2) return false;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    long long arr[30] = {0};
    bool f = true;
    for (int i = n; i >= 0; i--) {
      cin >> arr[i];
    }
    long long a = arr[2];
    long long b = arr[1];
    long long c = arr[0];

    if (n != 2) {
      if (n >= 3) {
        f = true;
      } else {
        f = false;
      }
    } else {
      long long x = b * b - 4ll * a * c;
      if (x < 0) {
        f = false;
      }
    }

    if (!f) {
      cout << "Yes";
    } else {
      cout << "No";
    }
    cout << endl;
  }
  return 0;
}