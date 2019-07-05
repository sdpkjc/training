// P1204 [USACO1.2]挤牛奶Milking Cows
// https://www.luogu.org/problemnew/show/P1204

#include <iostream>
using namespace std;

int arr[1000005];
int cntr[1000005];

int main() {
  int n;
  cin >> n;
  int l = 1000005, r = -1;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    arr[a]++;
    arr[b]--;
    l = min(l, a);
    r = max(r, b);
  }
  int cnt = 0;
  for (int i = l; i <= r; i++) {
    cnt += arr[i];
    cntr[i] = cnt;
  }
  int cnt0 = 0, cnt1 = 0;

  int ans0 = 0, ans1 = 0;
  for (int i = l; i <= r; i++) {
    if (cntr[i] == 0) {
      cnt0++;
    } else {
      ans0 = max(ans0, cnt0);
      cnt0 = 0;
    }
    if (cntr[i] >= 1) {
      cnt1++;
    } else {
      ans1 = max(ans1, cnt1);
      cnt1 = 0;
    }
  }
  cout << ans1 << " " << ans0 << endl;

  return 0;
}