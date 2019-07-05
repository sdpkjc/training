#include <assert.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> va;
  va.push_back(1);
  va.push_back(2);
  va.push_back(3);
  va.push_back(4);
  va.push_back(5);

  int* p[10];
  for (int i = 0; i < 5; i++) {
    p[i] = (int*)&va[i];
  }

  for (int i = 0; i < 5; i++) {
    cout << p[i] << " " << *p[i] << endl;
  }
  cout << endl;
  va.erase(va.begin());
  for (int i = 0; i < 5; i++) {
    cout << p[i] << " " << *p[i] << endl;
  }

  return 0;
}