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

int  main() {
  // Example of reading
  auto input = readInput();
  vvs list_e;
  for (auto i : input) {
    list_e.push_back(split(i, ':'));
  }
  matriz number_sequence;
  vi aux;
  for (auto list_simple : list_e) {
    std::cout << list_simple[0] << std::endl;
    aux.push_back(stoll(list_simple[0]));
    auto correction = split(
        stripSpace(join_s(vs(list_simple.begin() + 1, list_simple.end()))),
        ' ');
    for (long long i = 0; i < correction.size(); i++) {
      aux.push_back(stoll(correction[i]));
    }
    number_sequence.push_back(aux);
    aux.clear();
  }
  // using a mask bits for the solution
  long long mask = 0;
  long long result_final = 0;
  // make all combinations of the numbers
  for (long long i = 0; i < number_sequence.size(); i++) {
    long long number_to_find = number_sequence[i][0];
    long long limit =number_sequence[i].size() - 1 - 1;  // first number is objetive and operator between numbers take 2
    limit = pow(2, limit);
    long long elements = number_sequence[i].size() - 1;
    for (long long k = 0; k < limit; k++) {
      mask = k;
      long long result = number_sequence[i][1];
      std::bitset<32> mask_bits(mask);
      
      for (long long l = 0 ; l < elements-1 ; l++) {
        if (mask_bits[l] == 0) {
          result += number_sequence[i][l+2]; // se accede al numero menos significativo se empieza en 32 y descontando 
        } else {
          result *= number_sequence[i][l+2];
        }
        // std::cout << result << std::endl;
      }
      if (result == number_to_find) {
        result_final += result;
        break;
      }
    }
  }
  std::cout << result_final << std::endl;

  return 0;
}