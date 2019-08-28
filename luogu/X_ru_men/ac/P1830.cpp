// P1830 轰炸III
// https://www.luogu.org/problem/P1830

#include <iostream>
using namespace std;

int cnt[200][200], zh[200][200];

int main() {
  int n, m, q, Q;
  cin >> n >> m >> q >> Q;
  for (int i = 1; i <= q; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int j = x1; j <= x2; j++) {
      for (int k = y1; k <= y2; k++) {
        cnt[j][k]++;
        zh[j][k] = i;
      }
    }
  }
  while (Q--) {
    int x, y;
    cin >> x >> y;
    if (cnt[x][y] == 0) {
      cout << "N";
    } else {
      cout << "Y " << cnt[x][y] << " " << zh[x][y];
    }
    cout << endl;
  }
  return 0;
}