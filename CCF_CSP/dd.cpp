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
queue<string> G[MAXN];
queue<int> Qin;

int main() {
  int T, n;
  cin >> T >> n;
  string s;
  getline(cin, s);
  while (T--) {
    for (int i = 0; i < n; i++) {
      while (!G[i].empty()) G[i].pop();
    }
    while (!Qin.empty()) Qin.pop();
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
      if (!G[i].empty() && G[i].front()[0] == 'S') {
        Qin.push(i);
      }
    }
    int flag = 0;
    while (cnt && !Qin.empty() && flag < n + 100) {
      flag++;
      int in = Qin.front();
      Qin.pop();
      if (!G[in].empty()) {
        string tmp = G[in].front();
        if (tmp[0] == 'S') {
          int next = f(tmp);
          if (!G[next].empty()) {
            int pre = f(G[next].front());
            if (G[next].front()[0] == 'R' && pre == in) {
              G[in].pop();
              G[next].pop();
              cnt--;
              cnt--;
              flag = 0;
              if (!G[in].empty() && G[in].front()[0] == 'S') {
                Qin.push(in);
              }
              if (!G[next].empty() && G[next].front()[0] == 'S') {
                Qin.push(next);
              }
            }
          }
        }
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