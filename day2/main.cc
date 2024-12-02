/**
 * @file main.cc
 * @author Jose Fenic Peiteado Padilla (alu0101227023@ull.edu.es)
 * @brief The solution for advent of code 2024 day 1
 * @version 0.1
 * @date 2024-11-30
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <bits/stdc++.h>

#include "utils.cc"

bool isSafe(std::vector<long> elements) {
  long prev = elements[0];
  long next = elements[1];
  bool is_increasing = true;
  // second part add a variable removing for
  // allow a tolerate a single bad level 
  bool removing = false;
  if (prev > next) {
    is_increasing = false;
  } else {
    is_increasing = true;
  }
  int diference = abs(prev - next);
  if (diference > 3 || diference == 0) {
    removing = true;
  }
  prev = next;
  for (long i = 2; i < elements.size(); i++) {
    next = elements[i];
    if (prev > next && is_increasing == true) {
      if (removing) {
        return false;
      }
      removing = true;
    } else if (prev < next && is_increasing == false) {
      if (removing) {
        return false;
      }
      removing = true;
    }
    int diference = abs(prev - next);
    if (diference > 3 || diference == 0) {
      if (removing) {
        return false;
      }
      removing = true;
    }
    prev = next;
  }
  return true;
}

int main() {
  // Ejemplo de lectura
  auto input = readInput();
  std::vector<long> actual;
  std::map<int, int> right_list;
  int counts = 0;
  for (auto i : input) {
    auto spli_r = split(reduceSpaces(i), ' ');
    for (auto j : spli_r) {
      actual.push_back(std::stoi(j));
    }
    if (isSafe(actual)) {
      counts++;
    }
    actual.clear();
  }
  // ordenadr salida
  std::cout << counts << "\n";
  // std::cout << result2 << "\n";
  return 0;
}