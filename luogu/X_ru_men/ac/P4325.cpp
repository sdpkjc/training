// P4325 [COCI2006-2007#1] Modulo
// https://www.luogu.org/problem/P4325

#include <iostream>
using namespace std;

int arr[43] = {0};

int main() {
  for (int i = 0; i < 10; i++) {
    int a;
    cin >> a;
    arr[a % 42]++;
  }
  int cnt = 0;
  for (int i = 0; i < 43; i++) {
    if (arr[i]) cnt++;
  }
  cout << cnt << endl;
  return 0;
}