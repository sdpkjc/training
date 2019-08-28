#include <memory.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
using namespace std;

int main() {
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  do {
    int arrb[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    do {
      cout << 5 << endl;
      for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
      }
      cout << endl;
      for (int i = 0; i < 5; i++) {
        cout << arrb[i] << " ";
      }
      cout << endl;
    } while (next_permutation(arrb, arrb + 5));
  } while (next_permutation(arr, arr + 5));
  return 0;
}