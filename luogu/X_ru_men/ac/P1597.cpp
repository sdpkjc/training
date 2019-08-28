// P1597 语句解析
// https://www.luogu.org/problem/P1597

#include <iostream>
using namespace std;

int main() {
  int arr[3] = {0};
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i += 5) {
    char a = s[i];
    char b = s[i + 3];
    if (b >= '0' && b <= '9') {
      arr[a - 'a'] = b - '0';
    } else {
      arr[a - 'a'] = arr[b - 'a'];
    }
  }
  cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;

  return 0;
}