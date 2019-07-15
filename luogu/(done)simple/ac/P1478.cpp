#include <iostream>
#include <vector>
using namespace std;

vector<int> vp;
int dp[2000];
int main() {
  int n, s;
  int a, b;
  cin >> n >> s >> a >> b;
  int len = a + b;
  for (int i = 0; i < n; i++) {
    int t, x;
    cin >> t >> x;
    if (t <= len) vp.push_back(x);
  }
  for (int i = 0; i < vp.size(); i++) {
    for (int j = s; j >= vp[i]; j--) {
      dp[j] = max(dp[j], dp[j - vp[i]] + 1);
    }
  }

  cout << dp[s] << endl;
  return 0;
}