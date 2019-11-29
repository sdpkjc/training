// P4702 取石子
// https://www.luogu.org/problem/P4702

#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a = 0;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    a ^= t;
  }
  if (a % 2 != 0) {
    cout << "Alice" << endl;
  } else {
    cout << "Bob" << endl;
  }

  return 0;
}