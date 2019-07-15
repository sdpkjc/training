#include <iostream>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  for (int i = 0; i < s.length(); i++) {
    s[i] = 'a' + (s[i] - 'a' + n) % 26;
  }
  cout << s << endl;
  return 0;
}