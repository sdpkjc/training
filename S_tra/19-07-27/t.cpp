
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
string s;
int a[200005] = {0};
int main() {
  while (cin >> s) {
    int ans = 0;
    memset(a, 0, sizeof(a));
    int st = 0;
    int sum = 0;
    int cnt = 0;
    while (s[st] == '0') {
      st++;
    }
    for (int i = st; i < s.size(); i++) {
      a[cnt++] = s[i] - '0';
      sum += a[cnt - 1];
      if (sum % 3 == 0 || cnt >= 3 || a[cnt - 1] % 3 == 0) {
        ans++;
        sum = 0;
        cnt = 0;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
