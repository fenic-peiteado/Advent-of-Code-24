/**
 * @file main.cc
 * @author Jose Fenic Peiteado Padilla (alu0101227023@ull.edu.es)
 * @brief The solution for advent of code 2024 day 6
 * @version 0.1
 * @date 2024-11-30
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "utils.cc"

int main() {
  // Example of reading
  auto input = readInput();
  int pos_i, pos_j;
  vi dir_i = {-1, 0, 1, 0};
  vi dir_j = {0, 1, 0, -1};
  enum direction { UP, RIGHT, DOWN, LEFT };
  direction dir = UP;
  for (auto i = 0; i < input.size(); i++) {
    for (auto j = 0; j < input[i].size(); j++) {
      if (input[i][j] == '^') {
        pos_i = i;
        pos_j = j;
      }
    }
  }
  long count = 1;
  long count2 = 0;
  bool posible = false;
  int back_i = -1, back_j = -1;
  direction back_dir;
  std::map<std::string, bool> point_in_solution;
  std::string name;
  while (true) {
    for (auto i = 0; i < input.size(); i++) {
      for (auto j = 0; j < input[i].size(); j++) {
        std::cout << input[i][j];
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
    int next_i = pos_i + dir_i[dir];
    int next_j = pos_j + dir_j[dir];
    if (next_i < 0 || next_i >= input.size() || next_j < 0 ||
        next_j >= input[0].size()) {
      if (posible == true) {
        posible = false;
        name = std::to_string(back_i) + std::to_string(back_j) +
               std::to_string(static_cast<int>(back_dir));
        point_in_solution[name] = true;
        pos_i = back_i;
        pos_j = back_j;
        dir = back_dir;
        input[pos_i][pos_j] = '.';
        continue;
      }
      break;
    }
    if (pos_i == back_i && pos_j == back_j) {
      posible = false;
      pos_i = back_i;
      pos_j = back_j;
      dir = back_dir;
      back_i = -1;
      back_j = -1;
      input[pos_i][pos_j] = '.';
      std::cout << 
      count2++;
      continue;
    }
    if (input[next_i][next_j] == '#') {
      dir = (direction)((dir + 1) % 4);
      continue;
    } else if (input[next_i][next_j] == '.') {
      // count++;
      input[next_i][next_j] = '-';
    }
    // suponer punto y buscar con el giro si se encuentra suponemos un giro
    if (posible == false) {
      name = std::to_string(next_i) + std::to_string(next_j) +
             std::to_string(static_cast<int>(dir));
      if (point_in_solution.find(name) != point_in_solution.end()) {
        // si lo encuentra sigue
        pos_i = next_i;
        pos_j = next_j;
      } else {
        back_i = next_i;
        back_j = next_j;
        back_dir = dir;
        dir = (direction)((dir + 1) % 4);
        posible = true;
        input[next_i][next_j] = 'O';
      }
    } else {
      pos_i = next_i;
      pos_j = next_j;
    }
  }
  std::cout << count << std::endl;
  std::cout << count2 << std::endl;

  return 0;
}
