# algorithms-cpp

![CI](https://github.com/nickworkcs-rgb/algorithms-cpp/actions/workflows/ci.yml/badge.svg)

Основные алгоритмы и структуры данных на C++23 с тестами (GoogleTest).

## Сборка и запуск тестов

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build --output-on-failure
```

## Алгоритмы

| Алгоритм | Время | Память | Код | Тесты |
|----------|-------|--------|-----|-------|
| Бинарный поиск | O(log n) | O(1) | [binary_search.hpp](algorithms/searching/binary_search.hpp) | [binary_search_test.cpp](tests/searching/binary_search_test.cpp) |
| Пузырьковая сортировка | O(n^2) | O(1) | [bubble_sort.hpp](algorithms/sorting/bubble_sort.hpp) | [bubble_sort_test.cpp](tests/sorting/bubble_sort_test.cpp) |
## Структура

- `algorithms/` — реализации (header-only шаблоны)
- `tests/` — тесты GoogleTest
