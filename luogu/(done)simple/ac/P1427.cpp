#include <iostream>
using namespace std;

int flag[10005];

int main() {
  int i;
  for (i = 0;; i++) {
    cin >> flag[i];
    if (flag[i] == 0) {
      break;
    }
  }
  i--;
  for (; i >= 0; i--) {
    cout << flag[i];
    if (i != 0) cout << " ";
  }
  return 0;
}