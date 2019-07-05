// P1203 [USACO1.1]坏掉的项链Broken Necklace
// https://www.luogu.org/problemnew/show/P1203

#include <iostream>
using namespace std;

int main() {
  int n;
  string st;
  cin >> n >> st;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x = i;
    char q = st[x];
    int cnt = 2;

    int flag[3] = {0};
    if (q == 'w') {
      flag[0]++;
    } else if (q == 'b') {
      flag[1]++;
    } else if (q == 'r') {
      flag[2]++;
    }

    for (int j = x + 1, k = 0; k < n; j++, k++) {
      j %= n;
      if (st[j] == 'w') {
        flag[0]++;
      } else if (st[j] == 'b') {
        flag[1]++;
      } else if (st[j] == 'r') {
        flag[2]++;
      }
      if (!(flag[1] && flag[2])) {
        cnt++;
      } else {
        break;
      }
      q = st[j];
    }

    x = (x - 1 + n) % n;
    flag[0] = flag[1] = flag[2] = 0;
    char qq = st[x];
    if (qq == 'w') {
      flag[0]++;
    } else if (qq == 'b') {
      flag[1]++;
    } else if (qq == 'r') {
      flag[2]++;
    }

    for (int j = x - 1, k = 0; k < n; j--, k++) {
      j += n;
      j %= n;
      if (st[j] == 'w') {
        flag[0]++;
      } else if (st[j] == 'b') {
        flag[1]++;
      } else if (st[j] == 'r') {
        flag[2]++;
      }
      if (!(flag[1] && flag[2])) {
        cnt++;
      } else {
        break;
      }
    }  //[,x-1]
    if (cnt > ans) {
      ans = cnt;
    }
  }
  cout << min(n, ans) << endl;
  return 0;
}