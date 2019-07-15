#include <iostream>
using namespace std;

int flag[10005];
int cnt[10005];
int ans[1000];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> ans[i];
    cnt[ans[i]] = 1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (ans[i] + ans[j] <= 10000 && cnt[ans[i] + ans[j]] &&
          ans[i] != ans[i] + ans[j] && ans[j] != ans[i] + ans[j]) {
        flag[ans[i] + ans[j]] += cnt[ans[i] + ans[j]];
      }
    }
  }
  int re = 0;
  for (int i = 0; i < 10005; i++) {
    if (flag[i]) re++;
  }
  cout << re << endl;

  return 0;
}