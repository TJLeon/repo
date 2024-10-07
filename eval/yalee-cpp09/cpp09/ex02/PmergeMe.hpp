#pragma once

#include <list>
#include <deque>
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

using std::vector;
using std::string;
using std::deque;
using std::cout;
using std::endl;
using std::list;

template <typename Container>
bool is_sorted(const Container& container) {
  if (container.size() <= 1) {
    return true;
  }
  for (typename Container::size_type i = 0; i < container.size() - 1; ++i) {
    if (container[i] > container[i + 1]) {
      return false; 
    }
  }
  return true;
}

class PmergeMe {
private:
    deque<int> deq;
    deque<int> deqBuffer;
    vector<int> vctr;
    vector<int> vctrBuffer;
    int extraNum;
public:
    PmergeMe();
    PmergeMe(const string argv);
    ~PmergeMe();

    void mergeDeque();
    void mergeVector();
};