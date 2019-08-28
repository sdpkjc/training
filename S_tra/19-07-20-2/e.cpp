#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
const int MAX = 1010;

int main() {
  string str;
  cin >> str;
  if (str.length() <= 3) {
    cout << str[0] << endl;
  } else {
    vector<pair<int, int> > X;

    string ans = "";
    int l = 0, r = str.length() - 1;
    while (l < r) {
      if (str[l] == str[r]) {
        X.push_back(make_pair(l, r));
        // ans = str[l] + ans + str[r];
        l++;
        r--;
      } else {
        l++;
      }
    }
    for (int i = X.size() - 1; i >= 0; i--) {
      int l = X[i].first, r = X[i].second;
      if (l != r)
        ans = str[l] + ans + str[r];
      else
        ans = str[l] + ans;
    }

    string ansb = "";
    X.clear();
    int lb = 0, rb = str.length() - 1;
    while (l < r) {
      if (str[l] == str[r]) {
        X.push_back(make_pair(l, r));
        // ans = str[l] + ans + str[r];
        lb++;
        rb--;
      } else {
        rb--;
      }
    }
    for (int i = X.size() - 1; i >= 0; i--) {
      int l = X[i].first, r = X[i].second;
      if (l != r)
        ansb = str[l] + ans + str[r];
      else
        ansb = str[l] + ans;
    }

    // cout << ans.length() << " " << str.length()/2<< endl;
    if (ans.length() > ansb.length()) {
      cout << ans << endl;
    } else {
      cout << ansb << endl;
    }
  }
}