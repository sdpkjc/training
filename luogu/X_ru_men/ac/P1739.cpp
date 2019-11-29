// P1739 表达式括号匹配
// https://www.luogu.org/problem/P5015

#include <iostream>
#include <stack>
using namespace std;

int main() {
  string a;
  cin >> a;
  stack<int> S;
  bool flag = true;
  for (int i = 0; i < a.length(); i++) {
    if (a[i] == '(') {
      S.push(1);
    } else if (a[i] == ')') {
      if (S.empty()) {
        flag = false;
        break;
      } else {
        S.pop();
      }
    }
  }
  if (!S.empty()) {
    flag = false;
  }
  if (flag)
    cout << "YES";
  else
    cout << "NO";
  cout << endl;
  return 0;
}