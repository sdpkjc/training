#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int s = a * 60 + b, e = c * 60 + d;
  int l = e - s;
  cout << l / 60 << " " << l % 60 << endl;
  return 0;
}