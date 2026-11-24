#pragma once

#include <vector>

namespace algo {

template <typename T>
int binary_search(const std::vector<T> &data, const T &target) {

  int left = 0;
  int right = static_cast<int>(data.size()) - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (data[mid] == target)
      return mid;
    if (data[mid] < target)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return -1;
}

} // namespace algo
