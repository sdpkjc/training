#include <iostream>
#include <map>
using namespace std;

int so[4] = {0, 0, 0, 0};
map<pair<pair<int, int>, pair<int, int> >, int> M;

void dfs(int k) {
  if (k == 6) {
    M[make_pair(make_pair(so[0], so[1]), make_pair(so[2], so[3]))]++;
    return;
  }
  int cnt = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 4; j++) {
      if (cnt == k) {
        so[i] += 1;
        so[j] += 1;
        dfs(k + 1);
        so[i] -= 1;
        so[j] -= 1;

        so[i] += 3;
        dfs(k + 1);
        so[i] -= 3;

        so[j] += 3;
        dfs(k + 1);
        so[j] -= 3;
        return;
      }
      cnt++;
    }
  }
}

int main() {
  int n;
  cin >> n;
  dfs(0);
  for (int i = 1; i <= n; i++) {
    int arr[4];
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
    cout << "Case #" << i << ": ";
    int t = M[make_pair(make_pair(arr[0], arr[1]), make_pair(arr[2], arr[3]))];
    if (t == 1) {
      cout << "Yes";
    } else if (t > 1) {
      cout << "No";
    } else if (t == 0) {
      cout << "Wrong Scoreboard";
    }
    cout << endl;
  }
  return 0;
}