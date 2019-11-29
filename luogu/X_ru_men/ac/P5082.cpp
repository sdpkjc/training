// P5082 成绩
// https://www.luogu.org/problem/P5082

#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  double a = 0, b = 0;

  for (int i = 0; i < n; i++) {
    double t;
    scanf("%lf", &t);
    a += t;
  }
  for (int i = 0; i < n; i++) {
    double t;
    scanf("%lf", &t);
    b += t;
  }
  printf("%.6lf\n", (a * 3.0 - b * 2.0) / (a - b));
  return 0;
}