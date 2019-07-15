#include <string.h>
#include <cstdio>
#include <iostream>
#include <sstream>
using namespace std;
int mem[30][30][30];

int w(int a, int b, int c) {
  if (a <= 0 || b <= 0 || c <= 0) return 1;
  if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
  if (mem[a][b][c] == 0x3f3f3f3f) {
    if (a < b && b < c) {
      mem[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    } else {
      mem[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) -
                     w(a - 1, b - 1, c - 1);
    }
  }
  return mem[a][b][c];
}
signed main() {
  memset(mem, 0x3f, sizeof(mem));
  while (true) {
    int a, b, c;
    string sa, sb, sc;
    cin >> sa >> sb >> sc;
    if (sa.length() <= 3) {
      stringstream ss;
      ss << sa;
      ss >> a;
    } else {
      a = 21;
    }
    if (sb.length() <= 3) {
      stringstream ss;
      ss << sb;
      ss >> b;
    } else {
      b = 21;
    }
    if (sc.length() <= 3) {
      stringstream ss;
      ss << sc;
      ss >> c;
    } else {
      c = 21;
    }
    if (a == -1 && b == -1 && c == -1) {
      break;
    }
    printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
  }
  return 0;
}