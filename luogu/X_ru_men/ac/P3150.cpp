// P3150 pb的游戏（1）
// https://www.luogu.org/problem/P3150

#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a % 2) {
      cout << "zs wins";
    } else {
      cout << "pb wins";
    }
    cout << endl;
  }

  return 0;
}