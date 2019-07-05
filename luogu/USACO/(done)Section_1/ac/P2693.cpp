// P2693[USACO1 .3] 号码锁 Combination Lock
// https://www.luogu.org/problemnew/show/P2693

#include <cmath>
#include <iostream>
using namespace std;

int A[3], B[3];
int n;

bool check(int a, int b, int c) {
  if ((abs(A[0] - a) < 3 || abs(A[0] - a) > n - 3) &&
      (abs(A[1] - b) < 3 || abs(A[1] - b) > n - 3) &&
      (abs(A[2] - c) < 3 || abs(A[2] - c) > n - 3))
    return true;
  if ((abs(B[0] - a) < 3 || abs(B[0] - a) > n - 3) &&
      (abs(B[1] - b) < 3 || abs(B[1] - b) > n - 3) &&
      (abs(B[2] - c) < 3 || abs(B[2] - c) > n - 3))
    return true;
  return false;
}

int main() {
  cin >> n;
  for (int i = 0; i < 3; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < 3; i++) {
    cin >> B[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        if (check(i, j, k)) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}