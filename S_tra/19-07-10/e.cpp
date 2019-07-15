#include <limits.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define int long long

map<int, int> M;
signed main() {
  int p, n, k;
  cin >> n >> p >> k;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    M[(tmp * tmp % p * tmp % p * tmp % p - k * tmp % p + p) % p]++;
  }
  for (map<int, int>::iterator it = M.begin(); it != M.end(); it++) {
    int x = it->second;
    ans += (x * (x - 1)) / 2;
  }
  cout << ans << endl;

  return 0;
}

// pow(a,4) - k*a === pow(b,4) - k*b