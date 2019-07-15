// P3369 【模板】普通平衡树
// https://www.luogu.org/problemnew/show/P3369

#include <cstdio>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
int main() {
  tree<double, null_type, less<double>, rb_tree_tag,
       tree_order_statistics_node_update>
      bbt;
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int opt;
    double x;
    scanf("%d%lf", &opt, &x);
    if (opt == 1) {
      bbt.insert((double)x + (double)i * 1e-6);
      // printf("%lf\n", (double)x + (double)i * 1e-6);
    } else if (opt == 2) {
      bbt.erase(bbt.lower_bound(x));
    } else if (opt == 3) {
      printf("%d\n", (int)round(bbt.order_of_key(x)) + 1);
    } else if (opt == 4) {
      printf("%d\n", (int)round(*bbt.find_by_order(x - 1)));
    } else if (opt == 5) {
      printf("%d\n", (int)round(*--bbt.lower_bound(x)));
    } else if (opt == 6) {
      printf("%d\n", (int)round(*bbt.lower_bound((x + 1))));
    }
  }

  return 0;
}
