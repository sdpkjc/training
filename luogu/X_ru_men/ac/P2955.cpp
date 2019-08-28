// P2955 [USACO09OCT]奇数偶数Even? Odd?
// https://www.luogu.org/problem/P2955

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string a;
    cin >> a;
    if ((a[a.length() - 1] - '0') % 2) {
      cout << "odd";
    } else {
      cout << "even";
    }
    cout << endl;
  }
  return 0;
}