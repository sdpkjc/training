// P1211 [USACO1.3]牛式 Prime Cryptarithm
// https://www.luogu.org/problemnew/show/P1211

#include <iostream>
using namespace std;

int arr[10];
int tmp[10] = {0};

void setx(int a) {
  while (a != 0) {
    tmp[a % 10] = 1;
    a /= 10;
  }
}

bool check(int a, int b) {
  for (int i = 0; i < 10; i++) {
    tmp[i] = 0;
  }
  int bb = b % 10, bbb = b / 10 % 10;
  int bbxa = bb * a;
  int bbbxa = bbb * a;
  if (!(bbxa >= 100 && bbxa < 1000 && bbxa >= 100 && bbxa < 1000)) {
    return false;
  }
  int axb = a * b;
  if (!(axb >= 1000 && axb < 10000)) {
    return false;
  }
  setx(a);
  setx(b);
  setx(bb);
  setx(bbb);
  setx(bbxa);
  setx(bbbxa);
  setx(axb);
  for (int i = 0; i < 10; i++) {
    if (arr[i] == 0 && tmp[i] != 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    arr[tmp]++;
  }
  int ans = 0;
  int cnt = 0;
  for (int i = 100; i < 1000; i++) {
    for (int j = 10; j < 100; j++) {
      cnt++;
      if (check(i, j)) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}