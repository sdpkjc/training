#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 10010;
bool flag = true;
struct Trie {
  int ch[maxn][26];
  int cnt[maxn];
  int num;
  void init() {
    memset(ch[0], 0, sizeof(ch[0]));
    cnt[0] = 0;
    num = 0;
  }
  int newnode() {
    ++num;
    memset(ch[num], 0, sizeof(ch[num]));
    cnt[num] = 0;
    return num;
  }
  void insert(string s) {
    int u = 0;
    for (int i = 0; i < s.length(); ++i) {
      if (!ch[u][s[i] - 'a']) {
        ch[u][s[i] - 'a'] = newnode();
      }
      u = ch[u][s[i] - 'a'];
      ++cnt[u];
    }
  }
  int query(string s) {
    int u = 0;
    for (int i = 0; i < s.length(); ++i) {
      if (!ch[u][s[i] - 'a']) {
        return 0;
      }
      u = ch[u][s[i] - 'a'];
    }
    return cnt[u];
  }

} trie;

string sarr[1000005];
int main() {
  trie.init();
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> sarr[i];
  }
  sort(sarr, sarr + n);

  for (int i = n - 1; i >= 0; i--) {
    if (trie.query(sarr[i])) {
      flag = false;
      break;
    }
    trie.insert(sarr[i]);
  }
  if (flag) {
    cout << "Good Luck!";
  } else {
    cout << "Bug!";
  }
  cout << endl;
  return 0;
}