#include <iostream>
using namespace std;

int main() {
  double x;
  cin >> x;
  double n = 2;
  int cnt = 0;
  while (x > 0) {
    cnt++;
    x -= n;
    n *= 0.98;
  }
  cout << cnt << endl;
  return 0;
}