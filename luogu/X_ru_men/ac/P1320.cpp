// P1320 压缩技术（续集版）
// https://www.luogu.org/problem/P1320

#include <iostream>
#include <vector>
using namespace std;

vector<string> V;
int main() {
  string s;
  while (cin >> s) {
    V.push_back(s);
  }
  cout << V.size();

  int cnt = 0, sz = 0;
  for (int i = 0; i < V.size(); i++) {
    for (int j = 0; j < V[i].length(); j++) {
      if (V[i][j] - '0' == sz)
        cnt++;
      else {
        cout << " " << cnt;
        sz = V[i][j] - '0';
        cnt = 1;
      }
    }
  }
  if (cnt != 0) cout << " " << cnt;
  cout << endl;
  return 0;
}