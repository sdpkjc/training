#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

pair<vector<pair<string, int> >, string> arr[1000];

int main() {
  int n, m;
  cin >> n >> m;
  string glen;
  getline(cin, glen);
  vector<pair<string, int> > q;
  int qcnt = 0;
  for (int i = 1; i <= n; i++) {
    getline(cin, glen);
    stringstream ss;
    ss << glen;
    string a, b;
    ss >> a >> b;
    int cc = 0;
    for (cc = 0; cc < a.length(); cc++) {
      if (a[cc] != '.') {
        break;
      }
    }
    a = a.substr(cc);
    for (int i = q.size() - 1; i >= 0; i--) {
      if (q[i].second >= cc) {
        q.pop_back();
      }
    }
    if (b.length() == 0) {
      b = "null";
    }
    q.push_back(make_pair(a, cc));
    arr[i].first = q;
    arr[i].second = b;
  }

  for (int i = 0; i < m; i++) {
    getline(cin, glen);
    vector<string> tmp;
    vector<int> ans;
    stringstream ss;
    ss << glen;
    string x;
    while (ss >> x) {
      tmp.push_back(x);
    }
    string id = "";
    if (tmp[tmp.size() - 1][0] == '#') {
      id = tmp[tmp.size() - 1];
      tmp.pop_back();
    }
    if (id.length() == 0) {
      id = "null";
    }
    for (int ii = 1; ii <= n; ii++) {
      bool flag = false;
      if (id == arr[ii].second || id == "null") {
        int j, jj;
        for (j = arr[ii].first.size() - 1, jj = tmp.size() - 1;
             j >= 0 && jj >= 0; j--, jj--) {
          if (arr[ii].first[j].first != tmp[jj]) {
            break;
          }
        }
        if (jj == -1) {
          flag = true;
        }
      }
      if (flag) ans.push_back(ii);
    }
    cout << ans.size();
    for (int ii = 0; ii < ans.size(); ii++) {
      cout << " " << ans[ii];
    }
    cout << endl;
  }
  return 0;
}
