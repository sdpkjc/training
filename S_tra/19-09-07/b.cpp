#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

void f(int a) {
  if (a > 10) return;
  f(a + 1);
}
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

set<pair<ll, int> > s;
ll a[500005];

int main() {
  ll n, m;
  n = 400005;
  for (int i = 0; i < n; i++) {
    a[i] = i + 1;
    s.insert(make_pair(a[i], i));
  }
  for (int i = 0; i < n; i++) {
    int ans = 0;
    auto it = s.end();
    it--;
    ll temp = it->first;
    int index = it->second;
    if (a[i] + m <= temp) {
      ans = index - i - 1;
    } else {
      ans = -1;
    }
    // if (i < n - 1) printf(" ");
    s.erase(s.find(make_pair(a[i], i)));
  }
  int nn;
  scanf("%d", &nn);
  if (nn % 2 == 0 && n > 2) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
