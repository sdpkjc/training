// P5015 标题统计
// https://www.luogu.org/problem/P5015

#include <iostream>
#include <map>
using namespace std;

int main() {
  string a;
  getline(cin, a);
  int ans = 0;
  for (int i = 0; i < a.length(); i++) {
    if (a[i] >= '0' && a[i] <= '9') ans++;
    if (a[i] >= 'a' && a[i] <= 'z') ans++;
    if (a[i] >= 'A' && a[i] <= 'Z') ans++;
  }
  cout << ans << endl;

  return 0;
}