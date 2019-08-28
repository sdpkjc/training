#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

#define int long long

bool ispr(int num) {
  if (num < 2) return false;
  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) return false;
  }
  return true;
}

bool MAP[1005][1005];
int pd[1005];
signed main() {
  int n;
  cin >> n;
  int t = n;
  while (!ispr(t)) {
    t++;
  }
  cout << t << endl;
  for (int i = 1; i < n; i++) {
    cout << i << " " << i + 1 << endl;
  }
  cout << n << " " << 1 << endl;
  t -= n;
  for (int i = 2; i <= n; i++) {
    if (!t) break;
    cout << i << " " << n - i + 2 << endl;
    t--;
  }
  return 0;
}
