// P1568 赛跑
// https://www.luogu.org/problem/P1568

#include <iostream>
using namespace std;

int A[1000005];
int B[1000005];

int main() {
  int n, m;
  cin >> n >> m;
  int cnt = 1;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    for (int j = 0; j < b; j++) {
      A[cnt] = A[cnt - 1] + a;
      cnt++;
    }
  }
  cnt = 1;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    for (int j = 0; j < b; j++) {
      B[cnt] = B[cnt - 1] + a;
      cnt++;
    }
  }
  int ans = 0;
  int flag;
  if (A[1] == B[1])
    flag = 0;
  else if (A[1] > B[1])
    flag = 1;
  else if (A[1] < B[1])
    flag = 2;

  for (int i = 2; i < cnt; i++) {
    int f;
    if (A[i] == B[i])
      f = 0;
    else if (A[i] > B[i])
      f = 1;
    else if (A[i] < B[i])
      f = 2;

    if (f != 0) {
      if (flag != 0 && flag != f) {
        ans++;
        flag = f;
      }
      flag = f;
    }
  }
  cout << ans << endl;
  return 0;
}