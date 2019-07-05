// P1207 [USACO1.2]双重回文数 Dual Palindromes
// https://www.luogu.org/problemnew/show/P1207

#include <iostream>
using namespace std;

string fb(int B, int num) {
  string re = "";
  if (num == 0) return "0";
  while (num != 0) {
    int x = num % B;
    string cx = "x";
    if (x < 10) {
      cx[0] = x + '0';
    } else {
      cx[0] = x - 10 + 'A';
    }
    re = cx + re;
    num /= B;
  }
  return re;
}

bool hw(string s) {
  string ss(s.rbegin(), s.rend());
  return s == ss;
}

int main() {
  int N, S;
  cin >> N >> S;
  int cnt = 0;
  for (int i = S + 1; cnt < N; i++) {
    int tmp = 0;
    for (int B = 2; B <= 10; B++) {
      string x = fb(B, i);
      if (hw(x)) {
        tmp++;
      }
    }
    if (tmp > 1) {
      cout << i << endl;
      cnt++;
    }
  }

  return 0;
}