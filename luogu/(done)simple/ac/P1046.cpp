#include <iostream>
using namespace std;

int flag[10];

int main() {
  for (int i = 0; i < 10; i++) {
    cin >> flag[i];
  }
  int x;
  cin >> x;
  int cnt = 0;
  x += 30;
  for (int i = 0; i < 10; i++) {
    if (flag[i] <= x) {
      cnt++;
    }
  }
  cout << cnt << endl;

  return 0;
}