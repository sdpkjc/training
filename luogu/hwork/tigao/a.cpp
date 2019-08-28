#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
int ans;
string a, b;
vector<pair<string, string> > va;
void bfs() {
  map<string, int> M;
  queue<pair<string, int> > Q;
  Q.push(make_pair(a, 0));
  M[a] = 1;
  while (!Q.empty()) {
    string t = Q.front().first;
    int ti = Q.front().second;
    Q.pop();
    if (t == b) {
      ans = ti;
      break;
    }

    if (ti > 10) {
      break;
    }
    for (int i = 0; i < va.size(); i++) {
      string u = va[i].first;
      string v = va[i].second;

      string::size_type pos = -1;
      while ((pos = t.find(u, pos + 1)) != string::npos) {
        string tmp = t;
        tmp.replace(pos, u.length(), v);
        if (M[tmp] != 1) {
          Q.push(make_pair(tmp, ti + 1));
          M[tmp] = 1;
        }
      }
    }
  }
}
int main() {
  cin >> a >> b;
  string u, v;
  while (cin >> u >> v) {
    va.push_back(make_pair(u, v));
  }
  ans = -1;
  bfs();
  if (ans == -1) {
    cout << "NO ANSWER!";
  } else {
    cout << ans;
  }
  cout << endl;
  return 0;
}