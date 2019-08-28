// P1304 哥德巴赫猜想
// https://www.luogu.org/problem/P1304

#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

bool isp(int num) {
  if (num < 2) return false;
  int sq = sqrt(num);
  for (int i = 2; i <= sq; i++) {
    if (num % i == 0) return false;
  }
  return true;
}
bool flag[10005];
int main() {
  for (int i = 0; i <= 10000; i++) {
    flag[i] = isp(i);
  }
  int n;
  cin >> n;
  for (int i = 4; i <= n; i += 2) {
    for (int j = 2; j <= i - j; j++) {
      if (flag[j] && flag[i - j]) {
        cout << i << "=" << j << "+" << i - j << endl;
        break;
      }
    }
  }
  return 0;
}