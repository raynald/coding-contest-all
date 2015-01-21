/////////////////////////////
// DO NOT SUBMIT THIS FILE //
/////////////////////////////

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include "locksLib3.hpp"

#define CALL_LIMIT 200

template<int pad1, int pad2, int pad3>
class test_data_padded {
 public:
  test_data_padded(int N_arg, const std::string &test_arg)
      : number_of_calls(0), N(N_arg), test(test_arg) {
  }
  
  int get_number_of_calls() {
    return number_of_calls;
  }
  
  int get_D() {
    return test.size();
  }
  
 private:
  // Eliminate any pointer manipulation magic from accessing internals.
  int padding1[pad1];
  int number_of_calls;
  int padding2[pad2];
  int N;
  int padding3[pad3];
  std::string test;
  friend bool ::is_loose(const std::vector<int> &);
  friend bool ::matches(const std::vector<int> &);
};

typedef test_data_padded<12, 3, 4> test_data;
test_data t_(0, "");

bool is_loose(const std::vector<int> &combination) {
  ++t_.number_of_calls;
  t_.number_of_calls = std::min(t_.number_of_calls, 1000000000);
  if (combination.size() != t_.test.size()) return false;
  int ans = 0;
  for (int i = 0; i < combination.size(); ++i) {
    if (combination[i] == (t_.test[i] - '0')) {
      return true;
    }
  }
  return false;
}

bool matches(const std::vector<int> &combination) {
  if (combination.size() != t_.test.size()) return false;
  for (int i = 0; i < combination.size(); ++i) {
    if (combination[i] != (t_.test[i] - '0')) {
      return false;
    }
  }
  return true;
}

int main() {
    int N;
    char combination[81];
    
    int worst = 0;

    while (std::scanf("%s", combination) == 1) {
      t_ = test_data(81, combination);
      memset(combination, 0, sizeof(combination));
      std::vector<int> solution = crack_password();
      if (t_.get_number_of_calls() <= CALL_LIMIT && matches(solution)) {
        worst = std::max(worst, t_.get_number_of_calls());
        std::printf("Correct\n");
      } else {
          std::printf("%d", t_.get_number_of_calls());
        std::printf("Wrong\n");
      }
    }
    std::cerr << worst << std::endl;

    return 0;
}
