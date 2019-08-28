#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main() {
  int n, d;
  cin >> n >> d;
  vector<pair<int, int> > arr;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    arr.push_back(make_pair(x, y));
  }
  sort(arr.begin(), arr.end());
  deque<pair<int, int> > Q;
  int ans = 0x3f3f3f3f;
  for (int i = 0; i < n; i++) {
    while (!Q.empty() && Q.back().second > arr[i].second) {
      Q.pop_back();
    }
    Q.push_back(arr[i]);
    while (!Q.empty() && Q.back().second - Q.front().second >= d) {
      ans = min(ans, Q.back().first - Q.front().first);
      Q.pop_front();
    }
  }
  if (ans == 0x3f3f3f3f) {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}