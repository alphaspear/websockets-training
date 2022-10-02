#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
void ForEach (const std::vector<int>& values, const std::function<void(int)>& func)
{
    for (int value: values)
        func(value);
}

int main()
{
    std::vector<int> values = { 1, 9, 4, 2, 3 };
    auto it = std::find_if(values.begin(), values.end(), [](int value) { return value > 4; });
    std::cout << *it << std::endl;
    int a=5;
    auto lambda = [=](int value) { std::cout << "Value : " << a << std::endl; };
    ForEach(values, lambda);
}