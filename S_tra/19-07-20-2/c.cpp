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

signed main() {
  int a, b;
  cin >> a >> b;
  int c = a + b;
  int x = 1;
  for (int i = 0; i < c; i++) {
    x = x * 2 % 998244353;
  }
  cout << x << endl;
  return 0;
}
