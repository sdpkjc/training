#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int> > vp;

int main() {
  for (int i = 1; i <= 7; i++) {
    int a, b;
    cin >> a >> b;
    vp.push_back(make_pair(a + b, i));
  }
  sort(vp.rbegin(), vp.rend());

  for (int i = 0; i < vp.size(); i++) {
    if (vp[i].first != vp[i + 1].first) {
      cout << vp[i].second << endl;
      break;
    }
  }
  return 0;
}