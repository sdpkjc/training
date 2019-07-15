#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
typedef long long LL;
using namespace std;

const int maxn = 1000019, INF = 0x3f3f3f3f - 10;

struct Treap {
 private:
  int ch[maxn][2];  //[i][0]代表i左儿子，[i][1]代表i右儿子
  int val[maxn], dat[maxn];
  int size[maxn], cnt[maxn];
  int tot, root;
  int New(int v) {      //新增节点，
    val[++tot] = v;     //节点赋值
    dat[tot] = rand();  //随机优先级
    size[tot] = 1;      //目前是新建叶子节点，所以子树大小为1
    cnt[tot] = 1;       //新建节点同理副本数为1
    return tot;
  }
  void pushup(int id) {
    size[id] = size[ch[id][0]] + size[ch[id][1]] + cnt[id];
  }
  void build() {
    root = New(-INF),
    ch[root][1] = New(INF);  //先加入正无穷和负无穷，便于之后操作(貌似不加也行)
    pushup(root);  //因为INF > -INF,所以是右子树，
  }
  void Rotate(int &id, int d) {
    int temp = ch[id][d ^ 1];
    ch[id][d ^ 1] = ch[temp][d];
    ch[temp][d] = id;
    id = temp;

    pushup(ch[id][d]), pushup(id);
  }
  void insert(int &id, int v) {
    if (!id) {
      id = New(v);
      return;
    }
    if (v == val[id])
      cnt[id]++;
    else {
      int d = v < val[id] ? 0 : 1;
      insert(ch[id][d], v);
      if (dat[id] < dat[ch[id][d]]) Rotate(id, d ^ 1);
    }
    pushup(id);
  }
  void Remove(int &id, int v) {
    if (!id) return;
    if (v == val[id]) {
      if (cnt[id] > 1) {
        cnt[id]--, pushup(id);
        return;
      }
      if (ch[id][0] || ch[id][1]) {
        if (!ch[id][1] || dat[ch[id][0]] > dat[ch[id][1]]) {
          Rotate(id, 1), Remove(ch[id][1], v);
        } else
          Rotate(id, 0), Remove(ch[id][0], v);
        pushup(id);
      } else
        id = 0;
      return;
    }
    v < val[id] ? Remove(ch[id][0], v) : Remove(ch[id][1], v);
    pushup(id);
  }
  int get_rank(int id, int v) {
    if (!id) return 0;
    if (v == val[id])
      return size[ch[id][0]] + 1;
    else if (v < val[id])
      return get_rank(ch[id][0], v);
    else
      return size[ch[id][0]] + cnt[id] + get_rank(ch[id][1], v);
  }
  int get_val(int id, int rank) {
    if (!id) return INF;
    if (rank <= size[ch[id][0]])
      return get_val(ch[id][0], rank);

    else if (rank <= size[ch[id][0]] + cnt[id])
      return val[id];

    else
      return get_val(ch[id][1], rank - size[ch[id][0]] - cnt[id]);
  }

 public:
  Treap() { build(); }
  void push(int v) { insert(root, v); }
  void pop(int v) { Remove(root, v); }
  int lower(int v) {
    int id = root, pre;
    while (id) {
      if (val[id] < v)
        pre = val[id], id = ch[id][1];
      else
        id = ch[id][0];
    }
    return pre;
  }
  int upper(int v) {
    int id = root, next;
    while (id) {
      if (val[id] > v)
        next = val[id], id = ch[id][0];
      else
        id = ch[id][1];
    }
    return next;
  }
  int rank(int v)  //寻找该值对应的一个最近的上界值
  {
    return get_rank(root, v) - 1;
  }
  int atrank(int v)  //寻找该值对应的一个最近的下界值
  {
    return get_val(root, v + 1);
  }
};

Treap tr;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int opt, x;
    scanf("%d%d", &opt, &x);
    if (opt == 1)
      tr.push(x);
    else if (opt == 2)
      tr.pop(x);
    else if (opt == 3)
      printf("%d\n", tr.rank(x));
    else if (opt == 4)
      printf("%d\n", tr.atrank(x));
    else if (opt == 5)
      printf("%d\n", tr.lower(x));
    else if (opt == 6)
      printf("%d\n", tr.upper(x));
  }
  return 0;
}