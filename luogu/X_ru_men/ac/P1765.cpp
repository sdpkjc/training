// P1765 手机_NOI导刊2010普及（10）
// https://www.luogu.org/problem/P1765

#include <algorithm>
#include <iostream>
using namespace std;

int arr[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1,
               2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};

int main() {
  string s;
  int cnt = 0;
  getline(cin, s);
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ') {
      cnt++;
    } else if (s[i] >= 'a' && s[i] <= 'z') {
      cnt += arr[s[i] - 'a'];
    }
  }
  cout << cnt << endl;
  return 0;
}