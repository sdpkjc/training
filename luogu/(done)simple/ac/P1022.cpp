#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  int sumz = 0;
  int xs = 0;
  int f1 = 1;
  int f2 = 1;
  int tmp = 0;
  char c;
  s += " ";
  for (int i = 0; i < s.length(); i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      tmp *= 10;
      tmp += (s[i] - '0');
    } else {
      if (s[i] >= 'a' && s[i] <= 'z') {
        c = s[i];
        if (tmp != 0) {
          xs += (tmp * f1 * (-f2));
        } else {
          xs += (f1 * (-f2));
        }
      } else {
        sumz += (tmp * f1 * f2);
      }
      tmp = 0;
    }
    if (s[i] == '=') {
      f1 = 1;
      f2 = -1;
    }
    if (s[i] == '-') {
      f1 = -1;
    }
    if (s[i] == '+') {
      f1 = 1;
    }
  }
  // cout << sumz << " " << xs << endl;
  printf("%c=%.3lf\n", c, (double)sumz / xs);
  return 0;
}