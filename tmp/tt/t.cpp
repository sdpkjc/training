你可能思路有问题，kmp求后缀，开头肯定是从下标为0开始的一定长度与从末尾往前的相同长度的字串是否一致就行，就是一个扩展kmp
#include <algorithm>
#include <cstdio>
#include <cstring>
    using namespace std;
const int maxn = 2000005;
int n, dp[maxn];
struct Trie {
  int *ch[maxn];
  int tot;
  int cnt[maxn];
  void init() {
    tot = 0;
    memset(cnt, 0, sizeof(cnt));
    memset(ch, 0, sizeof(ch));
  }
  void insert(char *str, int *Next, int idx) {
    int p = 0, n = strlen(str);
    for (int i = 0; str[i]; i++) {
      if (ch[p] == NULL) {
        ch[p] = new int[26];
        memset(ch[p], -1, sizeof(int) * 26);
      }
      if (ch[p][str[i] - 'A'] == -1) {
        ch[p][str[i] - 'A'] = ++tot;
      }
      p = ch[p][str[i] - 'A'];
      if (cnt[p]) {
        if (Next[n - i - 1] == i + 1) {
          dp[idx] = max(dp[idx], dp[cnt[p]] + 1);
        }
      }
    }
    cnt[p] = idx;
  }
} trie;

void kmp(char *s, int *Next) {
  int n = strlen(s);
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

int main() {
  scanf("%d", &n);
  for (int i = 0; i <= n; i++) {
    dp[i] = 1;
  }
  char words[maxn];
  int Next[maxn];
  trie.init();
  for (int i = 1; i <= n; i++) {
    scanf("\n%s", words);
    kmp(words, Next);
    trie.insert(words, Next, i);
  }
  int ans = -0x3f;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dp[i]);
  }
  printf("%d\n", ans);
  return 0;
}