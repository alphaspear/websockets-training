#include <functional>
#include <iostream>

using namespace std;

const function<int(int)> summer() {
  int sum = 0; // When does this get deallocated? >> when calling function exits; ;
    cout<<"sum at init= "<<sum<<endl;
  return [sum](int x) mutable -> int { // x = 20 | sum = 11
    sum = sum + x;
    cout<<"sum before return= "<<sum<<endl;
    return sum;
    
  };
}

//runtime > it creates an temporary function object which is stored in stack;

void test()
{
    auto sum1 = summer(); // Type: ?
    auto sum2 = summer(); // Type: ?

    cout << sum1(11) << "\n"; // Value: ? | Line: ?
    cout << sum1(20) << "\n";
}

int main() {
  test();
  auto sum1 = summer(); // Type: ?
  auto sum2 = summer(); // Type: ?
  cout << sum1(11) << "\n"; // Value: ? | Line: ?
  cout << sum1(20) << "\n"; // Value: ? | Line: ?

  // cout << sum1(30) << "\n"; // Value: ?

  // cout << sum2(12) << "\n"; // Value: ?
  // cout << sum2(20) << "\n"; // Value: ?
  // cout << sum2(30) << "\n"; // Value: ?

  return 0;
}