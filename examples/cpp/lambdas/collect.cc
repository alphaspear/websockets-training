#include <iostream>
#include <vector>

using namespace std;

vector<int> collect(vector<int> in, int (*op) (int)) {
  vector<int> out = {};

  for (auto& el : in) {
    out.push_back(op(el));
  }

  return out;
}

int main()   {
  vector<int> primes = {1, 2, 3, 5, 7, 11};

  int scaleBy = 2;

  // vector<int> doubled = collect(primes, [scaleBy](int i) {
  vector<int> doubled = collect(primes, [](int i) {
    return i * 2;
  });

  for (const int& el: doubled) {
  // for (auto& el: doubled) {
    cout << el << " ";
  }

  cout << endl;
}