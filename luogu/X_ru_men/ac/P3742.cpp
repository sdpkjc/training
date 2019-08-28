// P3742 umi的函数
// https://www.luogu.org/problem/P3742

#include <iostream>
using namespace std;

int main() {
  int n;
  string a, b;
  cin >> n >> a >> b;

  for (int i = 0; i < n; i++) {
    if (a[i] < b[i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << b << endl;

  return 0;
}