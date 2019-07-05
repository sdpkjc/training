#include <stdio.h>

int foo;
double f();
double g() {
  foo = 2.5;
  printf("g foo = %p size = %d\n", &foo, sizeof(foo));
  return foo;
}
int main() {
  printf("%d\n", sizeof(foo));
  printf("%lf\n", g());
  printf("%lf\n", foo);
  printf("%lf\n", f());
  return 0;
}