// P4326 [COCI2006-2007#1] Herman
// https://www.luogu.org/problem/P4326

#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  double x;
  cin >> x;
  double pi = 3.14159265358974323846;

  printf("%.6lf\n%.6lf\n", pi * x * x, x * x * 2);

  return 0;
}