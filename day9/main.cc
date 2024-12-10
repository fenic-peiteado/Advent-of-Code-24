/**
 * @file main.cc
 * @author Jose Fenic Peiteado Padilla (alu0101227023@ull.edu.es)
 * @brief The solution for advent of code 2024 day 8
 * @version 0.1
 * @date 2024-11-30
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "main.h"

#include "utils.cc"

int last_digit(int first_i, int last_i, vs &disk_map) {
  for (last_i; last_i > 0; last_i--) {
    if (disk_map[last_i] != "." && disk_map[last_i] != "x") {
      return last_i;
    }
  }
  return -1;
}

void move_space(int &last_digit_i, vs &disk_map) {
  last_digit_i = disk_map.size() - 1;
  for (int i = 0; i < disk_map.size(); i++) {
    if (i == last_digit_i) {
      break;
    }
    if (disk_map[i] == ".") {
      int find_number = last_digit(i, last_digit_i, disk_map);
      if (find_number != -1) {
        disk_map[i] = disk_map[find_number];
        disk_map[find_number] = "x";
        last_digit_i = find_number;
      } else {
      }
    }
  }
}


// Segunda parte buscar La secuencia de ultimo elementos y buscar la posicion más a la izquierda para meterlo
//  hace fallta una map con punto y huecos
// y solo haria falta los hueco que esten a la izquierda de estos.
int find_space(int &last_digit_i, vs &disk_map) {
  // Se recorre la ID de más alto a menor y con su capacidad
  // y se busca los hueco que este a la izquierda y sea menor y se asigna con un bucle con el ID y se elimina
  return -1;
}

unsigned long long int get_number(vs disk_map) {
  unsigned long long int result = 0;
  int pos_mul = 0;
  for (int i = 0; i < disk_map.size(); i++) {
    if (disk_map[i] == "." || disk_map[i] == "x") {
    } else {
      long long digit = std::stoll(disk_map[i]);
      unsigned long long value = (digit * pos_mul);
      result += value;
      pos_mul++;
    }
  }
  return result;
}

int main() {
  // Example of reading
  auto input = readInput();
  std::string line = input[0];
  vs disk_map;
  int limit = 0;
  int last_digit_i = 0;
  int count = 0;
  for (int i = 0; i < line.size(); i++) {
    if (i % 2 == 0) {  // block file
      limit = line[i] - '0';
      last_digit_i = i;
      for (int j = 0; j < limit; j++) {
        std::string aux = std::to_string(count);
        disk_map.push_back(aux);
      }
      count++;
    } else {  // free space
    // Mete un contador de espacio y almacenar el size.
      limit = line[i] - '0';
      for (int j = 0; j < limit; j++) {
        std::string aux = ".";
        disk_map.push_back(aux);
      }
    }
  }
  // move_space(last_digit_i, disk_map); first
  unsigned long long int result = get_number(disk_map);
  for (auto i : disk_map) {
    std::cout << i << " ";
  }
  std::cout << "\n" << result << std::endl;
  unsigned long long max_value = ULLONG_MAX;
  std::cout << max_value;
  return 0;
}