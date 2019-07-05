#include <iostream>
using namespace std;

class A {
 public:
  int a;

  A() { a = 2; };
  virtual void fa() {}
};

class B {
 public:
  int b;
  B() { b = 3; };
  virtual void fb() {}
};

class C : public A, public B {
 public:
  int c;
  C() { c = 4; };
  virtual void fc() {}
};
int main() {
  cout << sizeof(A) << endl;
  cout << sizeof(B) << endl;
  cout << sizeof(C) << endl;
  A ax;
  B bx;

  C tmp;
  long long *pa = (long long *)&ax;
  long long *pb = (long long *)&bx;

  printf("%lld\n", *pa);
  printf("%lld\n", *pb);

  int *p = (int *)&tmp;

  for (int i = 0; i < 32 / 4; i++) {
    printf("%d\n", *(p + i));
  }
  long long *lp = (long long *)&tmp;
  for (int i = 0; i < 32 / 8; i++) {
    printf("%lld\n", *(lp + i));
  }
  return 0;
}