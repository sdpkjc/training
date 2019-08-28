#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  int ans = 0;
  map<int, int> M;
  bool flag = true;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    M[t]++;
    if (M[t - 1] != 0 || M[t + 1] != 0) {
      flag = false;
    }
    if (t % 2 == 0) {
      ans ^= 1;
    } else {
      ans ^= 0;
    }
    // ans ^= (t % 2);
  }
  if (ans == 0 || !flag) {
    cout << "sjfnb";
  } else {
    cout << "cslnb";
  }
  cout << endl;

  return 0;
}

// 0 1 2 3
// c t c t
