#include<iostream>

using namespace std;

int main() {
  // int p[5]; // Initialize only with [] notation
  // int p[5] = {1, 2, 3, 5, 7};
  // int p[5] = {0};

  int p[] = {1, 2, 3, 5, 7};

  // p = {1, 2, 3, 5, 7}; // - Doesn't work!

  cout << sizeof(p)/sizeof(p[0]) << "\n";

  for (auto el : p) {
    cout << "\t" << el << "\n";
  }

  // Dynamic arrays?

  // int *p1;

  // p1 = malloc(sizeof(int(0)) * 10);

  // for (auto el : p1) {
  //   cout << "\t" << el << "\n";
  // }

  // p = malloc()
}
