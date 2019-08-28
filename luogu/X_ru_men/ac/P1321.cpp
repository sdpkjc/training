// P1321 单词覆盖还原
// https://www.luogu.org/problem/P1321

#include <iostream>
using namespace std;

int main() {
  string a;
  cin >> a;
  int ans1 = 0, ans2 = 0;
  for (int i = 0; i < a.length() - 2; i++) {
    if (a[i] == 'b' || a[i + 1] == 'o' || a[i + 2] == 'y') {
      ans1++;
    }
  }
  for (int i = 0; i < a.length() - 3; i++) {
    if (a[i] == 'g' || a[i + 1] == 'i' || a[i + 2] == 'r' || a[i + 3] == 'l') {
      ans2++;
    }
  }
  cout << ans1 << endl << ans2 << endl;

  return 0;
}