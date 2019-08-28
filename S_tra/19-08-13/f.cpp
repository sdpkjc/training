#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int MAX_N = 350005;
int arr[MAX_N];
int flag[MAX_N];

int main() {
  int n, r;
  cin >> n >> r;
  vector<pair<int, int> > add;
  vector<pair<int, int> > sub;
  int sum = 1;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (b < 0) {
      sub.push_back(make_pair(a + b, a));
    } else {
      add.push_back(make_pair(a, b));
    }
  }
  sort(add.begin(), add.end());
  sort(sub.rbegin(), sub.rend());
  for (int i = 0; i < add.size(); i++) {
    if (r >= add[i].first) {
      r += add[i].second;
    } else {
      sum = 0;
      break;
    }
  }
  for (int i = 0; i < sub.size(); i++) {
    // cout << sub[i].second << " " << sub[i].first - sub[i].second << endl;
    if (r >= (sub[i].second)) {
      r += sub[i].first - sub[i].second;
    } else {
      sum = 0;
      break;
    }
    if (r < 0) {
      sum = 0;
      break;
    }
  }
  if (sum) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  cout << endl;
}