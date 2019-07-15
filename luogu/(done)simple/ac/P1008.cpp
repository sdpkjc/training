#include <iostream>
using namespace std;

int main() {
  int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  do {
    int aa = a[0] * 100 + a[1] * 10 + a[2];
    int bb = a[3] * 100 + a[4] * 10 + a[5];
    int cc = a[6] * 100 + a[7] * 10 + a[8];
    if (aa * 2 == bb && aa * 3 == cc) {
      cout << aa << " " << bb << " " << cc << endl;
    }
  } while (next_permutation(a, a + 9));

  return 0;
}