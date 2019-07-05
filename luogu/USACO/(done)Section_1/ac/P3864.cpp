// P3864 [USACO1.2]命名那个数字 Name That Number
// https://www.luogu.org/problemnew/show/P3864

#include <iostream>
using namespace std;

bool fchar(char num, char ar) {
  if (num == '1' || num == '0') return false;

  if (num == '2' && ar != 'A' && ar != 'B' && ar != 'C') return false;
  if (num == '3' && ar != 'D' && ar != 'E' && ar != 'F') return false;
  if (num == '4' && ar != 'G' && ar != 'H' && ar != 'I') return false;
  if (num == '5' && ar != 'J' && ar != 'K' && ar != 'L') return false;
  if (num == '6' && ar != 'M' && ar != 'N' && ar != 'O') return false;
  if (num == '7' && ar != 'P' && ar != 'R' && ar != 'S') return false;
  if (num == '8' && ar != 'T' && ar != 'U' && ar != 'V') return false;
  if (num == '9' && ar != 'W' && ar != 'X' && ar != 'Y') return false;

  return true;
}

int main() {
  string id;
  cin >> id;
  bool none = true;
  for (int i = 0; i < 4617; i++) {
    string t;
    cin >> t;
    if (t.length() == id.length()) {
      bool flag = true;
      for (int j = 0; j < id.length(); j++) {
        if (!fchar(id[j], t[j])) {
          flag = false;
          break;
        }
      }
      if (flag) {
        none = false;
        cout << t << endl;
      }
    }
  }
  if (none) {
    cout << "NONE" << endl;
  }
  return 0;
}