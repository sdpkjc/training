// P1209 [USACO1.3]修理牛棚 Barn Repair
// https://www.luogu.org/problemnew/show/P1209

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int M, S, C;
  cin >> M >> S >> C;
  vector<int> arr;
  vector<int> ansv;

  for (int i = 0; i < C; i++) {
    int tmp;
    cin >> tmp;
    arr.push_back(tmp);
  }
  sort(arr.begin(), arr.end());

  for (int i = 1; i < C; i++) {
    ansv.push_back(arr[i] - arr[i - 1] - 1);
  }
  int ans = S;
  ans = ans - (arr[0] - 1);
  ans = ans - (S - arr[C - 1]);
  sort(ansv.begin(), ansv.end());
  for (int i = 0; i < min(C - 1, M - 1); i++) {
    ans -= ansv[C - i - 1 - 1];
  }
  cout << ans << endl;
  return 0;
}