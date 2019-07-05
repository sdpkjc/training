#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  string a, b, c;
  while (cin >> a >> b >> c) {
    int i = 0, j = 0, fl = 0;
    bool flag = true;
    while (i < a.length() && j < b.length()) {
      int k = i + j - fl;
      if (a[i] == c[k] || b[j] == c[k]) {
        if (a[i] == b[j]) {
          fl++;
          i++;
          j++;
        } else if (a[i] == c[k]) {
          i++;
          j -= fl;
          fl = 0;
        } else if (b[j] == c[k]) {
          j++;
          i -= fl;
          fl = 0;
        } else {
          break;
        }
      } else {
        flag = false;
        break;
      }
    }

    if (flag) {
      while (i < a.length()) {
        int k = i + j - fl;
        cout << i << " " << k << endl;
        if (a[i] != c[k]) {
          flag = false;
        }
        i++;
      }
      while (j < b.length()) {
        int k = i + j - fl;
        if (b[j] != c[k]) {
          flag = false;
        }
        j++;
      }
    }
    if (flag) {
      cout << "Yes";
    } else {
      cout << "No";
    }
    cout << endl;
  }
  return 0;
}