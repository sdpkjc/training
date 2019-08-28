// P2084 进制转换
// https://www.luogu.org/problem/P2084

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  int dex;
  string s;
  cin >> dex >> s;
  bool flag = false;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != '0') {
      if (flag) cout << "+";
      flag = true;
      cout << s[i] << "*" << dex << "^" << s.length() - i - 1;
    }
  }
  cout << endl;
  return 0;
}