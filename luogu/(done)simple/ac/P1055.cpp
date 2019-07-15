#include <iostream>
using namespace std;

int main() {
  string isbn;
  cin >> isbn;

  int x = (isbn[0] - '0') + 2 * (isbn[2] - '0') + 3 * (isbn[3] - '0') +
          4 * (isbn[4] - '0') + 5 * (isbn[6] - '0') + 6 * (isbn[7] - '0') +
          7 * (isbn[8] - '0') + 8 * (isbn[9] - '0') + 9 * (isbn[10] - '0');
  x %= 11;
  int xx = isbn[12] - '0';
  if (isbn[12] == 'X') {
    xx = 10;
  }
  if (x == xx) {
    cout << "Right" << endl;
  } else {
    if (x != 10)
      isbn[12] = (x + '0');
    else
      isbn[12] = ('X');
    cout << isbn << endl;
  }
  return 0;
}