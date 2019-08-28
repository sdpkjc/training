#include <iostream>
using namespace std;
int arrA[2000];
int arrB[2000];
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
      cin >> arrA[i];
      if (arrA[i] != 0) x = arrA[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> arrB[i];
    }

    for (int i = n - 1; i >= 0; i--) {
      if (arrA[i] != 0) {
        x = i;
        break;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (arrB[i] != 0) {
        y = i;
        break;
      }
    }
    if (x < y) {
      cout << "0/1";
    } else if (x == y) {
      int g = gcd(arrA[x], arrB[y]);
      cout << arrA[x] / g << "/" << arrB[y] / g;
    } else {
      cout << "1/0";
    }
    cout << endl;
  }

  return 0;
}