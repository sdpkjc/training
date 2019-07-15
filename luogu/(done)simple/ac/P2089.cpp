#include <iostream>
#include <vector>
using namespace std;

struct X {
  int i, j, k, l, m, n, p, q, r, s;
  X() {}
  X(int i, int j, int k, int l, int m, int n, int p, int q, int r, int s)
      : i(i), j(j), k(k), l(l), m(m), n(n), p(p), q(q), r(r), s(s) {}
  void print() {
    cout << i << " " << j << " " << k << " " << l << " " << m << " " << n << " "
         << p << " " << q << " " << r << " " << s << endl;
  }
};

int main() {
  int nn;
  cin >> nn;

  vector<X> vx;
  for (int i = 1; i < 4; i++) {
    for (int j = 1; j < 4; j++) {
      for (int k = 1; k < 4; k++) {
        for (int l = 1; l < 4; l++) {
          for (int m = 1; m < 4; m++) {
            for (int n = 1; n < 4; n++) {
              for (int p = 1; p < 4; p++) {
                for (int q = 1; q < 4; q++) {
                  for (int r = 1; r < 4; r++) {
                    for (int s = 1; s < 4; s++) {
                      if (i + j + k + l + m + n + p + q + r + s == nn) {
                        vx.push_back(X(i, j, k, l, m, n, p, q, r, s));
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  cout << vx.size() << endl;
  for (int i = 0; i < vx.size(); i++) {
    vx[i].print();
  }

  return 0;
}