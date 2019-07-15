const int MAXN = 300010;
int num[MAXN], st[MAXN];
struct Treap {
  int tot1;
  int s[MAXN], tot2;
  int ch[MAXN][2];
  int key[MAXN], size[MAXN];
  int sum0[MAXN], sum1[MAXN];
  int status[MAXN];
  void Init() {
    tot1 = tot2 = 0;
    size[0] = 0;
    ch[0][0] = ch[0][1] = 0;
    sum0[0] = sum1[0] = 0;
  }
  bool random(double p) { return (double)rand() / RAND_MAX < p; }
  int newnode(int val, int _status) {
    int r;
    if (tot2)
      r = s[tot2--];
    else
      r = ++tot1;
    size[r] = 1;
    key[r] = val;
    status[r] = _status;
    ch[r][0] = ch[r][1] = 0;
    sum0[r] = sum1[r] = 0;  //需要push_up return r;
  }
  void del(int r) {
    if (!r) return;
    s[++tot2] = r;
    del(ch[r][0]);
    del(ch[r][1]);
  }
  void push_up(int r) {
    int lson = ch[r][0], rson = ch[r][1];
    size[r] = size[lson] + size[rson] + 1;
    sum0[r] = gcd(sum0[lson], sum0[rson]);
    sum1[r] = gcd(sum1[lson], sum1[rson]);
    if (status[r] == 0)
      sum0[r] = gcd(sum0[r], key[r]);
    else
      sum1[r] = gcd(sum1[r], key[r]);
  }
  void merge(int &p, int x, int y) {
    if (!x || !y)
      p = x | y;
    else if (random((double)size[x] / (size[x] + size[y]))) {
      merge(ch[x][1], ch[x][1], y);

      push_up(p = x);
    } else {
      merge(ch[y][0], x, ch[y][0]);

      push_up(p = y);
    }
  }
  void split(int p, int &x, int &y, int k) {
    if (!k) {
      x = 0;
      y = p;
      return;
    }
    if (size[ch[p][0]] >= k) {
      y = p;
      split(ch[p][0], x, ch[y][0], k);
      push_up(y);
    } else {
      x = p;
      split(ch[p][1], ch[x][1], y, k - size[ch[p][0]] - 1);
      push_up(x);
    }
  }
  void build(int &p, int l, int r) {
    if (l > r) return;
    int mid = (l + r) / 2;
    p = newnode(num[mid], st[mid]);
    build(ch[p][0], l, mid - 1);
    build(ch[p][1], mid + 1, r);
    push_up(p);
  }
  void debug(int root) {
    if (root == 0) return;
    printf("%d␣␣␣左儿子：%d␣␣右儿子:␣%d␣␣size␣=␣%d␣␣key␣=␣%d\n", root,
           ch[root][0], ch[root][1], size[root], key[root]);
    debug(ch[root][0]);
    debug(ch[root][1]);
  }
};