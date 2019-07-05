// P3650 [USACO1.3]滑雪课程设计Ski Course Design
// https://www.luogu.org/problemnew/show/P3650

#include <algorithm>
#include <iostream>
using namespace std;

int arr[2000];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int ans = 0x3f3f3f3f;
  for (int i = arr[0]; i <= arr[n - 1]; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (arr[j] > i) {
        cnt += (arr[j] - i) * (arr[j] - i);
      }
      if (i - arr[j] > 17) {
        cnt += (i - arr[j] - 17) * (i - arr[j] - 17);
      }
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}