#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 2001000;
int dp[maxn];
int Next[maxn];

void get_Next(string s) {
  int n = s.length();
  Next[0] = n;
  int i, j, k;
  for (i = 0; i + 1 < n && s[i] == s[i + 1]; i++)
    ;
  Next[1] = i;
  k = 1;
  for (i = 2; i < n; i++) {
    int len = k + Next[k];
    int l = Next[i - k];
    if (l + i < len) {
      Next[i] = l;
    } else {
      for (j = max(0, len - i); j + i < n && s[j] == s[i + j]; j++)
        ;
      Next[i] = j;
      k = i;
    }
  }
}

struct Trie {
  int *ch[maxn];
  int cnt[maxn];
  int num;
  void init() {
    memset(ch, 0, sizeof(ch));
    memset(cnt, 0, sizeof(cnt));
    num = 0;
  }

  void insert(string s, int id) {
    int u = 0;
    for (int i = 0; i < s.length(); ++i) {
      if (ch[u] == NULL) {
        ch[u] = new int[26];
        memset(ch[u], -1, sizeof(int) * 26);
      }
      if (ch[u][s[i] - 'A'] == -1) {
        ch[u][s[i] - 'A'] = ++num;
      }
      u = ch[u][s[i] - 'A'];
      if (cnt[u]) {
        if (Next[s.length() - i - 1] == i + 1) {
          dp[id] = max(dp[id], dp[cnt[u]] + 1);
        }
      }
    }
    cnt[u] = id;
  }

} trie;

int main() {
  trie.init();
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    dp[i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    string t;
    cin >> t;
    get_Next(t);
    trie.insert(t, i);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
  return 0;
}