#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct A {
  int p, t;
  int ind;
  bool operator<(const A& x) const {
    if (p != x.p) return p > x.p;
    return t < x.t;
  }
} sarr[100005];
string arr[100005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      int p, t;
      cin >> arr[i] >> sarr[i].p >> sarr[i].t;
      sarr[i].ind = i;
    }
    if (n * k % 10 == 5) {
      sort(sarr, sarr + n);
      cout << arr[sarr[n * k / 10].ind] << endl;
    } else {
      cout << "Quailty is very great" << endl;
    }
  }

  return 0;
}