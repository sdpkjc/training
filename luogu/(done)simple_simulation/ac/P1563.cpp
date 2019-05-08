// P1563 玩具谜题
// https://www.luogu.org/problemnew/show/P1563

#include <iostream>
using namespace std;

string arr[100005];
int arri[100005];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arri[i] >> arr[i];
  }

  // 逆时针+ 顺时针-
  // 面朝内 右手逆+ 左手顺-
  // 面朝外 右手顺- 左手逆+
  int loc = 0;
  for (int i = 0; i < m; i++) {
    int a, s;
    cin >> a >> s;
    if (arri[loc] == 0 && a == 0) {
      loc = (loc - s + n) % n;
    } else if (arri[loc] == 0 && a == 1) {
      loc = (loc + s + n) % n;
    } else if (arri[loc] == 1 && a == 0) {
      loc = (loc + s + n) % n;
    } else if (arri[loc] == 1 && a == 1) {
      loc = (loc - s + n) % n;
    }
  }
  cout << arr[loc] << endl;
  return 0;
}

// 判断情况就好了，水