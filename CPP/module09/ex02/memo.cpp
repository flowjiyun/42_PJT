#include <iostream>
#include <vector>

class MyCompare {
public:
  bool operator()(const int& a, const int& b) const {
    // 비교 연산 구현
    return a < b;
  }
};

int main() {
  std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
  std::sort(vec.begin(), vec.end(), MyCompare());
  for (int i : vec) {
    std::cout << i << " ";
  }
  return 0;
}
