#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  int p = 1;
  int ss = 0;
  for (int i = s.length() - 1; i >= 0; i--) {
    if (s[i] == '1') {
      ss += p;
    }
    p *= 2;
  }
  int ans = 0;
  cout << ss << endl;
  return 0;
}