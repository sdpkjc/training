#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int X, K;
    cin >> X >> K;

    if (K % 3) {
      int a = X % 3;
      if (a == 0) {
        cout << "Bob";
      } else {
        cout << "Alice";
      }
    } else {
      int b = K / 3;
      b--;
      int c = 3 * b + 4;
      int d = X % c;
      if (d <= b * 3) {
        int a = d % 3;
        if (a == 0) {
          cout << "Bob";
        } else {
          cout << "Alice";
        }
      } else {
        d -= b * 3;
        if (d == 0) {
          cout << "Bob";
        } else {
          cout << "Alice";
        }
      }
    }
    cout << endl;
  }

  return 0;
}
