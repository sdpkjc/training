#include <iostream>
using namespace std;

int main() {
  int k;
  cin >> k;
  double s = 0;
  for (int i = 0;; i++) {
    s += (double)1 / (double)(i + 1);
    if (s > k) {
      cout << i + 1 << endl;
      break;
    }
  }

  return 0;
}