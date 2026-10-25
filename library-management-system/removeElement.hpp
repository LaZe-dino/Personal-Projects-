#ifndef REMOVE_ELEMENT_HPP
#define REMOVE_ELEMENT_HPP

#include <algorithm>
#include <vector>

template <typename T>
void removeElement(std::vector<T>& vec, const T& element) {
  vec.erase(std::remove(vec.begin(), vec.end(), element), vec.end());
}

#endif
