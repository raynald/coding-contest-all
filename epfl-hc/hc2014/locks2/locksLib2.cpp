/////////////////////////////
// DO NOT SUBMIT THIS FILE //
/////////////////////////////

#include <cassert>
#include <cstdio>
#include <cstring>
#include <string>
#include "locksLib2.hpp"

namespace {

class test_data {
 public:
  test_data(const std::string &test_arg) : number_of_calls(0), test(test_arg) {}
  
  int get_number_of_calls() const {
    return number_of_calls;
  }
  
  size_t size() const {
    return test.size();
  }
  
 private:
  long long number_of_calls;
  std::string test;
  friend bool ::login(const std::vector<int> &);
  friend bool matches(const std::vector<int> &);
};

test_data t("");

bool matches(const std::vector<int> &combination) {
  if (combination.size() != t.size()) return false;
  for (size_t i = 0; i < combination.size(); ++i) {
    if (combination[i] != (t.test[i] - '0')) {
      return false;
    }
  }
  return true;
}

}  // unnamed namespace.

bool login(const std::vector<int> &combination) {
  bool result = false;
  ++t.number_of_calls;
  assert(combination.size() == t.size());
  for (size_t i = 0; i < combination.size(); ++i) {
    assert(-1 <= combination[i] && combination[i] <= 9);
    if (combination[i] == (t.test[i] - '0')) {
      result = true;
    }
  }
  return result;
}

int main() {
  char combination[128];
  int tests = 0;
  assert(std::scanf("%d", &tests) == 1);
  while (tests-- > 0) {
    assert(std::scanf("%s", combination) == 1);
    t = test_data(combination);
    memset(combination, 0, sizeof(combination));
    std::vector<int> solution = crack_combination_lock(t.size());
    if (t.get_number_of_calls() <= 500 && matches(solution)) {
      std::printf("PASS\n");
    } else {
        std::printf("%d\n",t.get_number_of_calls());
      std::printf("FAIL\n");
    }
  }

  return 0;
}
