// P1146 硬币翻转
// https://www.luogu.org/problem/P1146

#include <iostream>
using namespace std;

bool a[1005];
int main() {
  int n;
  cin >> n;
  cout << n << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (j != i) {
        a[j] = !a[j];
      }
      cout << a[j];
    }
    cout << endl;
  }
  return 0;
}