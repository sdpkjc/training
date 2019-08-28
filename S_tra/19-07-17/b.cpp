#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int m[10], p[10], s[10];
int main() {
  string a, b, c;
  cin >> a >> b >> c;
  if (a[1] == 's') {
    s[a[0] - '0']++;
  } else if (a[1] == 'p') {
    p[a[0] - '0']++;
  } else {
    m[a[0] - '0']++;
  }
  if (b[1] == 's') {
    s[b[0] - '0']++;
  } else if (b[1] == 'p') {
    p[b[0] - '0']++;
  } else {
    m[b[0] - '0']++;
  }
  if (c[1] == 's') {
    s[c[0] - '0']++;
  } else if (c[1] == 'p') {
    p[c[0] - '0']++;
  } else {
    m[c[0] - '0']++;
  }
  int maxk = 0;
  for (int i = 1; i <= 9; i++) {
    maxk = max(s[i], maxk);
    maxk = max(p[i], maxk);
    maxk = max(m[i], maxk);
  }
  maxk = 3 - maxk;
  int maxs = 2;
  for (int i = 2; i <= 8; i++) {
    if (s[i - 1] != 0 && s[i] == 0 && s[i + 1] != 0) {
      maxs = min(maxs, 1);
    }
    if (p[i - 1] != 0 && p[i] == 0 && p[i + 1] != 0) {
      maxs = min(maxs, 1);
    }
    if (m[i - 1] != 0 && m[i] == 0 && m[i + 1] != 0) {
      maxs = min(maxs, 1);
    }

    if (s[i - 1] == 0 && s[i] != 0 && s[i + 1] != 0) {
      maxs = min(maxs, 1);
    }
    if (p[i - 1] == 0 && p[i] != 0 && p[i + 1] != 0) {
      maxs = min(maxs, 1);
    }
    if (m[i - 1] == 0 && m[i] != 0 && m[i + 1] != 0) {
      maxs = min(maxs, 1);
    }

    if (s[i - 1] != 0 && s[i] != 0 && s[i + 1] == 0) {
      maxs = min(maxs, 1);
    }
    if (p[i - 1] != 0 && p[i] != 0 && p[i + 1] == 0) {
      maxs = min(maxs, 1);
    }
    if (m[i - 1] != 0 && m[i] != 0 && m[i + 1] == 0) {
      maxs = min(maxs, 1);
    }

    if (s[i - 1] != 0 && s[i] != 0 && s[i + 1] != 0) {
      maxs = min(maxs, 0);
    }
    if (p[i - 1] != 0 && p[i] != 0 && p[i + 1] != 0) {
      maxs = min(maxs, 0);
    }
    if (m[i - 1] != 0 && m[i] != 0 && m[i + 1] != 0) {
      maxs = min(maxs, 0);
    }
  }
  //   cout << maxs << " " << maxk << endl;
  cout << min(maxk, maxs) << endl;
  return 0;
}