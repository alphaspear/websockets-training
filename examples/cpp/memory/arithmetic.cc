#include <iostream>
#include <stdio.h>

using namespace std;

// void printArr(int p[]) {
//   for (auto el : p) {
//     cout << el << "\n";
//   }
// }

const int MAX = 3;
void printArrUsingPtr(int *ptr) {
   int i;
   for ( i = 0; i < MAX; i++) {
      printf("Address of var[%d] = %p\n", i, ptr );
      printf("Value of var[%d] = %d\n", i, *ptr );

      /* move to the next location */
      ptr++;
   }
}

int main() {
  int var[] = {10, 100, 200}; // Must be on the Heap! - How to prove?!

  printArrUsingPtr(var);

  // int i, *ptr;
  /* let us have array address in pointer */
  //  ptr = var;

  //  for ( i = 0; i < MAX; i++) {
  //     printf("Address of var[%d] = %p\n", i, ptr );
  //     printf("Value of var[%d] = %d\n", i, *ptr );

  //     /* move to the next location */
  //     ptr++;
  //  }

  return 0;
}
