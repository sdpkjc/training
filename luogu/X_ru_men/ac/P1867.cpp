// P1867 【Mc生存】经验值
// https://www.luogu.org/problem/P1867#submit

#include <iostream>
using namespace std;

int main() {
  long long le = 0, jy = 0, n;
  cin >> n;
  double sm = 10;
  for (int i = 1; i <= n; i++) {
    double x;
    long long a;
    cin >> x >> a;
    sm -= x;
    if (sm <= 0) {
      break;
    } else {
      sm = min(10.0, sm);
      jy += a;
    }
  }
  long long re = 1;
  for (int i = 1; i <= 50; i++) {
    if (jy >= re) {
      le++;
      jy -= re;
    } else {
      break;
    }
    re *= 2;
  }
  cout << le << " " << jy << endl;
  return 0;
}