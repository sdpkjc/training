// P1202 [USACO1.1]黑色星期五Friday the Thirteenth
// https://www.luogu.org/problemnew/show/P1202

#include <iostream>
using namespace std;
int whatday(int y, int m, int d) {
  // 返回正确的星期。用 0 - 6 表示 星期 1 - 7
  if (m == 1 || m == 2) {
    y--;
    m += 12;
  }
  int w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
  return w;
}

int cnt[10];

int main() {
  int n;
  cin >> n;
  for (int y = 1900; y < 1900 + n; y++) {
    for (int m = 1; m < 13; m++) {
      cnt[whatday(y, m, 13)]++;
    }
  }
  for (int i = 5; i < 7; i++) {
    if (i != 5) cout << " ";
    cout << cnt[i];
  }

  for (int i = 0; i < 5; i++) {
    cout << " ";
    cout << cnt[i];
  }
  cout << endl;
  return 0;
}