#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool flag[3000][3000];

int main() {
  string a, b, c;
  while (cin >> a >> b >> c) {
    if (a.length() + b.length() != c.length()) {
      cout << "No" << endl;
      continue;
    }
    for (int i = 0; i < a.length() + 10; i++) {
      for (int j = 0; j < b.length() + 10; j++) {
        flag[i][j] = false;
      }
    }
    a = " " + a;
    b = " " + b;
    c = " " + c;

    flag[0][0] = true;
    // flag[0][1] = true;
    // flag[1][0] = true;

    for (int i = 0; i < a.length(); i++) {
      for (int j = 0; j < b.length(); j++) {
        if (i > 0 && flag[i - 1][j] && a[i] == c[i + j]) {
          flag[i][j] = true;
        }
        if (j > 0 && flag[i][j - 1] && b[j] == c[i + j]) {
          flag[i][j] = true;
        }
      }
    }
    if (flag[a.length() - 1][b.length() - 1]) {
      cout << "Yes";
    } else {
      cout << "No";
    }
    cout << endl;
  }
  return 0;
}