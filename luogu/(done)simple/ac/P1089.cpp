#include <iostream>
using namespace std;
int main() {
  int ma = 0, fl = -1;
  int jj = 0;
  for (int i = 1; i <= 12; i++) {
    jj += 300;
    int t;
    cin >> t;
    jj -= t;
    if (jj < 0) {
      fl = i;
      break;
    }
    int c = jj / 100 * 100;
    ma += c;
    jj -= c;
  }

  jj += (ma / 100 * 120);

  if (fl == -1) {
    cout << jj;
  } else {
    cout << -fl;
  }
  cout << endl;

  return 0;
}