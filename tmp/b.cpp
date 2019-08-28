#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <string>
using namespace std;

const int MAXN = 1e6 + 5;
int Next[MAXN], n, m, lena, lenb;
string a, b, c;

void init(string a) {
  m = a.length();
  int i = 0, j = -1;
  while (i < m) {
    if (j == -1 || a[i] == a[j]) {
      Next[++i] = ++j;
    } else {
      j = Next[j];
    }
  }
}

int main() {
  Next[0] = -1;
  cin >> n >> a;
  for (int i = 1; i < n; i++) {
    cin >> b;
    lena = a.length();
    lenb = b.length();
    c = b + a;
    init(c);
    int len = min(Next[m], min(lena, lenb));
    for (int j = len; j < lenb; j++) a += b[j];
  }
  cout << a;
  return 0;
}