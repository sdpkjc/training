// P1554 梦中的统计
// https://www.luogu.org/problem/P1554

#include <iostream>
using namespace std;

int cnt[10];

void f(int num) {
  do {
    cnt[num % 10]++;
    num /= 10;
  } while (num);
}

int main() {
  int a, b;
  cin >> a >> b;
  for (int i = a; i <= b; i++) {
    f(i);
  }
  for (int i = 0; i < 10; i++) {
    if (i != 0) cout << " ";
    cout << cnt[i];
  }
  cout << endl;

  return 0;
}