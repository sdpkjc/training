// P1838 三子棋I
// https://www.luogu.org/problem/P1838

#include <iostream>
using namespace std;

int M[3][3] = {0};

int main() {
  string s;
  cin >> s;
  int flag = 1;
  for (int i = 0; i < s.length(); i++) {
    int x = s[i] - '1';
    M[x / 3][x % 3] = flag;
    if (flag == 1) {
      flag = 2;
    } else {
      flag = 1;
    }
  }
  int ans = 0;
  for (int i = 0; i < 3; i++) {
    if (M[i][0] > 0 && M[i][0] == M[i][1] && M[i][1] == M[i][2]) {
      ans = M[i][0];
    }
    if (M[0][i] > 0 && M[0][i] == M[1][i] && M[1][i] == M[2][i]) {
      ans = M[0][i];
    }
  }
  if (M[0][0] > 0 && M[0][0] == M[1][1] && M[1][1] == M[2][2]) {
    ans = M[0][0];
  }

  if (M[0][2] > 0 && M[0][2] == M[1][1] && M[1][1] == M[2][0]) {
    ans = M[0][2];
  }
  if (ans == 1) {
    cout << "xiaoa wins.";
  } else if (ans == 2) {
    cout << "uim wins.";
  } else {
    cout << "drew.";
  }
  cout << endl;

  return 0;
}