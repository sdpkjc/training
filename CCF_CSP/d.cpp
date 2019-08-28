#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

const int MAXN = 10005;

int f(string s) {
  int re = 0;
  string t = s.substr(1);
  stringstream ss;
  ss << t;
  ss >> re;
  return re;
}

int main() {
  int T, n;
  cin >> T >> n;
  string s;
  getline(cin, s);
  while (T--) {
    queue<string> G[MAXN];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      getline(cin, s);
      stringstream ss;
      ss << s;
      string t;
      while (ss >> t) {
        G[i].push(t);
        cnt++;
      }
    }
    while (cnt) {
      bool flag = true;
      for (int i = 0; i < n; i++) {
        if (!G[i].empty()) {
          string tmp = G[i].front();
          if (tmp[0] == 'S') {
            int next = f(tmp);
            if (!G[next].empty()) {
              int pre = f(G[next].front());
              if (G[next].front()[0] == 'R' && pre == i) {
                G[i].pop();
                G[next].pop();
                cnt--;
                cnt--;
                flag = false;
              }
            }
          }
        }
      }
      if (flag) {
        break;
      }
    }
    if (cnt == 0) {
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
    }
  }
  return 0;
}