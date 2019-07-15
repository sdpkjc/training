#include <iostream>
using namespace std;

int main() {
  double s, x;
  cin >> s >> x;
  double ss = 0;
  int cnt = 0;
  bool flag = true;
  for (double d = 7; ss <= s + x; d *= 0.98) {
    // cout << ss << " " << cnt << endl;
    if (ss >= s - x && ss <= s + x) {
      cnt++;
    } else {
      cnt = 0;
    }
    if (cnt == 2) {
      flag = false;
    }
    ss += d;
  }
  if (flag) {
    cout << "n";
  } else {
    cout << "y";
  }
  cout << endl;
  return 0;
}