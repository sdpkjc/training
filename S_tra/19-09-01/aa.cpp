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

const int MAX_N = 1e6 + 10;
const int MAX_M = MAX_N << 2;
const int INF = 0x7f7f7f7f;

long long t[MAX_N];
int k[MAX_N];
long long r[MAX_N];
int d[MAX_N];
long long tot;

struct PST {
  struct tree {
    long long sum;
    tree *lson, *rson;
  } memory_pool[MAX_N * 21], *tail, *null, *root[MAX_N];

  void update(tree *&now, tree *pre, long long pos, long long l, long long r) {
    now = tail++;
    *now = *pre;
    now->sum++;
    if (l == r) return;
    int mid = (l + r) / 2;
    if (pos <= mid)
      update(now->lson, pre->lson, pos, l, mid);
    else
      update(now->rson, pre->rson, pos, mid + 1, r);
  }
  int query(tree *a, tree *b, long long l, long long r, long long L,
            long long R) {
    if (l > R || r < L) return 0;
    if (l >= L && r <= R) return a->sum - b->sum;
    int mid = (l + r) / 2;
    return query(a->lson, b->lson, l, mid, L, R) +
           query(a->rson, b->rson, mid + 1, r, L, R);
  }
  PST() {
    tail = memory_pool;
    null = tail++;
    root[0] = null->lson = null->rson = null;
  }
  void update(long long now, long long pre, long long pos) {
    update(root[now], root[pre], pos, 1, tot);
  }
  long long query(long long l, long long r, long long x) {
    return query(root[r], root[l - 1], 1, tot, 1,
                 (long long)(lower_bound(d + 1, d + tot + 1, x) - d - 1));
  }
} persistent_segment_tree;

int N, y;
int main() {
  scanf("%d%d", &N, &y);
  for (int i = 1; i <= N; i++) {
    scanf("%lld", &t[i]);
  }
  sort(t + 1, t + N + 1);
  for (int x = 1; x <= y; x++) {
    for (int i = 1; i <= N; i++) {
      r[i] = (long long)t[i] + y;
      k[i] = t[i] - t[i - 1];
    }
    int p = upper_bound(r + 1, r + N + 1, t[N] + x) - r;
    if (p == N + 1) {
      printf("%lld", t[N] + (long long)x);
      continue;
    }
    for (int i = 0; i <= N; i++) d[i] = k[i];
    sort(d + 1, d + N + 1);
    tot = unique(d + 1, d + N + 1) - d - 1;

    for (int i = 1; i <= N; i++) {
      persistent_segment_tree.update(i, i - 1,
                                     lower_bound(d + 1, d + tot + 1, k[i]) - d);
    }
    long long v = persistent_segment_tree.query(p + 1, N, x);
    if (v > 0)
      printf("%lld", t[N] + (long long)y);
    else {
      printf("%lld", t[N] + (long long)x);
    }
    if (x != y) putchar(' ');
  }

  return 0;
}
