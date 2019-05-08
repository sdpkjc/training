// P1056 排座椅
// https://www.luogu.org/problemnew/show/P1056

#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

map<int, int> kk;
map<int, int> ll;

int main() {
  int m, n, k, l, d;
  scanf("%d%d%d%d%d", &m, &n, &k, &l, &d);
  for (int i = 0; i < d; i++) {
    int x, y, p, q;
    scanf("%d%d%d%d", &x, &y, &p, &q);

    if (x != p) {
      kk[min(x, p)]++;
    } else if (y != q) {
      ll[min(y, q)]++;
    }
  }
  vector<pair<int, int> > vk;
  for (map<int, int>::iterator it = kk.begin(); it != kk.end(); it++) {
    vk.push_back(make_pair(it->second, it->first));
  }
  vector<pair<int, int> > vl;

  for (map<int, int>::iterator it = ll.begin(); it != ll.end(); it++) {
    vl.push_back(make_pair(it->second, it->first));
  }

  sort(vk.begin(), vk.end());
  sort(vl.begin(), vl.end());

  vector<int> ansk;
  vector<int> ansl;

  for (int i = vk.size() - 1, j = 0; i >= 0 && j < k; i--, j++) {
    ansk.push_back(vk[i].second);
  }
  for (int i = vl.size() - 1, j = 0; i >= 0 && j < l; i--, j++) {
    ansl.push_back(vl[i].second);
  }

  sort(ansk.begin(), ansk.end());
  sort(ansl.begin(), ansl.end());
  for (int i = 0; i < ansk.size(); i++) {
    if (i != 0) printf(" ");
    printf("%d", ansk[i]);
  }
  printf("\n");
  for (int i = 0; i < ansl.size(); i++) {
    if (i != 0) printf(" ");
    printf("%d", ansl[i]);
  }
  printf("\n");
  return 0;
}
// 好像写麻烦了