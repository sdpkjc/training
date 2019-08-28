// P2550 [AHOI2001]彩票摇奖
// https://www.luogu.org/problem/P2550

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int ans[10], zj[10], tmp[10];
void f() {
  map<int, int> M;
  for (int i = 0; i < 7; i++) {
    M[zj[i]]++;
  }
  int cnt = 0;
  for (int i = 0; i < 7; i++) {
    if (M[tmp[i]] > 0) {
      cnt++;
      M[tmp[i]]--;
    }
  }
  ans[7 - cnt]++;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < 7; i++) {
    cin >> zj[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 7; j++) {
      cin >> tmp[j];
    }
    f();
  }

  for (int i = 0; i < 7; i++) {
    if (i != 0) cout << " ";
    cout << ans[i];
  }
  cout << endl;

  return 0;
}