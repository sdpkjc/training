#include <iostream>
using namespace std;

int n, L, G;

void f(int &w, int &h) {
  while (w > G || h > G) {
    w /= 2;
    h /= 2;
  }
}

int main() {
  cin >> n >> L >> G;
  for (int i = 0; i < n; i++) {
    int w, h;
    cin >> w >> h;
    f(w, h);
    if (w < L || h < L) {
      cout << "Too Young";
    } else if (w != h) {
      cout << "Too Simple";
    } else {
      cout << "Sometimes Naive";
    }
    cout << endl;
  }
  return 0;
}

// 4
// 48

// 48*4
// 192
// 12