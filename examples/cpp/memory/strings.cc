#include<iostream>
#include<stdio.h>

using namespace std;

int main() {
  char s[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
  // string s = {'h', 'e', 'l', 'l', 'o'};

  cout << strlen(s) << "\n";

  // cout << s << "\n"; // TODO: Figure out why garbage end characters?!

  cin >> s; // TODO: HOW!? Heap!? How is it free-ed!?
  // scanf("%s", s); // TODO: HOW!?

  cout << "Input read:" << s << "\n";

  cout << strlen(s) << "\n";

  return 0;
}
