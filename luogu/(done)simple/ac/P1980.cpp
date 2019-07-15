#include <iostream>
using namespace std;

int flag[10];

void f(int num) {
  while (num != 0) {
    flag[num % 10]++;
    num /= 10;
  }
}

int main() {
  int n, x;
  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    f(i);
  }
  cout << flag[x] << endl;
  return 0;
}