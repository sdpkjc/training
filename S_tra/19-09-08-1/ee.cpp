#include <string.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
  int n, m;  // n个人，第m个人死
  cin >> n >> m;
  bool* live = new bool[n];
  for (int i = 0; i < n; ++i) live[i] = true;
  int res = n, cnt = 0;
  cout << "1"
       << " ";
  live[1] = false;
  cnt++;
  for (int i = 2;; i = (i + 1) % n) {
    if (live[i] == true)
      cnt++;
    else
      continue;
    if (cnt == m) {
      live[i] = false;
      if (i != 0)
        cout << i << " ";
      else
        cout << n << " ";
      res--;
      cnt = 0;
    }
    if (res == 0)  //空环
      break;
  }
  delete[] live;
  return 0;
}