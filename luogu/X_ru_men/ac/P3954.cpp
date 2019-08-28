// P3954 成绩
// https://www.luogu.org/problem/P3954

#include <iostream>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  cout << a / 10 * 2 + b / 10 * 3 + c / 10 * 5 << endl;
  return 0;
}