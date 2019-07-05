// P1200 [USACO1.1]你的飞碟在这儿Your Ride Is He…
// https://www.luogu.org/problemnew/show/P1200

#include <iostream>
using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  int ax = 1, bx = 1;
  for (int i = 0; i < a.length(); i++) {
    ax *= (a[i] - 'A' + 1);
    ax %= 47;
  }
  for (int i = 0; i < b.length(); i++) {
    bx *= (b[i] - 'A' + 1);
    bx %= 47;
  }

  if (ax == bx) {
    cout << "GO";
  } else {
    cout << "STAY";
  }
  cout << endl;

  return 0;
}