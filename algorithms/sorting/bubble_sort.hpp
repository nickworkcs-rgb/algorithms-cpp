#pragma once

#include <cstddef>
#include <utility>
#include <vector>

namespace algo {

// Пузырьковая сортировка (по возрастанию, на месте).
// Идея: сравниваем соседей и меняем местами, если они стоят неправильно;
//       после каждого прохода максимум "всплывает" в конец.
// Время: O(n^2), O(n) если массив уже отсортирован. Память: O(1).
// Устойчивая.

template <typename T>
void bubble_sort(std::vector<T>& data) {
    const std::size_t len = data.size();
    bool swapped = true;

    for (std::size_t i = 0; i < len && swapped; ++i) {
        swapped = false;
        for (std::size_t j = 0; j + 1 < len - i; ++j) {
            if (data[j + 1] < data[j]) {
                std::swap(data[j], data[j + 1]);
                swapped = true;
            }
        }
    }
}

}  // namespace algo
