// P1206 [USACO1.2]回文平方数 Palindromic Squares
// https://www.luogu.org/problemnew/show/P1206

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
  int B;
  cin >> B;

  for (int i = 1; i <= 300; i++) {
    string x = fb(B, i * i);
    if (hw(x)) {
      cout << fb(B, i) << " " << x << endl;
    }
  }

  return 0;
}