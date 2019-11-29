#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1e6;
int arr[MAX_N];
int ans[MAX_N];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  vector<pair<int, int> > V;
  ans[n - 1] = -1;
  V.push_back(make_pair(arr[n - 1], n - 1));
  for (int i = n - 2; i >= 0; i--) {
    if (arr[i] + m <= V[0].first) {
      ans[i] = V[0].second - i - 1;
      //   cout << V[0].second - i - 1;
    } else if (arr[i] + m > V[V.size() - 1].first) {
    }
  }

  return 0;
}