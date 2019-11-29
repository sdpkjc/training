#include <cmath>
#include <iostream>
using namespace std;

double dp[10000000];
int main() {
  int T;
  cin >> T;
  int cnt = 1;
  while (T--) {
    cout << "Case " << cnt++ << ": ";
    double ans = 0.0;
    double n;
    cin >> n;
    double p = n / 100.0;
    double q = 0.02;
    dp[200] = 1.0 / p;
    for (int i = 200 - 1; i >= 4; i--) {
      dp[i] = dp[i+4]
    }
    cout << ans << endl;
  }
}