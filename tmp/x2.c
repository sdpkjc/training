double foo;

double f() {
  foo = 1.5;

  printf("g foo = %p size = %d\n", &foo, sizeof(foo));
  return foo;
}