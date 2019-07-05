#include <iostream>
using namespace std;
const int MAX_N = 1000010;
int C[MAX_N];

int main() {
  string a, b;
  cin >> a >> b;
  int ans = 0;
  int a1 = 0, b1 = 0;

  for (int i = 0; i < a.length(); i++) {
    if (a[i] == '1') {
      a1++;
      C[i + 1] = C[i] + 1;
    } else {
      C[i + 1] = C[i];
    }
  }
  for (int i = 0; i < b.length(); i++) {
    if (b[i] == '1') b1++;
  }
  for (int i = 0; i < a.length() - b.length() + 1; i++) {
    int tmp = C[i + b.length()] - C[i];
    // getsum(i + b.length()) - getsum(i + 1 - 1);

    // cout << i + b.length() << " " << i << " " << tmp << endl;
    if (tmp % 2 == b1 % 2) {
      ans++;
    }
  }
  cout << ans << endl;
}
